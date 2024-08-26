use std::{
    collections::HashMap,
    fs::File,
    io::BufReader,
    path::{Path, PathBuf},
    process::Output,
    str::{self, Utf8Error}
};

use duct::cmd;
use miette::{Diagnostic, Result};
use regex::Regex;
use semver::{Error as SemverVersion, Version, VersionReq};
use serde::Deserialize;
use serde_json::{Error as SerdeJsonError, Value};
use std::io::Error as IoError;
use thiserror::Error;
use tracing::{debug, error, info, trace};

use xtask_cache::{ToolEntry, TOOLS_CACHE};
use xtask_utils::fetch_env_or;

static PNPM_DEFAULT_BINARY: &str = "pnpm";
static PNPM_FLAG_KEY: &str = "has_pnpm";

static VOLTA_DEFAULT_BINARY: &str = "volta";
static VOLTA_FLAG_KEY: &str = "has_volta";

static VERSION_PATTERN: &str = r"^\d+.\d+.\d+$";

#[derive(Debug, Error, Diagnostic)]
pub enum NodeManifestError {
    #[error(transparent)]
    #[diagnostic(code(xtask::node::manifest::invalid_path_error))]
    InvalidPath(#[from] IoError),

    #[error("Failed to convert manifest content to UTF-8, {0}.")]
    #[diagnostic(code(xtask::node::manifest::content_error))]
    Content(Utf8Error),

    #[error("Failed to parse manifest as JSON, {0}.")]
    #[diagnostic(code(xtask::node::manifest::parsing_failed_error))]
    ParsingFailed(SerdeJsonError)
}

#[derive(Debug, Error, Diagnostic)]
pub enum NodeError {
    #[error("The `pnpm` package manager is not present on this system.")]
    #[diagnostic(code(xtask::node::pnpm_not_present_error))]
    PnpmNotPresent,

    #[error("Failed to execute `pnpm` command '{command}'. {err}")]
    #[diagnostic(code(xtask::node::pnpm_execution_failed_error))]
    PnpmExecutionFailed { err: IoError, command: String },

    #[error("Missing dependency package '{package_name}'.")]
    #[diagnostic(code(xtask::node::missing_dependency_error))]
    MissingDependency { package_name: String },

    #[error(
        "Could not parse '{version}' version for package '{package_name}'. \
         {err}"
    )]
    #[diagnostic(code(xtask::node::unparsable_version_error))]
    UnparsableVersion {
        package_name: String,
        version: String,
        err: SemverVersion
    },

    #[error(
        "Version mismatch for dependency package '{package_name}', version \
         '{expected_version}' expected, '{installed_version}' installed."
    )]
    #[diagnostic(code(xtask::node::mismatched_dependency_version_error))]
    MismatchedDependencyVersion {
        package_name: String,
        expected_version: String,
        installed_version: String
    },

    #[error("An error occurred when handling '{filepath}' manifest. {err}")]
    #[diagnostic(code(xtask::node::manifest_error))]
    Manifest {
        err: Box<NodeManifestError>,
        filepath: PathBuf
    }
}

#[derive(Debug, Deserialize, Clone)]
#[serde(rename_all = "camelCase")]
pub struct PackageJson {
    pub dependencies: Option<HashMap<String, Value>>,
    pub dev_dependencies: Option<HashMap<String, Value>>,
    pub peer_dependencies: Option<HashMap<String, Value>>,
    pub volta: Option<HashMap<String, String>>
}

impl PackageJson {
    pub fn from_path(manifest_path: &Path) -> Result<Self, NodeError> {
        let reader = BufReader::new(match File::open(manifest_path) {
            Ok(file) => file,
            Err(err) => {
                return Err(NodeError::Manifest {
                    err: Box::new(NodeManifestError::InvalidPath(err)),
                    filepath: manifest_path.to_path_buf()
                })
            }
        });
        match serde_json::from_reader(reader) {
            Ok(json) => Ok(json),
            Err(err) => Err(NodeError::Manifest {
                err: Box::new(NodeManifestError::ParsingFailed(err)),
                filepath: manifest_path.to_path_buf()
            })
        }
    }

