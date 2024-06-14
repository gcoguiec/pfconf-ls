use miette::Diagnostic;
use thiserror::Error;

#[derive(Debug, Error, Diagnostic)]
pub enum CargoError {}

// pub fn execute(args: Vec<&str>) -> Result<Output, CargoError> {

//     Ok(())
// }
