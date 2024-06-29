use std::{
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
use tracing::trace;

use crate::fetch_env_or;

static CARGO_BINARY: &str = "cargo";

#[derive(Debug, Error, Diagnostic)]
pub enum CargoManifestError {
    #[error("Failed to parse cargo manifest for {filepath}")]
    #[diagnostic(code(xtask::cargo::file_error))]
    FileError { error: IoError, filepath: PathBuf },

    #[error("Unsufficient permissions when trying to read cargo manifest.")]
    #[diagnostic(code(xtask::cargo::permission_error))]
    PermissionError,

    #[error("Failed to parse file '{filepath}' as TOML, {error}.")]
    #[diagnostic(code(xtask::cargo::toml_parsing_error))]
    TomlParsingError {
        error: TomlDeserializingError,
        filepath: PathBuf
    }
}

#[derive(Debug, Deserialize)]
#[serde(rename_all = "kebab-case")]
pub struct CargoManifestPackage {
    pub name: String
}

#[derive(Debug, Deserialize)]
#[serde(rename_all = "kebab-case")]
pub struct CargoManifest {
    pub package: Option<CargoManifestPackage>
}

impl CargoManifest {
    pub fn from_path(manifest_path: &Path) -> Result<Self, CargoManifestError> {
        let manifest_content = match read_to_string(manifest_path) {
            Ok(content) => content,
            Err(err) => {
                return Err(CargoManifestError::FileError {
                    error: err,
                    filepath: manifest_path.to_path_buf()
                })
            }
        };

        match toml::from_str(&manifest_content) {
            Ok(toml) => Ok(toml),
            Err(err) => Err(CargoManifestError::TomlParsingError {
                error: err,
                filepath: manifest_path.to_path_buf()
            })
        }
    }
}

#[derive(Debug, Error, Diagnostic)]
pub enum CargoError {
    #[error("Failed to execute `cargo` command '{command}', {error}.")]
    #[diagnostic(code(xtask::cargo::execution_failed))]
    ExecutionFailed { error: IoError, command: String },

    #[error("An error occured when handling '{filepath}' manifest. {error}.")]
    #[diagnostic(code(xtask::cargo::manifest_error))]
    ManifestError {
        error: CargoManifestError,
        filepath: PathBuf
    }
}

/// Executes cargo with provided arguments.
pub fn cargo_execute(args: Vec<&str>) -> Result<Output, CargoError> {
    let command = args.join(" ");
    trace!("Command: '{command}'");
    match cmd(fetch_env_or("CARGO", CARGO_BINARY), args).run() {
        Ok(output) => Ok(output),
        Err(err) => Err(CargoError::ExecutionFailed {
            error: err,
            command
        })
    }
}

/// Returns detected crate list at provided root.
pub fn cargo_crates_for_root(
    root: &PathBuf
) -> Result<Vec<String>, CargoError> {
    let glob_pattern = root
        .to_str()
        .expect("Expected crates root to be a valid UTF-8 string."); // We panic because this is likely a developer error.

    glob(glob_pattern)
        .expect("Invalid glob pattern used as root.") // Same panic remark as above.
        .map(|matched_file| {
            let filepath = match matched_file {
                Ok(filepath) => filepath,
                Err(err) => {
                    return Err(CargoError::ManifestError {
                        error: CargoManifestError::PermissionError,
                        filepath: err.path().to_path_buf()
                    })
                }
            };
            match CargoManifest::from_path(&filepath) {
                Ok(manifest) => Ok(manifest
                    .package
                    .expect("Package definition should provide a name.") // Cargo is checking this for us first. Should not happen.
                    .name),
                Err(err) => Err(CargoError::ManifestError {
                    error: err,
                    filepath
                })
            }
        })
        .collect::<Result<Vec<String>, CargoError>>()
}
