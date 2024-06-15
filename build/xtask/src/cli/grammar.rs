use std::{path::PathBuf, process::ExitCode};

use miette::Result;
use tracing::{error, info, trace};

use crate::{
    cli::{flags, Command},
    from_workspace_root,
    tools::pnpm::{execute_for_package, install_dependencies_for_package}
};

impl Command for flags::GenerateGrammar {
    fn run(self) -> Result<ExitCode> {
        if let Err(err) = install_dependencies_for_package(from_workspace_root(
            PathBuf::from("grammar")
        )) {
            error!("{err}");
            return Ok(ExitCode::FAILURE)
        }

        info!(
            "Proceeding to generate parser/scanner from grammar definition..."
        );
        match execute_for_package(
            from_workspace_root(PathBuf::from("grammar")),
            vec!["gen"]
        ) {
            Ok(_) => {
                info!("Parser & scanner successfully generated.");
                Ok(ExitCode::SUCCESS)
            }
            Err(err) => {
                error!("{err}");
                Ok(ExitCode::FAILURE)
            }
        }
    }
}

// @TODO this sucks
impl Command for flags::CleanGrammar {
    fn run(self) -> Result<ExitCode> {
        match execute_for_package(
            from_workspace_root(PathBuf::from("grammar")),
            vec!["prune"]
        ) {
            Ok(_) => {
                trace!("Extraneous packages were removed.");
                Ok(ExitCode::SUCCESS)
            }
            Err(err) => {
                error!("{err}");
                Ok(ExitCode::FAILURE)
            }
        }
    }
}
