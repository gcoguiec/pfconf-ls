use std::{path::PathBuf, process::ExitCode};

use miette::Result;
use tracing::{error, info, warn};

use crate::{
    cli::{flags, Command},
    from_workspace_root,
    tools::node::{
        execute_for_package,
        install_dependencies_for_package,
        is_volta_installed,
        PackageJson
    }
};

static PACKAGE_PATH: &str = "grammar";

// Generates parser and scanner from the grammar definition.
impl Command for flags::GenerateGrammar {
    fn run(self) -> Result<ExitCode> {
        let package_path = from_workspace_root(PathBuf::from(PACKAGE_PATH));
        let manifest =
            match PackageJson::from_path(&package_path.join("package.json")) {
                Ok(manifest) => manifest,
                Err(err) => {
                    error!("{err}");
                    return Ok(ExitCode::FAILURE)
                }
            };

        // We check if `volta` is available, if not we warn the end-user about it.
        if manifest.volta.is_some() && !is_volta_installed() {
            let volta_config = manifest.volta.expect(
                "Volta configuration object was expected in the package \
                 manifest"
            );
            let expected_node_version = volta_config.get("node").expect(
                "A specified node version was expected in volta configuration \
                 object"
            );
            warn!(
                "The grammar project leverage `volta` to manage its Node.js \
                 runtime and it is not currently available, if you don't want \
                 to use `volta` you'll have to install \
                 `node@{expected_node_version}` manually."
            );
        }

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
