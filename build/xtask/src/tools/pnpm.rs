use std::{
    collections::HashMap,
    fs::File,
    io::BufReader,
    path::PathBuf,
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
static VERSION_PATTERN: &str = r"^\d+.\d+.\d+$";

#[derive(Debug, Error, Diagnostic)]
pub enum PnpmError {
    #[error("The `pnpm` package manager is not present on this system.")]
    #[diagnostic(code(xtask::pnpm::not_present))]
    NotPresent,

    #[error("Failed to execute `pnpm` command '{command}', {error}.")]
    #[diagnostic(code(xtask::pnpm::execution_failed))]
    ExecutionFailed { error: IoError, command: String },

    #[error("Failed to convert manifest content to UTF-8, {0}.")]
    #[diagnostic(code(xtask::pnpm::output_processing_error))]
    ManifestProcessingError(Utf8Error),

    #[error("Failed to parse file '{filepath}' as JSON, {error}.")]
    #[diagnostic(code(xtask::pnpm::json_parsing_error))]
    JSONParsingError {
        error: SerdeJsonError,
        filepath: String
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
    pub peer_dependencies: Option<HashMap<String, Value>>
}

impl PackageJson {
    pub fn from_path(manifest_path: PathBuf) -> Result<Self, PnpmError> {
        let reader =
            BufReader::new(match File::open(manifest_path.to_str().unwrap()) {
                Ok(file) => file,
                Err(err) => {
                    return Err(PnpmError::InvalidPackageManifestPath {
                        error: err,
                        filepath: manifest_path
                    })
                }
            });
        match serde_json::from_reader(reader) {
            Ok(json) => Ok(json),
            Err(err) => Err(PnpmError::JSONParsingError {
                error: err,
                filepath: String::from(manifest_path.to_str().unwrap())
            })
        }
    }

    pub fn clone_iter(
        &self
    ) -> impl Iterator<Item = Option<HashMap<String, Value>>> {
        vec![
            self.dependencies.clone(),
            self.dev_dependencies.clone(),
            self.peer_dependencies.clone(),
        ]
        .into_iter()
    }
}

/// Checks if the system has pnpm installed.
pub fn is_pnpm_installed() -> bool {
    let mut cache = TOOLS_FLAG_CACHE.lock().unwrap();
    if let Some(option) = cache.get(PNPM_FLAG_KEY) {
        return *option;
    }
    match cmd!(PNPM_BINARY, "--version").read() {
        Ok(stdout) => {
            trace!("Found `pnpm` version {stdout}.");
            let flag = Regex::new(VERSION_PATTERN).unwrap().is_match(&stdout);
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

/// Executes `pnpm` with provided arguments.
pub fn pnpm_execute(args: Vec<&str>) -> Result<Output, PnpmError> {
    if !is_pnpm_installed() {
        error!(
            "A dependency is missing: the Node package manager `pnpm` is not \
             installed."
        );
        return Err(PnpmError::NotPresent);
    }
    let command = args.join(" ");
    trace!("Command: '{command}'");
    match cmd(PNPM_BINARY, args).stdout_capture().run() {
        Ok(output) => Ok(output),
        Err(err) => {
            debug!("Underlying I/O error: {err}");
            Err(PnpmError::ExecutionFailed {
                error: err,
                command
            })
        }
    }
}

/// Returns installed dependencies for a specific package.
pub fn installed_dependencies_for_package(
    package_path: PathBuf
) -> Result<Vec<PackageJson>, PnpmError> {
    let output = pnpm_execute(vec![
        "-C",
        package_path
            .to_str()
            .expect("Unable to convert package path"),
        "list",
        "--depth",
        "0",
        "--json",
    ])?;
    trace!("Installed Dependencies Output: {:?}", output);
    let json = match str::from_utf8(&output.stdout) {
        Ok(value) => value,
        Err(err) => return Err(PnpmError::ManifestProcessingError(err))
    };
    match serde_json::from_str(json.trim()) {
        Ok(list) => Ok(list),
        Err(err) => Err(PnpmError::JSONParsingError {
            error: err,
            filepath: String::from(package_path.to_str().unwrap())
        })
    }
}

/// Check if package dependencies are installed properly.
pub fn ensure_dependencies(package_path: PathBuf) -> Result<(), PnpmError> {
    let package_json =
        PackageJson::from_path(package_path.join("package.json"))?;
    let installed = &installed_dependencies_for_package(package_path)?[0];

    let mut installed_dependencies: HashMap<String, Value> = HashMap::new();
    for collection in installed.clone_iter().flatten() {
        installed_dependencies.extend(collection);
    }
    installed_dependencies.shrink_to_fit();

    let mut manifest_dependencies: HashMap<String, Value> = HashMap::new();
    for collection in package_json.clone_iter().flatten() {
        manifest_dependencies.extend(collection);
    }
    manifest_dependencies.shrink_to_fit();

    for (name, version) in manifest_dependencies.into_iter() {
        ensure_satisfied_dependency(
            name,
            version.as_str().unwrap().to_string(),
            &installed_dependencies
        )?;
    }
    Ok(())
}

/// Check if the designated dependency is installed and verify if its version satisfies manifest requirements.
pub fn ensure_satisfied_dependency(
    package_name: String,
    expected_version: String,
    installed_dependencies: &HashMap<String, Value>
) -> Result<(), PnpmError> {
    let installed_version: String =
        match installed_dependencies.get(&package_name) {
            Some(dependency) if dependency.get("version").is_some() => {
                dependency["version"].as_str().unwrap().to_string()
            }
            Some(_) | None => {
                return Err(PnpmError::MissingDependency { package_name })
            }
        };

    let required_semver = match VersionReq::parse(&expected_version) {
        Ok(req) => req,
        Err(err) => {
            return Err(PnpmError::UnparsableVersion {
                package_name,
                version: expected_version,
                error: err
            })
        }
    };
    let installed_semver = match Version::parse(&installed_version) {
        Ok(version) => version,
        Err(err) => {
            return Err(PnpmError::UnparsableVersion {
                package_name,
                version: installed_version,
                error: err
            })
        }
    };
    if !required_semver.matches(&installed_semver) {
        return Err(PnpmError::MismatchedDependencyVersion {
            package_name,
            expected_version,
            installed_version
        })
    }
    Ok(())
}

/// Install specific package dependencies (if necessary).
pub fn install_dependencies(package_path: PathBuf) -> Result<(), PnpmError> {
    info!("Checking dependency availability...");
    match ensure_dependencies(package_path.to_owned()) {
        Ok(_) => {
            info!("Dependencies are up-to-date.");
        }
        Err(
            PnpmError::MismatchedDependencyVersion { .. } |
            PnpmError::MissingDependency { .. }
        ) => {
            info!(
                "One or multiple missing (or not up-to-date) dependencies \
                 were detected. Attempting to correct the issue by running \
                 `pnpm install`."
            );
            match pnpm_execute(vec![
                "-C",
                package_path.to_str().unwrap(),
                "install",
            ]) {
                Ok(_) => {
                    info!("Dependencies are successfully installed.");
                }
                Err(err) => {
                    error!(
                        "An error occured when trying to install \
                         dependencies: {err}"
                    );
                }
            }
        }
        Err(err) => return Err(err)
    }
    // Double-check (literally).
    ensure_dependencies(package_path)
}
