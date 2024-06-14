use std::process::ExitCode;

use duct::cmd;
use miette::{IntoDiagnostic, Result};

use crate::cli::{flags, Command};

impl Command for flags::BuildServer {
    fn run(self) -> Result<ExitCode> {
        // let target = if self.wasm32 {

        // } else { };

        let args = format!("build -p pfconf-ls");

        cmd("cargo", args.split_whitespace())
            .run()
            .into_diagnostic()?;

        Ok(ExitCode::SUCCESS)
    }
}
