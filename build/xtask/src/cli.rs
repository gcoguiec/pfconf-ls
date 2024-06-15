use std::process::ExitCode;

use miette::Result;

pub trait Command {
    fn run(self) -> Result<ExitCode>;
}

pub mod flags;
pub mod grammar;
pub mod server;
pub mod vscodium;
