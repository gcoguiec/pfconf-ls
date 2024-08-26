use std::{
    cell::OnceCell,
    fs::{File, OpenOptions},
    io::{self, Error as IoError, Write},
    path::PathBuf
};

use flate2::read::GzDecoder;
use hex::FromHexError;
use miette::{Diagnostic, Result};
use reqwest::Error as ReqwestError;
use sha2::{Digest, Sha512};
use tar::Archive;
use thiserror::Error;
use tracing::{debug, info, trace, warn};

use xtask_cargo::{CargoManifest, CargoManifestError, WasiReleaseEntry};
use xtask_utils::{
    create_directory_path,
    fetch_env_or,
    from_workspace_root,
    get_target_double,
    TargetDouble
};

#[derive(Debug, Error, Diagnostic)]
pub enum WasiSdkError {
    #[error(
        "Failed to create or modify wasi-sdk directory at {filepath}. {err}"
    )]
    #[diagnostic(
        code(xtask::wasi::sdk::directory_error),
        help("Do you have permissions to create or modify the directory?")
    )]
    Directory { err: IoError, filepath: PathBuf },

    #[error(
        "Building for the wasm32-wasi target is not supported on a {0} system."
    )]
    #[diagnostic(
        code(xtask::wasi::sdk::unsupported_system_error),
        help(
            "Only Windows (x86_64), Linux (x86_64,arm64) and MacOS \
             (x86_64,arm64) are supported."
        )
    )]
    UnsupportedSystem(String),

    #[error(
        "An error occurred when trying to read `xtask-wasi` cargo manifest: \
         {0}"
    )]
    #[diagnostic(code(xtask::wasi::sdk::manifest_error))]
    Manifest(CargoManifestError)
}

#[derive(Debug, Error, Diagnostic)]
pub enum WasiSdkDownloadError {
    #[error(
        "Failed to create of modify wasi-sdk tarball file at '{filepath}'. \
         {err}"
    )]
    #[diagnostic(
        code(xtask::wasi::sdk::download::file_error),
        help("Do you have permissions to create or modify this file?")
    )]
    File { err: IoError, filepath: PathBuf },

    #[error("An error occurred when downloading wasi-sdk release. {0}")]
    #[diagnostic(code(xtask::wasi::sdk::download::request_error))]
    Request(ReqwestError),

    #[error("An error occurred when writing content to tarball file. {0}")]
    #[diagnostic(code(xtask::wasi::sdk::download::copy_error))]
    Copy(ReqwestError),

    #[error(
        "Invalid release SHA512 signature. Expected '{expected}' got \
         '{actual}'."
    )]
    SignatureMismatch {
        expected: String,
        actual: String,
        filepath: PathBuf
    },

    #[error(
        "Updating the hasher failed. Couldn't build release signature. {0}"
    )]
    #[diagnostic(code(xtask::wasi::sdk::download::hasher_update_error))]
    HasherUpdate(IoError),

    #[error("Failed to decode hasher's finalized output as raw bytes. {0}")]
    #[diagnostic(code(xtask::wasi::sdk::download::signature_decoding_error))]
    SignatureDecoding(FromHexError)
}

#[derive(Debug, Error, Diagnostic)]
pub enum WasiSdkExtractError {
    #[error("Failed to open wasi-sdk tarball file at '{filepath}'. {err}")]
    #[diagnostic(
        code(xtask::wasi::sdk::extract::file_error),
        help("Do you have permissions to read this file?")
    )]
    File { err: IoError, filepath: PathBuf },

    #[error("An error occurred when trying to access archive content. {0}")]
    #[diagnostic(code(xtask::wasi::sdk::extract::archive_error))]
    Archive(IoError),

    #[error("An error occurred when trying to unpack archive item. {0}")]
    #[diagnostic(code(xtask::wasi::sdk::extract::unpack_error))]
    Unpack(IoError)
}

/// Holds environment variables for a wasi-sdk installation.
#[derive(Debug)]
pub struct WasiSdkEnv {
    strict: bool,
    target_dir_path: PathBuf,
    parent_dir_path: PathBuf,
    target_double: TargetDouble,
    manifest_path: OnceCell<PathBuf>,
    release_tarball_path: OnceCell<PathBuf>,
    version_file_path: OnceCell<PathBuf>
}

