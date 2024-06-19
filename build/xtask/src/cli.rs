use std::process::ExitCode;

use miette::Result;

pub mod clean;
pub mod flags;
pub mod grammar;
pub mod server;
pub mod vscodium;

pub trait Command {
    fn run(self) -> Result<ExitCode>;
}
