use std::{
    path::PathBuf,
    process::{ExitCode, Output}
};

use miette::Result;
use tracing::info;
use tracing_log::log::error;

use crate::{
    cli::{flags, Command},
    from_workspace_root,
    tools::cargo::{cargo_crates_for_root, cargo_execute}
};

static SERVER_CRATES_ROOT: &str = "crates/*/cargo.toml";

impl Command for flags::BuildServer {
    fn run(self) -> Result<ExitCode> {
        Ok(ExitCode::SUCCESS)
    }
}

impl Command for flags::CleanServer {
    /// Cleans-up server crates specifically (and not the xtask crates).
    fn run(self) -> Result<ExitCode> {
        info!("Proceeding to clean-up server crates...");
        for name in cargo_crates_for_root(&from_workspace_root(PathBuf::from(
            SERVER_CRATES_ROOT
        )))? {
            info!("Cleaning-up '{name}'.");
            match cargo_execute(vec!["clean", "-p", &name]) {
                Ok(_) => {}
                Err(err) => {
                    error!("Cleaning-up '{name}' crate did not succeed. {err}");
                    return Ok(ExitCode::FAILURE)
                }
            }
        }
        info!("✅ Clean-up done!");
        Ok(ExitCode::SUCCESS)
    }
}
