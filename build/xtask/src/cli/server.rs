use std::{
    ffi::OsString,
    fs::create_dir_all,
    path::PathBuf,
    process::ExitCode
};

use duct::cmd;
use miette::Result;
use tracing::{info, warn};
use tracing_log::log::error;

use xtask_cargo::{cargo_crates_for_root, cargo_execute, CargoEnv};
use xtask_node::{pnpx_execute, NodeEnv};
use xtask_rustup::{add_toolchain_target, RustupEnv};
use xtask_utils::{cli::Question, fetch_env_or, from_workspace_root};
use xtask_wasi::sdk;

use crate::cli::{flags, Command};

#[derive(Debug)]
pub struct ServerEnv {
    pub crates_root_path: PathBuf,
    pub manifest_path: PathBuf
}

impl ServerEnv {
    /// Creates a new language server environment from environment variables.
    ///
    /// # Environment Variables
    ///
    /// - `XTASK_SERVER_CRATES_ROOT_PATH`: Set root directory path for all server crates.
    pub fn from_local_env() -> Self {
        let crates_root_path = from_workspace_root(PathBuf::from(
            fetch_env_or("SERVER_CRATES_ROOT_PATH", "crates")
        ));
        let manifest_path = crates_root_path.join("pfconf-ls/Cargo.toml");
        Self {
            crates_root_path,
            manifest_path
        }
    }
}

impl Command for flags::BuildServer {
    /// Builds the language server.
    fn run(&self) -> Result<ExitCode> {
        if self.wasi {
            flags::BuildServer::build_wasi_target(self)
        } else {
            flags::BuildServer::build_system_target(self)
        }
    }
}

impl flags::BuildServer {
    /// Builds language server for provided target.
    fn build_system_target(&self) -> Result<ExitCode> {
        Ok(ExitCode::SUCCESS)
    }

    /// Builds language server for the wasm32-wasi target.
    fn build_wasi_target(&self) -> Result<ExitCode> {
        // Several dependencies (rustix,...) are not building with wasm32-wasip2 target (as of 28 Aug 2024)
        // That's why we need to build to wasip1 first and then transpile it to wasip2 with jco.
        let intermediate_target_name = "wasm32-wasip1";
        let final_target_name = "wasm32-wasip2";
        let build_mode = match self.release {
            true => "release",
            false => "debug"
        };
        info!("Building in '{build_mode}' mode.");
        let cargo_env = CargoEnv::from_local_env();
        let rustup_env = match RustupEnv::from_local_env() {
            Ok(env) => env,
            Err(err) => {
                error!(
                    "Something went wrong when initializing rustup \
                     environment. {err}"
                );
                return Ok(ExitCode::FAILURE)
            }
        };
        if !rustup_env.is_rustup_installed() {
            error!("A working rustup setup is required for this build.");
            return Ok(ExitCode::FAILURE)
        }
        info!(
            "Checking if '{intermediate_target_name}' toolchain target is \
             installed."
        );
        if !rustup_env.has_toolchain_target(intermediate_target_name) &&
            Question::new(format!(
                "The target '{intermediate_target_name}' is not installed for active \
                 toolchain. Do you want xtask to install it for you?"
            ))
            .register_answer("yes")
            .register_answer("no")
            .default_answer("no") // opt-in
            .ask()
            .is_ok_and(|answer| answer.is_yes())
        {
            if let Err(err) =
                add_toolchain_target(&rustup_env, intermediate_target_name)
            {
                error!("Couldn't add {intermediate_target_name} target. {err}");
            }
        }
        if !rustup_env.has_toolchain_target(intermediate_target_name) {
            info!(
                "Please install the toolchain target manually by running \
                 `rustup target add {intermediate_target_name}`."
            );
            return Ok(ExitCode::FAILURE)
        }
        info!(
            "'{intermediate_target_name}' target is installed. Ready to roll!"
        );
        let sdk_env = sdk::WasiSdkEnv::from_local_env();
        info!("Verifying if wasi-sdk directory is present.");
        if !sdk_env.is_ready_to_use() {
            error!(
                "To build the language server for the wasm32-wasi target the \
                 wasi-sdk must be installed. Please run `cargo xtask wasi \
                 download-sdk` first."
            );
            return Ok(ExitCode::FAILURE)
        }
        info!(
            "All good! wasi-sdk path is '{}'.",
            sdk_env.get_target_dir_path().display()
        );
        info!("Checking cargo-component presence.");
        if !cargo_env.is_cargo_component_installed() {
            // We're using a modified version of cargo-component at the moment.
            error!(
                "
                The cargo-component command must be installed \
                 for this build to proceed.
                help: `cargo install \
                 --git https://github.com/gcoguiec/cargo-component.git \
                 --branch configurable-bindings-path`
            "
            );
            return Ok(ExitCode::FAILURE)
        }
        info!("Good to go! Let's proceed with the build.");
        let mut args = Vec::from([
            OsString::from("component"),
            OsString::from("build"),
            OsString::from("-q"),
            OsString::from("--target"),
            OsString::from(intermediate_target_name),
            OsString::from("-p"),
            OsString::from("pfconf-ls")
        ]);
        if self.release {
            args.push(OsString::from("--release"));
        }
        if let Some(jobs) = self.jobs {
            args.push(OsString::from("--jobs"));
            args.push(OsString::from(jobs.to_string()));
        }
        if let Err(err) = cmd("cargo", args)
            .env(
                "RUSTFLAGS",
                format!(
                    "-L {}",
                    sdk_env
                        .get_target_dir_path()
                        .join("share/wasi-sysroot/lib/wasm32-wasi")
                        .display()
                )
            )
            .env("CC", sdk_env.get_target_dir_path().join("bin/clang"))
            .env("CFLAGS", "-Wno-implicit-function-declaration")
            .env("WIT_BINDGEN_DEBUG", format!("{}", !self.release as i8))
            .run()
        {
            error!("{err}");
            return Ok(ExitCode::FAILURE)
        }
        info!(
            "✅ Intermediate '{intermediate_target_name}' build is successful!"
        );
        let node_env = NodeEnv::from_local_env();
        let wasm_path = from_workspace_root(
            PathBuf::from("target")
                .join(intermediate_target_name)
                .join(build_mode)
                .join("pfconf-ls.wasm")
        );
        let output_path = from_workspace_root(
            PathBuf::from("target")
                .join(final_target_name)
                .join(build_mode)
                .join("pfconf-ls")
        );
        if let Some(output_dir) = output_path.parent() {
            if let Err(err) = create_dir_all(output_dir) {
                warn!("Couldn't create output directory. {err}");
            }
        }
        info!(
            "Transpiling from '{intermediate_target_name}' to \
             '{final_target_name}'."
        );
        if let Err(err) = pnpx_execute(&node_env, vec![
            "@bytecodealliance/jco",
            "transpile",
            "-q",
            "-m",
            "--no-nodejs-compat",
            &wasm_path.display().to_string(),
            "-o",
            &output_path.display().to_string(),
        ]) {
            error!("{err}");
            return Ok(ExitCode::FAILURE);
        }
        info!("✅ Final build is successful!");
        info!("Build path: '{path}'.", path = output_path.display());
        Ok(ExitCode::SUCCESS)
    }
}

impl Command for flags::CleanServer {
    /// Cleans-up server crates specifically (and not the xtask crates).
    fn run(&self) -> Result<ExitCode> {
        let server_env = ServerEnv::from_local_env();
        info!("Proceeding to clean-up server crates.");
        for name in cargo_crates_for_root(&server_env.crates_root_path)? {
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
