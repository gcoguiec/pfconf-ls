use duct::cmd;
use miette::Diagnostic;
use std::{io::Error as IoError, path::PathBuf};
use thiserror::Error;
use tracing::debug;
use xtask_utils::{fetch_env_or_else, get_sysroot_path};

#[derive(Debug, Error, Diagnostic)]
pub enum RustupEnvError {
    #[error("Couldn't obtain active Rust toolchain sysroot path. {0}")]
    #[diagnostic(code(xtask_rustup::env::missing_sysroot_error))]
    NoSysroot(IoError),

    #[error("Couldn't find rustup location.")]
    #[diagnostic(
        code(xtask_rustup::env::unlocatable_error),
        help("Running `which rustup` can help diagnose this issue.")
    )]
    Unlocatable
}

#[derive(Debug, Error, Diagnostic)]
pub enum RustupError<'r> {
    #[error("Couldn't add new toolchain target '{target_name}'. {err}")]
    #[diagnostic(code(xtask_rustup::target_addition_failed_error))]
    TargetAdditionFailed { target_name: &'r str, err: IoError }
}

/// Holds variables for local rustup installation.
#[derive(Debug)]
pub struct RustupEnv {
    pub rustup_path: PathBuf,
    pub sysroot_path: PathBuf
}

impl RustupEnv {
    /// Creates a new rustup environment initialized from local environment
    /// variables (or defaults).
    pub fn from_local_env() -> Result<Self, RustupEnvError> {
        Ok(Self {
            rustup_path: PathBuf::from(fetch_env_or_else(
                "RUSTUP_PATH",
                |_| match cmd!("which", "rustup").read() {
                    Ok(stdout) => stdout.trim().to_string(),
                    Err(_) => String::from("rustup")
                }
            )),
            sysroot_path: match get_sysroot_path() {
                Ok(path) => path,
                Err(err) => return Err(RustupEnvError::NoSysroot(err))
            }
        })
    }

    /// Checks if the active toolchain has a specific target installed.
    pub fn has_toolchain_target(&self, target_name: &str) -> bool {
        self.sysroot_path
            .join("lib/rustlib")
            .join(target_name)
            .exists()
    }

    /// Checks if the system has rustup installed.
    pub fn is_rustup_installed(&self) -> bool {
        match cmd!(&self.rustup_path, "--version")
            .stdout_capture()
            .stderr_capture()
            .read()
        {
            Ok(_) => true,
            Err(err) => {
                debug!(target: "xtask_rustup::env::is_rustup_installed",
                    rustup_path = ?self.rustup_path, "{err}");
                false
            }
        }
    }
}

/// Adds an additional target to the active toolchain.
pub fn add_toolchain_target<'a>(
    env: &'a RustupEnv,
    target_name: &'a str
) -> Result<(), RustupError<'a>> {
    if let Err(err) = cmd!(&env.rustup_path, "target", "add", target_name).run()
    {
        return Err(RustupError::TargetAdditionFailed { target_name, err })
    }
    Ok(())
}
