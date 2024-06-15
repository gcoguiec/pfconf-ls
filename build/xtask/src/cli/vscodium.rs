use std::process::ExitCode;

use miette::Result;

use crate::cli::{flags, Command};

impl Command for flags::BuildVscodium {
    fn run(self) -> Result<ExitCode> {
        Ok(ExitCode::SUCCESS)
    }
}
