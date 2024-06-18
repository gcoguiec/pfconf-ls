use std::process::Output;

use duct::cmd;
use miette::Diagnostic;
use std::io::Error as IoError;
use thiserror::Error;
use tracing::{debug, trace};

use crate::fetch_env_or;

static CARGO_BINARY: &str = "cargo";

#[derive(Debug, Error, Diagnostic)]
pub enum CargoError {
    #[error("Failed to execute `cargo` command '{command}', {error}.")]
    #[diagnostic(code(xtask::cargo::execution_failed))]
    ExecutionFailed { error: IoError, command: String }
}

/// Executes cargo with provided arguments.
pub fn cargo_execute(args: Vec<&str>) -> Result<Output, CargoError> {
    let command = args.join(" ");
    trace!("Command: '{command}'");
    match cmd(fetch_env_or("CARGO", CARGO_BINARY), args).run() {
        Ok(output) => Ok(output),
        Err(err) => {
            debug!("Underlying I/O error: {err}");
            Err(CargoError::ExecutionFailed {
                error: err,
                command
            })
        }
    }
}