    pub fn iter(
        &self
    ) -> impl Iterator<Item = &Option<HashMap<String, Value>>> {
        vec![
            &self.dependencies,
            &self.dev_dependencies,
            &self.peer_dependencies,
        ]
        .into_iter()
    }
}

/// Checks if the system has pnpm installed.
pub fn is_pnpm_installed() -> bool {
    let mut cache =
        TOOLS_CACHE.lock().expect("Could not lock the tools cache.");
    if let Some(tool_entry) = cache.get(PNPM_FLAG_KEY) {
        return tool_entry.present;
    }
    // @todo PNPM => PNPM_PATH, remove DEFAULT_BINARY
    let pnpm_path = fetch_env_or("PNPM", PNPM_DEFAULT_BINARY);
    match cmd!(&pnpm_path, "--version").read() {
        Ok(stdout) => {
            trace!("Found `pnpm` version {stdout}.");
            let flag = Regex::new(VERSION_PATTERN)
                .expect("Invalid version regex pattern.")
                .is_match(&stdout);
            cache.put(PNPM_FLAG_KEY, ToolEntry {
                present: true,
                path: Some(PathBuf::from(pnpm_path)),
                version: Some(stdout)
            });
            flag
        }
        Err(err) => {
            debug!("Underlying error: {err}");
            cache.put(PNPM_FLAG_KEY, ToolEntry {
                present: false,
                path: None,
                version: None
            });
            false
        }
    }
}

/// Executes node / pnpm with provided arguments.
pub fn pnpm_execute(args: Vec<&str>) -> Result<Output, NodeError> {
    if !is_pnpm_installed() {
        return Err(NodeError::PnpmNotPresent);
    }
    let command = args.join(" ");
    trace!("Command: '{command}'");
    match cmd(fetch_env_or("PNPM", PNPM_DEFAULT_BINARY), args)
        .stdout_capture()
        .run()
    {
        Ok(output) => Ok(output),
        Err(err) => {
            debug!("Underlying I/O error: {err}");
            Err(NodeError::PnpmExecutionFailed { err, command })
        }
    }
}

/// Executes a `pnpm` task in a package context.
pub fn pnpm_execute_for_package(
    package_path: &Path,
    args: Vec<&str>
) -> Result<Output, NodeError> {
    pnpm_execute(
        vec![
            "-C",
            package_path
                .to_str()
                .expect("Could not convert package path to UTF-8"),
        ]
        .into_iter()
        .chain(args)
        .collect()
    )
}

/// Returns installed dependencies for a specific package.
pub fn pnpm_installed_dependencies_for_package(
    package_path: &Path
) -> Result<Vec<PackageJson>, NodeError> {
    let output = pnpm_execute_for_package(package_path, vec![
        "list", "--depth", "0", "--json",
    ])?;
    trace!("Installed Dependencies Output: {:?}", output);
    let json = match str::from_utf8(&output.stdout) {
        Ok(value) => value,
        Err(err) => {
            return Err(NodeError::Manifest {
                err: Box::new(NodeManifestError::Content(err)),
                filepath: package_path.to_path_buf()
            })
        }
    };
    match serde_json::from_str(json.trim()) {
        Ok(list) => Ok(list),
        Err(err) => Err(NodeError::Manifest {
            err: Box::new(NodeManifestError::ParsingFailed(err)),
            filepath: package_path.to_path_buf()
        })
    }
}

/// Checks if package dependencies are installed properly.
pub fn pnpm_ensure_dependencies_for_package(
    package_path: &Path
) -> Result<(), NodeError> {
    let package_json =
        PackageJson::from_path(&package_path.join("package.json"))?;
    let installed = &pnpm_installed_dependencies_for_package(package_path)?[0];

    let mut installed_dependencies: HashMap<String, Value> = HashMap::new();
    for collection in installed.iter().flatten() {
        installed_dependencies.extend(collection.to_owned());
    }
    installed_dependencies.shrink_to_fit();

    let mut manifest_dependencies: HashMap<String, Value> = HashMap::new();
    for collection in package_json.iter().flatten() {
        manifest_dependencies.extend(collection.to_owned());
    }
    manifest_dependencies.shrink_to_fit();

    for (name, version) in manifest_dependencies.into_iter() {
        pnpm_ensure_satisfied_dependency_for_package(
            name,
            version
                .as_str()
                .expect("Expected version to be a valid JSON string.")
                .to_string(),
            &installed_dependencies
        )?;
    }
    Ok(())
}

