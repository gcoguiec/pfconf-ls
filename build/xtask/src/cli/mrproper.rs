use std::process::ExitCode;

use miette::Result;

use crate::cli::{
    flags::{self, CleanGrammar, CleanServer},
    Command
};

impl Command for flags::Mrproper {
    /// Removes all project build artifacts and their local dependencies.
    fn run(&self) -> Result<ExitCode> {
        CleanGrammar.run()?;
        CleanServer.run()?;
        Ok(ExitCode::SUCCESS)
    }
}
