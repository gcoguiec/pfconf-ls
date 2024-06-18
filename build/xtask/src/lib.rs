#![deny(unsafe_code)]
#![deny(unsafe_op_in_unsafe_fn)]

use std::{
    env,
    path::{Path, PathBuf}
};

mod cache;
pub mod cli;
pub mod log;
mod tools;

/// Returns a path buffer beginning at workspace root.
// see: https://github.com/rust-lang/cargo/pull/13644
pub fn from_workspace_root(path: PathBuf) -> PathBuf {
    Path::new(env!("CARGO_RUSTC_CURRENT_DIR")).join(path)
}

/// Fetches environment variable or a default value otherwise.
pub fn fetch_env_or(key: &str, otherwise: &str) -> String {
    env::var(format!("XTASK_{key}")).unwrap_or(String::from(otherwise))
}
