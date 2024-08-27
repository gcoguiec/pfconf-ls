use std::{
    collections::HashMap,
    fs::read_to_string,
    path::{Path, PathBuf},
    process::Output
};

use duct::cmd;
use glob::glob;
use miette::Diagnostic;
use serde::Deserialize;
use std::io::Error as IoError;
use thiserror::Error;
use toml::de::Error as TomlDeserializingError;

use xtask_utils::fetch_env_or_else;

#[derive(Debug, Error, Diagnostic)]
pub enum CargoManifestError {
    #[error("Failed to open cargo manifest for {filepath}. {err}")]
    #[diagnostic(code(xtask::cargo::manifest::file_error))]
    File { err: IoError, filepath: PathBuf },

    #[error("Unsufficient permissions when trying to read cargo manifest.")]
    #[diagnostic(
        code(xtask::cargo::manifest::unsufficient_permission_error),
        help(
            "Maybe the user you are executing xtask with does not have read \
             permission on the manifest file?"
        )
    )]
    UnsufficientPermission,

    #[error("Failed to parse file '{filepath}' as TOML. {err}")]
    #[diagnostic(code(xtask::cargo::manifest::parsing_failed_error))]
    ParsingFailed {
        err: TomlDeserializingError,
        filepath: PathBuf
    }
}

#[derive(Debug, Deserialize, Clone)]
#[serde(rename_all = "kebab-case")]
pub struct WasiReleaseEntry {
    pub url: String,
    pub sha512: String
}

#[derive(Debug, Default, Deserialize)]
#[serde(rename_all = "kebab-case")]
pub struct PackageMetadata {
    pub wasi_sdk: Option<HashMap<String, WasiReleaseEntry>>
}

#[derive(Debug, Deserialize)]
#[serde(rename_all = "kebab-case")]
pub struct CargoManifestPackage {
    pub name: String,
    pub metadata: Option<PackageMetadata>
}

#[derive(Debug, Default, Deserialize)]
#[serde(rename_all = "kebab-case")]
pub struct CargoManifest {
    pub package: Option<CargoManifestPackage>
}

impl CargoManifest {
    pub fn from_path(manifest_path: &Path) -> Result<Self, CargoManifestError> {
        let manifest_content = match read_to_string(manifest_path) {
            Ok(content) => content,
            Err(err) => {
                return Err(CargoManifestError::File {
                    err,
                    filepath: manifest_path.to_path_buf()
                })
            }
        };

        match toml::from_str(&manifest_content) {
            Ok(toml) => Ok(toml),
            Err(err) => Err(CargoManifestError::ParsingFailed {
                err,
                filepath: manifest_path.to_path_buf()
            })
        }
    }
}

#[derive(Debug, Error, Diagnostic)]
pub enum CargoError {
    #[error("Failed to execute `cargo` command. {err}")]
    #[diagnostic(code(xtask::cargo::execution_failed_error))]
    ExecutionFailed { err: IoError },

    #[error("An error occurred when handling '{filepath}' manifest. {err}")]
    #[diagnostic(code(xtask::cargo::manifest_error))]
    Manifest {
        err: Box<CargoManifestError>,
        filepath: PathBuf
    }
}

/// Executes cargo with provided arguments.
pub fn cargo_execute(args: Vec<&str>) -> Result<Output, CargoError> {
    match cmd(
        fetch_env_or_else("CARGO_PATH", |_| {
            match cmd!("which", "cargo").read() {
                Ok(stdout) => stdout.trim().to_string(),
                Err(_) => String::from("cargo")
            }
        }),
        args
    )
    .run()
    {
        Ok(output) => Ok(output),
        Err(err) => Err(CargoError::ExecutionFailed { err })
    }
}

/// Returns detected crate list at provided root.
pub fn cargo_crates_for_root(root: &Path) -> Result<Vec<String>, CargoError> {
    glob(root.join("*/cargo.toml")
        .to_str()
        .expect("Expected crates root to be a valid UTF-8 string.")) // We panic because this is likely a developer error.
        .expect("Invalid glob pattern used as root.") // Same panic remark as above.
        .map(|matched_file| {
            let filepath = match matched_file {
                Ok(filepath) => filepath,
                Err(err) => {
                    return Err(CargoError::Manifest {
                        err: Box::new(CargoManifestError::UnsufficientPermission),
                        filepath: err.path().to_path_buf()
                    })
                }
            };
            match CargoManifest::from_path(&filepath) {
                Ok(manifest) => Ok(manifest
                    .package
                    .expect("Package definition should provide a name.") // Cargo is checking this for us first. Should not happen.
                    .name),
                Err(err) => Err(CargoError::Manifest {
                    err: Box::new(err),
                    filepath
                })
            }
        })
        .collect::<Result<Vec<String>, CargoError>>()
}