/// Checks if the designated dependency is installed and verify if its version satisfies manifest requirements.
pub fn pnpm_ensure_satisfied_dependency_for_package(
    package_name: String,
    expected_version: String,
    installed_dependencies: &HashMap<String, Value>
) -> Result<(), NodeError> {
    let installed_version: String = match installed_dependencies
        .get(&package_name)
    {
        Some(dependency) if dependency.get("version").is_some() => dependency
            ["version"]
            .as_str()
            .expect("Expected version to be a valid JSON string.")
            .to_string(),
        Some(_) | None => {
            return Err(NodeError::MissingDependency { package_name })
        }
    };

    let required_semver = match VersionReq::parse(&expected_version) {
        Ok(req) => req,
        Err(err) => {
            return Err(NodeError::UnparsableVersion {
                package_name,
                version: expected_version,
                err
            })
        }
    };
    let installed_semver = match Version::parse(&installed_version) {
        Ok(version) => version,
        Err(err) => {
            return Err(NodeError::UnparsableVersion {
                package_name,
                version: installed_version,
                err
            })
        }
    };
    if !required_semver.matches(&installed_semver) {
        return Err(NodeError::MismatchedDependencyVersion {
            package_name,
            expected_version,
            installed_version
        })
    }
    Ok(())
}

/// Installs specific package dependencies (if necessary).
pub fn pnpm_install_dependencies_for_package(
    package_path: &PathBuf
) -> Result<(), NodeError> {
    info!("Checking dependency availability...");
    let run_install = |package_path: &PathBuf| match pnpm_execute_for_package(
        package_path,
        vec!["install", "--frozen-lockfile"]
    ) {
        Ok(_) => {
            info!("✅ Dependencies are successfully installed.");
        }
        Err(err) => {
            error!(
                "An error occurred when trying to install dependencies: {err}"
            );
        }
    };

    match pnpm_ensure_dependencies_for_package(package_path) {
        Ok(_) => {
            info!("✅ Dependencies are up-to-date.");
        }
        Err(
            NodeError::MismatchedDependencyVersion { .. } |
            NodeError::MissingDependency { .. }
        ) => {
            info!(
                "One or multiple missing (or not up-to-date) dependencies \
                 were detected. Attempting to correct the issue by running \
                 `pnpm install`."
            );
            run_install(package_path)
        }
        Err(err) => return Err(err)
    }
    // Double-check (literally).
    pnpm_ensure_dependencies_for_package(package_path)
}

/// Checks if the system has volta installed.
pub fn is_volta_installed() -> bool {
    let mut cache =
        TOOLS_CACHE.lock().expect("Could not lock the tools cache.");
    if let Some(tool_entry) = cache.get(VOLTA_FLAG_KEY) {
        return tool_entry.present;
    }
    let volta_path = fetch_env_or("VOLTA", VOLTA_DEFAULT_BINARY);
    match cmd!(&volta_path, "--version").read() {
        Ok(stdout) => {
            trace!("Found `volta` version {stdout}.");
            let flag = Regex::new(VERSION_PATTERN)
                .expect("Invalid version regex pattern.")
                .is_match(&stdout);
            cache.put(VOLTA_FLAG_KEY, ToolEntry {
                present: true,
                path: Some(PathBuf::from(volta_path)),
                version: Some(stdout)
            });
            flag
        }
        Err(err) => {
            debug!("Underlying error: {err}");
            cache.put(VOLTA_FLAG_KEY, ToolEntry {
                present: true,
                path: None,
                version: None
            });
            false
        }
    }
}
