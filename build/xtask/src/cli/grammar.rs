use std::{path::PathBuf, process::ExitCode};

use miette::Result;
use tracing::{error, info, trace};

use crate::{
    cli::{flags, Command},
    from_workspace_root,
    tools::pnpm::{install_dependencies, pnpm_execute}
};

impl Command for flags::GenerateGrammar {
    fn run(self) -> Result<ExitCode> {
        match install_dependencies(from_workspace_root(PathBuf::from(
            "grammar"
        ))) {
            Ok(_) => {}
            Err(err) => {
                error!("{err}");
                return Ok(ExitCode::FAILURE)
            }
        }

        info!(
            "Proceeding to generate parser/scanner from grammar definition..."
        );
        match pnpm_execute(vec![
            "-C",
            from_workspace_root(PathBuf::from("grammar"))
                .to_str()
                .unwrap(),
            "gen",
        ]) {
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
        match pnpm_execute(vec![
            "-C",
            from_workspace_root(PathBuf::from("grammar"))
                .to_str()
                .unwrap(),
            "prune",
        ]) {
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
