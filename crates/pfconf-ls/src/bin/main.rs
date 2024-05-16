use std::process::ExitCode;

use miette::{IntoDiagnostic, Result};

use pfconf_ls::{
    cli::flags,
    log::{init_logger, LoggerConfig},
    lsp::run_lsp_server,
    thread::{self, role::ThreadRole},
    util::is_terminal,
    version::version
};

fn main() -> Result<ExitCode> {
    // Miette hook configuration isn't critical, we allow it to fail.
    let _ = miette::set_hook(Box::new(|_| {
        Box::new(
            miette::MietteHandlerOpts::new()
                .color(is_terminal())
                .terminal_links(true)
                .with_cause_chain()
                .build()
        )
    }));

    init_logger(LoggerConfig::from_env("PFCONFLS_LOG")).into_diagnostic()?;
    let flags = flags::LspServer::from_env_or_exit();
    if flags.version {
        println!(
            "Packet Filter Configuration Language Server\nversion {}",
            version()
        );
        return Ok(ExitCode::SUCCESS);
    }
    let _ = spawn_lsp_server_thread();
    Ok(ExitCode::SUCCESS)
}

fn spawn_lsp_server_thread() -> Result<()> {
    let handle = thread::Builder::new(ThreadRole::LatencySensitiveWorker)
        .name("LSPServer".into())
        .spawn(run_lsp_server)
        .into_diagnostic()?;
    let _ = handle.join();
    Ok(())
}
