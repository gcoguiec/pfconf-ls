use std::{path::PathBuf, process::ExitCode};

use miette::Result;
use tracing::{error, info};

use crate::{
    cli::{flags, Command},
    from_workspace_root,
    tools::pnpm::{execute_for_package, install_dependencies_for_package}
};

static PACKAGE_PATH: &str = "grammar";

// Generates parser and scanner from the grammar definition.
impl Command for flags::GenerateGrammar {
    fn run(self) -> Result<ExitCode> {
        let package_path = from_workspace_root(PathBuf::from(PACKAGE_PATH));

        // We verify that grammar project `node_modules` is correctly populated
        // and that all dependencies are up-to-date. If not, we try running
        // `pnpm install` once to correct the issue.
        if let Err(err) = install_dependencies_for_package(&package_path) {
            error!("{err}");
            return Ok(ExitCode::FAILURE)
        }

        info!(
            "Proceeding to generate parser/scanner from grammar definition..."
        );
        match execute_for_package(&package_path, vec!["gen"]) {
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

impl Command for flags::CleanGrammar {
    fn run(self) -> Result<ExitCode> {
        Ok(ExitCode::SUCCESS)
    }
}
