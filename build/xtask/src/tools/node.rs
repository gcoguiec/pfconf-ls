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

use crate::cache::TOOLS_FLAG_CACHE;

static PNPM_BINARY: &str = "pnpm";
static PNPM_FLAG_KEY: &str = "has_pnpm";

static VOLTA_BINARY: &str = "volta";
static VOLTA_FLAG_KEY: &str = "has_volta";

static VERSION_PATTERN: &str = r"^\d+.\d+.\d+$";

#[derive(Debug, Error, Diagnostic)]
pub enum NodeError {
    #[error("The `pnpm` package manager is not present on this system.")]
    #[diagnostic(code(xtask::pnpm::not_present))]
    PnpmNotPresent,

    #[error("Failed to execute `pnpm` command '{command}', {error}.")]
    #[diagnostic(code(xtask::pnpm::execution_failed))]
    PnpmExecutionFailed { error: IoError, command: String },

    #[error("Failed to convert manifest content to UTF-8, {0}.")]
    #[diagnostic(code(xtask::pnpm::output_processing_error))]
    ManifestProcessingError(Utf8Error),

    #[error("Failed to parse file '{filepath}' as JSON, {error}.")]
    #[diagnostic(code(xtask::pnpm::json_parsing_error))]
    JSONParsingError {
        error: SerdeJsonError,
        filepath: PathBuf
    },

    #[error("Missing dependency package '{package_name}'.")]
    #[diagnostic(code(xtask::pnpm::missing_dependency))]
    MissingDependency { package_name: String },

    #[error(
        "Could not parse '{version}' version for package '{package_name}'. \
         {error}"
    )]
    #[diagnostic(code(xtask::pnpm::unparsable_version))]
    UnparsableVersion {
        package_name: String,
        version: String,
        error: SemverVersion
    },

    #[error(
        "Version mismatch for dependency package '{package_name}', version \
         '{expected_version}' expected, '{installed_version}' installed."
    )]
    #[diagnostic(code(xtask::pnpm::mismatched_dependency_version))]
    MismatchedDependencyVersion {
        package_name: String,
        expected_version: String,
        installed_version: String
    },

    #[error("Could not find a package manifest at path '{filepath}'. {error}")]
    #[diagnostic(code(xtask::pnpm::invalid_package_manifest_path))]
    InvalidPackageManifestPath { error: IoError, filepath: PathBuf }
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
                return Err(NodeError::InvalidPackageManifestPath {
                    error: err,
                    filepath: manifest_path.to_path_buf()
                })
            }
        });
        match serde_json::from_reader(reader) {
            Ok(json) => Ok(json),
            Err(err) => Err(NodeError::JSONParsingError {
                error: err,
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
    let mut cache = TOOLS_FLAG_CACHE
        .lock()
        .expect("Could not lock the tools flag cache.");
    if let Some(option) = cache.get(PNPM_FLAG_KEY) {
        return *option;
    }
    match cmd!(PNPM_BINARY, "--version").read() {
        Ok(stdout) => {
            trace!("Found `pnpm` version {stdout}.");
            let flag = Regex::new(VERSION_PATTERN)
                .expect("Invalid version regex pattern.")
                .is_match(&stdout);
            cache.put(PNPM_FLAG_KEY, flag);
            flag
        }
        Err(err) => {
            debug!("Underlying error: {err}");
            cache.put(PNPM_FLAG_KEY, false);
            false
        }
    }
}

/// Executes node / pnpm with provided arguments.
pub fn execute(args: Vec<&str>) -> Result<Output, NodeError> {
    if !is_pnpm_installed() {
        return Err(NodeError::PnpmNotPresent);
    }
    let command = args.join(" ");
    trace!("Command: '{command}'");
    match cmd(PNPM_BINARY, args).stdout_capture().run() {
        Ok(output) => Ok(output),
        Err(err) => {
            debug!("Underlying I/O error: {err}");
            Err(NodeError::PnpmExecutionFailed {
                error: err,
                command
            })
        }
    }
}

/// Executes a `pnpm` task in a package context.
pub fn execute_for_package(
    package_path: &Path,
    args: Vec<&str>
) -> Result<Output, NodeError> {
    execute(
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
pub fn installed_dependencies_for_package(
    package_path: &Path
) -> Result<Vec<PackageJson>, NodeError> {
    let output = execute_for_package(package_path, vec![
        "list", "--depth", "0", "--json",
    ])?;
    trace!("Installed Dependencies Output: {:?}", output);
    let json = match str::from_utf8(&output.stdout) {
        Ok(value) => value,
        Err(err) => return Err(NodeError::ManifestProcessingError(err))
    };
    match serde_json::from_str(json.trim()) {
        Ok(list) => Ok(list),
        Err(err) => Err(NodeError::JSONParsingError {
            error: err,
            filepath: package_path.to_path_buf()
        })
    }
}

/// Check if package dependencies are installed properly.
pub fn ensure_dependencies_for_package(
    package_path: &Path
) -> Result<(), NodeError> {
    let package_json =
        PackageJson::from_path(&package_path.join("package.json"))?;
    let installed = &installed_dependencies_for_package(package_path)?[0];

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
        ensure_satisfied_dependency_for_package(
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

/// Check if the designated dependency is installed and verify if its version satisfies manifest requirements.
pub fn ensure_satisfied_dependency_for_package(
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
                error: err
            })
        }
    };
    let installed_semver = match Version::parse(&installed_version) {
        Ok(version) => version,
        Err(err) => {
            return Err(NodeError::UnparsableVersion {
                package_name,
                version: installed_version,
                error: err
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

/// Install specific package dependencies (if necessary).
pub fn install_dependencies_for_package(
    package_path: &PathBuf
) -> Result<(), NodeError> {
    info!("Checking dependency availability...");
    let run_install =
        |package_path: &PathBuf| match execute_for_package(package_path, vec![
            "install",
            "--frozen-lockfile",
        ]) {
            Ok(_) => {
                info!("Dependencies are successfully installed.");
            }
            Err(err) => {
                error!(
                    "An error occured when trying to install dependencies: \
                     {err}"
                );
            }
        };

    match ensure_dependencies_for_package(package_path) {
        Ok(_) => {
            info!("Dependencies are up-to-date.");
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
    ensure_dependencies_for_package(package_path)
}

/// Checks if the system has volta installed.
pub fn is_volta_installed() -> bool {
    let mut cache = TOOLS_FLAG_CACHE
        .lock()
        .expect("Could not lock the tools flag cache.");
    if let Some(option) = cache.get(VOLTA_FLAG_KEY) {
        return *option;
    }
    match cmd!(VOLTA_BINARY, "--version").read() {
        Ok(stdout) => {
            trace!("Found `volta` version {stdout}.");
            let flag = Regex::new(VERSION_PATTERN)
                .expect("Invalid version regex pattern.")
                .is_match(&stdout);
            cache.put(VOLTA_FLAG_KEY, flag);
            flag
        }
        Err(err) => {
            debug!("Underlying error: {err}");
            cache.put(VOLTA_FLAG_KEY, false);
            false
        }
    }
}
