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
        flags::XtaskCmd::GenerateGrammar(command) => Ok(command.run()?),
        flags::XtaskCmd::BuildServer(command) => Ok(command.run()?),
        flags::XtaskCmd::BuildVscodium(command) => Ok(command.run()?),
        flags::XtaskCmd::CleanGrammar(command) => Ok(command.run()?)
    }
}
