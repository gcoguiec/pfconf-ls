use std::{
    env::{self, VarError},
    fs,
    io::Error as IoError,
    path::{Path, PathBuf}
};

use duct::cmd;
use miette::Result;

pub mod cli;

pub static VERSION_PATTERN: &str = r"^\d+.\d+.\d+$";

pub type TargetDouble = (&'static str, &'static str);

/// Fetches environment variable or a default value otherwise.
pub fn fetch_env_or(key: &str, otherwise: &str) -> String {
    env::var(format!("XTASK_{key}")).unwrap_or(String::from(otherwise))
}

/// Fetches environment variable or computes its default value from a closure.
pub fn fetch_env_or_else<F: FnOnce(VarError) -> String>(
    key: &str,
    otherwise: F
) -> String {
    env::var(format!("XTASK_{key}")).unwrap_or_else(otherwise)
}

/// Returns a path buffer beginning at workspace root.
// see: https://github.com/rust-lang/cargo/pull/13644
pub fn from_workspace_root(path: PathBuf) -> PathBuf {
    Path::new(env!("CARGO_RUSTC_CURRENT_DIR")).join(path)
}

/// Creates a directory path (recursively) if it does not already exist.
pub fn create_directory_path(dir_path: &PathBuf) -> Result<(), IoError> {
    if dir_path.exists() {
        return Ok(())
    }
    fs::create_dir_all(dir_path)
}

/// Returns system target double `(arch,os)``.
pub fn get_target_double() -> TargetDouble {
    (env::consts::ARCH, env::consts::OS)
}

/// Returns rust toolchain sysroot path.
pub fn get_sysroot_path() -> Result<PathBuf, IoError> {
    Ok(PathBuf::from(
        cmd!(fetch_env_or("RUSTC_PATH", "rustc"), "--print", "sysroot")
            .read()?
            .trim()
    ))
}
