use std::{fs, process::ExitCode};

use miette::Result;
use tracing::{error, info, warn};
use xtask_wasi::sdk::{
    self,
    create_version_file_for_env,
    extract_release,
    WasiSdkDownloadError,
    WasiSdkEnv
};

use crate::cli::{flags, Command};

impl Command for flags::DownloadSdk {
    /// Downloads wasi-sdk release tarball and decompress it to the vendor directory.
    fn run(&self) -> Result<ExitCode> {
        let sdk_env = WasiSdkEnv::from_env();
        if sdk_env.is_ready_to_use() {
            info!("wasi-sdk is already downloaded and ready to be used.");
            return Ok(ExitCode::SUCCESS)
        }
        let release_entry = match sdk::get_release_entry_for_env(&sdk_env) {
            Ok(release_entry) => release_entry,
            Err(err) => {
                error!("{err}");
                return Ok(ExitCode::FAILURE)
            }
        };
        if let Err(err) = sdk_env.ensure_target_directory_exists() {
            error!("{err}");
            return Ok(ExitCode::FAILURE)
        }
        info!("Downloading wasi-sdk release.");
        if let Err(err) = sdk::download_release(&sdk_env, &release_entry) {
            error!("Something went wrong when downloading the wasi-sdk. {err}");
            return Ok(ExitCode::FAILURE)
        }
        info!("✅ Downloaded.");
        info!("Verifying the release signature.");
        if let Err(err) = sdk::verify_release(&sdk_env, &release_entry) {
            match &err {
                WasiSdkDownloadError::SignatureMismatch {
                    filepath, ..
                } => {
                    error!(
                        "Something went wrong when signing wasi-sdk release. \
                         {err}"
                    );
                    if self.keep || !filepath.exists() {
                        return Ok(ExitCode::FAILURE);
                    }
                    if let Err(err) = fs::remove_file(filepath) {
                        warn!(
                            "Could not clean-up wasi-sdk tarball file with \
                             invalid signature. {err}"
                        );
                    }
                    return Ok(ExitCode::FAILURE)
                }
                _ => {
                    error!(
                        "Something went wrong when signing the wasi-sdk \
                         release. {err}"
                    );
                    return Ok(ExitCode::FAILURE)
                }
            }
        }
        info!("✅ Verified.");
        info!("Extracting the release.");
        let version_name = match extract_release(&sdk_env) {
            Ok(version_name) => version_name,
            Err(err) => {
                error!(
                    "Something went wrong when extracting tarball release. \
                     {err}"
                );
                return Ok(ExitCode::FAILURE)
            }
        };
        info!("✅ Extracted.");
        if let Err(err) = create_version_file_for_env(&sdk_env, &version_name) {
            // Creating version file is not critical, we allow it to fail.
            warn!("Could not create wasi-sdk version file. {err}");
        }
        Ok(if sdk_env.is_ready_to_use() {
            info!("wasi-sdk ({version_name}) was installed.");
            info!("📁 {}", sdk_env.get_target_dir_path().display());
            ExitCode::SUCCESS
        } else {
            ExitCode::FAILURE
        })
    }
}

impl Command for flags::CleanSdk {
    /// Cleans up the wasi-sdk artifacts.
    fn run(&self) -> Result<ExitCode> {
        info!("Cleaning-up the wasi-sdk artifacts.");
        let mut exit_code = ExitCode::SUCCESS;
        let sdk_env = WasiSdkEnv::from_env();
        [
            sdk_env.get_version_file_path(),
            sdk_env.get_release_tarball_path(),
            sdk_env.get_target_dir_path()
        ]
        .into_iter()
        .for_each(|path| {
            if !path.exists() {
                return
            }
            if let Err(err) = if path.is_dir() {
                fs::remove_dir_all(path)
            } else {
                fs::remove_file(path)
            } {
                warn!(
                    "Cleaning-up '{}' artifact did not succeed. {err}",
                    path.display()
                );
                exit_code = ExitCode::FAILURE;
            }
        });
        info!("✅ Cleaned-up.");
        Ok(exit_code)
    }
}

impl Command for flags::UpdateSdk {
    /// Cleans up the wasi-sdk artifacts.
    fn run(&self) -> Result<ExitCode> {
        flags::CleanSdk.run()?;
        let download_flag = flags::DownloadSdk { keep: self.keep };
        flags::DownloadSdk::run(&download_flag)
    }
}
