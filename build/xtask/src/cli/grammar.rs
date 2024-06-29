use std::{fs, path::PathBuf, process::ExitCode};

use miette::Result;
use tracing::{error, info, warn};

use crate::{
    cli::{flags, Command},
    from_workspace_root,
    tools::node::{
        is_volta_installed,
        pnpm_execute_for_package,
        pnpm_install_dependencies_for_package,
        PackageJson
    }
};

static GRAMMAR_PACKAGE_PATH: &str = "grammar";

impl Command for flags::GenerateGrammar {
    /// Generates parser and scanner from the grammar definition.
    fn run(self) -> Result<ExitCode> {
        let package_path =
            from_workspace_root(PathBuf::from(GRAMMAR_PACKAGE_PATH));
        let manifest =
            match PackageJson::from_path(&package_path.join("package.json")) {
                Ok(manifest) => manifest,
                Err(err) => {
                    error!("{err}");
                    return Ok(ExitCode::FAILURE)
                }
            };

        // We check if `volta` is available, if not we warn the developer about it.
        if manifest.volta.is_some() && !is_volta_installed() {
            let volta_config = manifest.volta.expect(
                "A `volta` configuration object was expected in the package \
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
        if let Err(err) = pnpm_install_dependencies_for_package(&package_path) {
            error!("{err}");
            return Ok(ExitCode::FAILURE)
        }

        info!(
            "Proceeding to generate parser/scanner from grammar definition..."
        );

        match pnpm_execute_for_package(&package_path, vec!["gen"]) {
            Ok(_) => {
                // We make sure parser was successfully generated before moving on.
                let artifact_path = package_path.join("src/parser.c");
                if !artifact_path.exists() {
                    error!(
                        "Generation succeeded but '{}' is missing from \
                         artifacts.",
                        artifact_path.to_str().expect(
                            "Could not convert artifact path to UTF-8."
                        )
                    );
                    return Ok(ExitCode::FAILURE)
                }

                info!("✅ Parser & scanner successfully generated.");
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
    /// Cleans-up grammar project by removing the `node_modules` folder.
    fn run(self) -> Result<ExitCode> {
        info!("Proceeding to clean-up grammar project...");
        let modules_path =
            from_workspace_root(PathBuf::from(GRAMMAR_PACKAGE_PATH))
                .join("node_modules");

        if !modules_path.exists() {
            info!("💪 Nothing to clean-up.");
            return Ok(ExitCode::SUCCESS)
        }

        match fs::remove_dir_all(modules_path) {
            Ok(()) => {
                info!("✅ Clean-up done!");
                Ok(ExitCode::SUCCESS)
            }
            Err(err) => {
                error!(
                    "Cleaning-up grammar node modules directory did not \
                     succeed. {err}"
                );
                Ok(ExitCode::FAILURE)
            }
        }
    }
}
