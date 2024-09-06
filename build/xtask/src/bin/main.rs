use std::{
    env,
    io::{stderr, IsTerminal},
    process::ExitCode
};

use miette::{IntoDiagnostic, Result};
use tracing::error;
use xtask::{
    cli::{flags, Command},
    log::{init_logger, LoggerConfig}
};

fn main() -> Result<ExitCode> {
    // Miette hook configuration isn't critical, we allow it to fail.
    let _ = miette::set_hook(Box::new(|_| {
        Box::new(
            miette::MietteHandlerOpts::new()
                .color(stderr().is_terminal())
                .terminal_links(true)
                .with_cause_chain()
                .build()
        )
    }));

    // Registers logger globally.
    init_logger(LoggerConfig::from_env("XTASK_LOG")).into_diagnostic()?;

    // Displays help if no argument is provided.
    if env::args().count() == 1 {
        let help = flags::Xtask::from_vec(vec!["--help".into()]).unwrap_err();
        println!("{help}");
        return Ok(ExitCode::SUCCESS);
    }

    let flags = match flags::Xtask::from_env() {
        Ok(flags) => flags,
        Err(err) if err.is_help() => {
            println!("{err}");
            return Ok(ExitCode::SUCCESS);
        }
        Err(err) => {
            error!("{err}");
            return Ok(ExitCode::FAILURE);
        }
    };

    match flags.subcommand {
        flags::XtaskCmd::Mrproper(command) => command.run(),

        // Server
        flags::XtaskCmd::BuildServer(command) => command.run(),
        flags::XtaskCmd::CleanServer(command) => command.run(),

        // Grammar
        flags::XtaskCmd::GenerateGrammar(command) => command.run(),
        flags::XtaskCmd::CleanGrammar(command) => command.run(),

        // Vscodium
        flags::XtaskCmd::BuildVscodium(command) => command.run(),

        // Wasi
        flags::XtaskCmd::Wasi(command) => match command.subcommand {
            flags::WasiCmd::DownloadSdk(subcommand) => subcommand.run(),
            flags::WasiCmd::UpdateSdk(subcommand) => subcommand.run(),
            flags::WasiCmd::CleanSdk(subcommand) => subcommand.run()
        }
    }
}
