use std::{path::PathBuf, process::ExitCode};

use miette::Result;
use tracing::info;
use tracing_log::log::error;

use xtask_cargo::{cargo_crates_for_root, cargo_execute};
use xtask_utils::{fetch_env_or, from_workspace_root};
use xtask_wasi::sdk::WasiSdkError;

use crate::cli::{flags, Command};

pub struct ServerEnv {}

impl Command for flags::BuildServer {
    /// Builds the language server.
    fn run(&self) -> Result<ExitCode> {
        if self.wasm32 {
            flags::BuildServer::build_wasm32_target()?;
            return Ok(ExitCode::SUCCESS)
        }
        flags::BuildServer::build_system_target();
        Ok(ExitCode::SUCCESS)
    }
}

impl flags::BuildServer {
    /// Returns the root at which the language server crates lie.
    fn get_server_crates_root() -> PathBuf {
        from_workspace_root(PathBuf::from(fetch_env_or(
            "SERVER_CRATES_ROOT_PATH",
            "crates"
        )))
    }

    fn build_system_target() {}

    fn build_wasm32_target() -> Result<(), WasiSdkError> {
        // RUSTFLAGS='-L /Users/yugo/projects/pfconf-ls/target/wasi-sdk/wasi-sdk-22.0/share/wasi-sysroot/lib/wasm32-wasi -lstatic=c
        // ++ -lstatic=c++abi' CXXSTDLIB=c++ CC=/Users/yugo/projects/pfconf-ls/target/wasi-sdk/wasi-sdk-22.0/bin/clang CFLAGS="-Wno-impl
        // icit-function-declaration" CXX=/Users/yugo/projects/pfconf-ls/target/wasi-sdk/wasi-sdk-22.0/bin/clang++ cargo component build -p pfconf-ls --release
        Ok(())
    }
}

impl Command for flags::CleanServer {
    /// Cleans-up server crates specifically (and not the xtask crates).
    fn run(&self) -> Result<ExitCode> {
        info!("Proceeding to clean-up server crates...");
        for name in cargo_crates_for_root(
            &flags::BuildServer::get_server_crates_root()
        )? {
            info!("Cleaning-up '{name}'.");
            if let Err(err) = cargo_execute(vec!["clean", "-p", &name]) {
                error!("Cleaning-up '{name}' crate did not succeed. {err}");
                return Ok(ExitCode::FAILURE)
            }
        }
        info!("✅ Clean-up done!");
        Ok(ExitCode::SUCCESS)
    }
}
