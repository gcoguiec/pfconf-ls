use std::process::ExitCode;

use miette::Result;

use crate::cli::{flags, Command};

impl Command for flags::BuildServer {
    fn run(self) -> Result<ExitCode> {
        Ok(ExitCode::SUCCESS)
    }
}

impl Command for flags::CleanServer {
    fn run(self) -> Result<ExitCode> {
        Ok(ExitCode::SUCCESS)
    }
}
