use std::process::ExitCode;

use miette::Result;

pub mod flags;
pub mod grammar;
pub mod mrproper;
pub mod server;
pub mod vscodium;
pub mod wasi;

pub trait Command {
    fn run(&self) -> Result<ExitCode>;
}
