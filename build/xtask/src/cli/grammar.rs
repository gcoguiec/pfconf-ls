use std::{path::PathBuf, process::ExitCode};

use miette::Result;
use tracing::{error, info, trace};

use crate::{
    cli::{flags, Command},
    from_workspace_root,
    tools::pnpm::{ensure_dependencies, pnpm_execute, PnpmError}
};

fn ensure_grammar_dependencies() -> Result<(), PnpmError> {
    match ensure_dependencies(from_workspace_root(PathBuf::from("grammar"))) {
        Ok(_) => {
            info!("Dependencies are up-to-date.");
        }
        Err(
            PnpmError::MismatchedDependencyVersion { .. } |
            PnpmError::MissingDependency { .. }
        ) => {
            info!(
                "One or multiple missing (or not up-to-date) dependencies \
                 were detected. Attempting to correct the issue by running \
                 `pnpm install`."
            );
            match pnpm_execute(vec![
                "-C",
                from_workspace_root(PathBuf::from("grammar"))
                    .to_str()
                    .unwrap(),
                "install",
            ]) {
                Ok(_) => {
                    info!("Dependencies successfully installed.");
                }
                Err(err) => {
                    error!(
                        "An error occured when trying to install \
                         dependencies: {err}"
                    );
                }
            }
        }
        Err(err) => return Err(err)
    }
    // Double-check package installation by calling the `ensure_dependencies`
    // function a second time.
    ensure_dependencies(from_workspace_root(PathBuf::from("grammar")))
}

impl Command for flags::GenerateGrammar {
    fn run(self) -> Result<ExitCode> {
        info!("Checking dependency availability.");
        match ensure_grammar_dependencies() {
            Ok(_) => {}
            Err(err) => {
                error!("{err}");
                return Ok(ExitCode::FAILURE)
            }
        }

        info!("Proceeding to generate parser/scanner from grammar definition:");
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