impl WasiSdkEnv {
    /// Creates a new wasi-sdk environment initialized from local environment
    /// variables (or default values).
    ///
    /// # Environment Variables
    ///
    /// - `XTASK_WASI_STRICT`: See Strict Mode section.
    /// - `XTASK_WASI_MANIFEST_PATH`: Change cargo manifest path where all releases are declared.
    /// - `XTASK_WASI_SDK_TARGET_DIR`: Set a specific target directory path.
    /// - `XTASK_WASI_SDK_TARBALL_FILENAME`: Rename tarball release file name.
    /// - `XTASK_WASI_SDK_VERSION_FILENAME`: Rename release file name.
    ///
    /// # Strict Mode
    ///
    /// Enabling `strict` option (via `XTASK_WASI_STRICT=true`) will:
    /// - Lock `XTASK_WASI_MANIFEST_PATH` variable to prevent the ability to change the manifest path and, therefore, SDK release URLs and signatures.
    ///
    /// # Panics
    ///
    /// This function will panic if target directory doesn't have a parent directory.
    pub fn from_local_env() -> Self {
        let target_dir_path = from_workspace_root(PathBuf::from(fetch_env_or(
            "WASI_SDK_TARGET_DIR",
            "lib/wasi-sdk"
        )));
        // Q: Why requiring a parent folder?
        // A: I would love to give you a logical explanation for this, but
        // truthfully, it's just an aesthetic decision about how SDK files should
        // be organised.
        let parent_dir_path = target_dir_path
            .parent()
            // Very early in the initialization process, we can reasonnably
            // allow a panic here.
            .expect(
                "The target directory does not have a parent directory \
                 necessary for the SDK install process. Help: Are you running \
                 xtask at the filesystem root?"
            )
            .to_path_buf();

        Self {
            strict: matches!(
                fetch_env_or("WASI_SDK_STRICT", "false")
                    .to_lowercase()
                    .as_str(),
                "true" | "1"
            ),
            target_dir_path,
            parent_dir_path,
            target_double: get_target_double(),
            manifest_path: OnceCell::new(),
            release_tarball_path: OnceCell::new(),
            version_file_path: OnceCell::new()
        }
    }

    /// Returns wasi-sdk target directory path.
    pub fn get_target_dir_path(&self) -> &PathBuf {
        &self.target_dir_path
    }

    /// Returns wasi-sdk target directory parent path.
    pub fn get_parent_dir_path(&self) -> &PathBuf {
        &self.parent_dir_path
    }

    /// Returns cargo manifest path where wasi-sdk releases are declared.
    pub fn get_manifest_path(&self) -> &PathBuf {
        self.manifest_path.get_or_init(|| {
            let default_relative_path = "build/xtask-wasi/cargo.toml";
            from_workspace_root(if self.strict {
                PathBuf::from(default_relative_path)
            } else {
                PathBuf::from(fetch_env_or(
                    "WASI_MANIFEST_PATH",
                    default_relative_path
                ))
            })
        })
    }

    /// Returns wasi-sdk release tarball path.
    ///
    /// # Panics
    ///
    /// This function will panic if file name provided via
    /// `WASI_SDK_TARBALL_FILENAME` environment variable is invalid.
    pub fn get_release_tarball_path(&self) -> &PathBuf {
        self.release_tarball_path.get_or_init(|| {
            let relative_path = PathBuf::from(fetch_env_or(
                "WASI_SDK_TARBALL_FILENAME",
                "wasi-sdk.tar.gz"
            ));
            self.parent_dir_path.join(
                relative_path
                    .file_name()
                    .expect("Invalid release tarball file name.")
            )
        })
    }

    /// Returns wasi-sdk version file name.
    ///
    /// # Panics
    ///
    /// This function will panic if version file name provided via
    /// `WASI_SDK_VERSION_FILENAME` environment variable is invalid.
    pub fn get_version_file_path(&self) -> &PathBuf {
        self.version_file_path.get_or_init(|| {
            let relative_path = PathBuf::from(fetch_env_or(
                "WASI_SDK_VERSION_FILENAME",
                "wasi-sdk.version"
            ));
            self.parent_dir_path.join(
                relative_path
                    .file_name()
                    .expect("Invalid version file name.")
            )
        })
    }

    /// Returns target system arch.
    pub fn get_target_system_arch(&self) -> &str {
        self.target_double.0
    }

