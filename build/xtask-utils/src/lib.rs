use std::{
    env,
    fs,
    io::Error as IoError,
    path::{Path, PathBuf}
};

pub type TargetDouble = (&'static str, &'static str);

/// Fetches environment variable or a default value otherwise.
pub fn fetch_env_or(key: &str, otherwise: &str) -> String {
    env::var(format!("XTASK_{key}")).unwrap_or(String::from(otherwise))
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
