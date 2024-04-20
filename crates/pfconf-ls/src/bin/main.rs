use std::process::ExitCode;

use lsp_server::{Connection, Message};
use miette::{miette, IntoDiagnostic, Result};

use pfconf_ls::{
    cli::flags,
    log::{init_logger, LoggerConfig},
    thread,
    thread::role::ThreadRole,
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

fn run_lsp_server() -> Result<()> {
    let (connection, io_threads) = Connection::stdio();
    let (initialize_id, initialize_params) = match connection.initialize_start()
    {
        Ok(it) => it,
        Err(e) => {
            if e.channel_is_disconnected() {
                io_threads.join().into_diagnostic()?;
            }
            return Err(miette!("Protocol error: {}", e))
        }
    };
    tracing::info!("InitializeParams: {}", initialize_params);

    handle_lsp_server_loop(connection, initialize_params)?;
    io_threads.join().into_diagnostic()?;

    tracing::info!("Shutting down pfconf-ls server.");
    Ok(())
}

fn handle_lsp_server_loop(
    connection: Connection,
    params: serde_json::Value
) -> Result<()> {
    for message in &connection.receiver {
        match message {
            Message::Request(request) => {
                if connection.handle_shutdown(&request).into_diagnostic()? {
                    return Ok(());
                }
                tracing::info!("Request: {request:?}");
            }
            Message::Response(response) => {
                tracing::info!("Response: {response:?}");
            }
            Message::Notification(notification) => {
                tracing::info!("Notification: {notification:?}");
            }
        }
    }
    Ok(())
}