    /// Returns target system operating system.
    pub fn get_target_system_os(&self) -> &str {
        self.target_double.1
    }

    /// Checks if SDK is properly extracted and ready to use.
    pub fn is_ready_to_use(&self) -> bool {
        self.target_dir_path.join("bin/clang").exists()
    }

    /// Creates wasi-sdk target directory if it doesn't already exist.
    ///
    /// # Errors
    ///
    /// This function will return an error if directory cannot be created.
    pub fn ensure_target_directory_exists(&self) -> Result<(), WasiSdkError> {
        if self.target_dir_path.exists() {
            return Ok(())
        }
        debug!("Directory to create: {}", self.target_dir_path.display());
        if let Err(err) = create_directory_path(&self.target_dir_path) {
            return Err(WasiSdkError::Directory {
                err,
                filepath: self.target_dir_path.to_path_buf()
            });
        }
        Ok(())
    }
}

/// Returns wasi-sdk release archive url and checksum for a specific target double `(arch,os)`.
///
/// # Errors
///
/// This function will return an error if system is not supported or if cargo
/// manifest cannot be read.
///
/// # Panics
///
/// This function will panic if TOML manifest is missing the metadata.
pub fn get_release_entry_for_env(
    env: &WasiSdkEnv
) -> Result<WasiReleaseEntry, WasiSdkError> {
    let manifest = match CargoManifest::from_path(env.get_manifest_path()) {
        Ok(manifest) => manifest,
        Err(err) => return Err(WasiSdkError::Manifest(err))
    };
    // We allow panics here because this is most likely a project developer error.
    let package = manifest
        .package
        .expect("The `package` section is missing from cargo manifest.");
    let metadata = package.metadata.expect(
        "The `package.metadata` section is missing from cargo manifest."
    );
    let entries = metadata.wasi_sdk.expect(
        "The `package.metadata.wasi-sdk` section is missing from cargo \
         manifest."
    );
    match entries.get(
        format!(
            "{}-{}",
            env.get_target_system_arch(),
            env.get_target_system_os()
        )
        .as_str()
    ) {
        Some(entry) => Ok(entry.to_owned()),
        None => Err(WasiSdkError::UnsupportedSystem(format!(
            "{} ({})",
            env.get_target_system_os(),
            env.get_target_system_arch()
        )))
    }
}

/// Downloads wasi release into a target directory.
///
/// # Errors
///
/// This function will return an error if it cannot write/copy downloaded content
/// into destination file or if the download request failed somehow.
pub fn download_release(
    env: &WasiSdkEnv,
    release_entry: &WasiReleaseEntry
) -> Result<(), WasiSdkDownloadError> {
    if env.get_release_tarball_path().exists() {
        info!("wasi-sdk release archive already exists, skipping download.");
        return Ok(())
    }
    let mut file = match OpenOptions::new()
        .create(true)
        .truncate(true)
        .write(true)
        .open(env.get_release_tarball_path())
    {
        Ok(file) => file,
        Err(err) => {
            return Err(WasiSdkDownloadError::File {
                err,
                filepath: env.get_release_tarball_path().to_path_buf()
            })
        }
    };
    trace!("Url: {}", release_entry.url);
    let mut response = match reqwest::blocking::get(release_entry.url.as_str())
    {
        Ok(response) => response,
        Err(err) => return Err(WasiSdkDownloadError::Request(err))
    };
    response = match response.error_for_status() {
        Ok(response) => response,
        Err(err) => return Err(WasiSdkDownloadError::Request(err))
    };
    if let Err(err) = response.copy_to(&mut file) {
        return Err(WasiSdkDownloadError::Copy(err))
    }
    Ok(())
}

/// Verifies downloaded release signature.
///
/// # Errors
///
/// This function will return an error when signature cannot be decoded properly,
/// when SHA2 hasher can't update its blocks and finally, when there's a mismatch
/// between the two signatures (downloaded v.s. expected).
pub fn verify_release(
    env: &WasiSdkEnv,
    release_entry: &WasiReleaseEntry
) -> Result<(), WasiSdkDownloadError> {
    let mut file = match File::open(env.get_release_tarball_path()) {
        Ok(file) => file,
        Err(err) => {
            return Err(WasiSdkDownloadError::File {
                err,
                filepath: env.get_release_tarball_path().to_path_buf()
            })
        }
    };
    trace!("Expected signature: {}", release_entry.sha512);
    let expected = match hex::decode(&release_entry.sha512) {
        Ok(signature) => signature,
        Err(err) => return Err(WasiSdkDownloadError::SignatureDecoding(err))
    };
    let actual = {
        let mut hasher = Sha512::new();
        if let Err(err) = io::copy(&mut file, &mut hasher) {
            return Err(WasiSdkDownloadError::HasherUpdate(err));
        }
        hasher.finalize()
    };
    if expected != actual.as_slice() {
        return Err(WasiSdkDownloadError::SignatureMismatch {
            expected: hex::encode(expected),
            actual: hex::encode(actual),
            filepath: env.get_release_tarball_path().to_path_buf()
        })
    }
    debug!("'{}' signature is valid.", hex::encode(actual));
    Ok(())
}

/// Extracts the wasi-sdk release file into its target directory and returns
/// a version name if everything went well.
///
/// # Errors
///
/// This function will return an error if archive cannot be opened or if its
/// content cannot be listed.
///
/// # Warnings
///
/// This function will emit warnings if an archive entry path cannot be obtained
/// or if the entry itself cannot be unpacked.
pub fn extract_release(
    env: &WasiSdkEnv
) -> Result<String, WasiSdkExtractError> {
    let file = match File::open(env.get_release_tarball_path()) {
        Ok(file) => file,
        Err(err) => {
            return Err(WasiSdkExtractError::File {
                err,
                filepath: env.get_release_tarball_path().to_path_buf()
            })
        }
    };
    let mut partially_decompressed = false;
    let mut version_name: Option<String> = None;
    let prefix_cell: OnceCell<PathBuf> = OnceCell::new();
    let mut archive = Archive::new(GzDecoder::new(file));
    let entry_results = match archive.entries() {
        Ok(iterator) => iterator,
        Err(err) => return Err(WasiSdkExtractError::Archive(err))
    };
    for entry_result in entry_results {
        let mut entry = match entry_result {
            Ok(entry) => entry,
            Err(err) => {
                partially_decompressed = true;
                warn!("Couldn't process archive entry. {err}");
                continue;
            }
        };
        let path = match entry.path() {
            Ok(path) => path,
            Err(err) => {
                partially_decompressed = true;
                warn!("Couldn't process archive entry path. {err}");
                continue;
            }
        };
        let prefix = prefix_cell.get_or_init(|| {
            let mut ancestors = path.ancestors();
            ancestors
                // Note: single ended iterator, we can't use `nth_back()`.
                .nth(ancestors.count() - 2)
                // We assume there's no root directory otherwise.
                .unwrap_or(&PathBuf::from(""))
                .to_path_buf()
        });
        if version_name.is_none() {
            // The version name is obtained from the archive root directory
            // (not ideal, it works for now).
            version_name = Some(
                format!("{}", prefix.display())
                    .trim_end_matches(std::path::MAIN_SEPARATOR)
                    .to_string()
            );
        }
        let stripped_path = path.strip_prefix(prefix).unwrap_or(&path);
        let absolute_target_path =
            env.get_target_dir_path().join(stripped_path);
        if let Err(err) = entry.unpack(&absolute_target_path) {
            partially_decompressed = true;
            warn!(
                "Failed to unpack '{}' archive entry. {}",
                absolute_target_path.display(),
                WasiSdkExtractError::Unpack(err)
            );
            continue;
        }
        trace!("- {}", absolute_target_path.display());
    }
    if partially_decompressed {
        warn!(
            "At least one file could not be adequately decompressed. Please \
             be advised that this is not expected. You may want to run `xtask \
             wasi update-sdk` as an attempt to fix this issue."
        );
    }
    Ok(version_name.unwrap_or_default())
}

/// Creates a wasi-sdk version file in target directory.
///
/// # Errors
///
/// This function will return an [`io::Error`] if the version file cannot be
/// created or written.
pub fn create_version_file_for_env(
    env: &WasiSdkEnv,
    version_name: &String
) -> Result<(), IoError> {
    let mut version_file = OpenOptions::new()
        .create(true)
        .truncate(true)
        .read(false)
        .write(true)
        .open(env.get_version_file_path())?;
    version_file.write_fmt(format_args!("{version_name}"))?;
    Ok(())
}
