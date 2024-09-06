use lsp_server::{Connection, Message};
use lsp_types::{
    SemanticTokenType,
    SemanticTokensFullOptions,
    SemanticTokensLegend,
    SemanticTokensOptions,
    ServerCapabilities
};
use miette::{miette, IntoDiagnostic, Result};

pub fn run_lsp_server() -> Result<()> {
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

    let server_capabilities = ServerCapabilities {
        semantic_tokens_provider: Some(
            SemanticTokensOptions {
                work_done_progress_options: Default::default(),
                legend: SemanticTokensLegend {
                    token_types: vec![SemanticTokenType::COMMENT],
                    token_modifiers: vec![]
                },
                range: Some(false),
                full: Some(SemanticTokensFullOptions::Delta {
                    delta: Some(true)
                })
            }
            .into()
        ),
        ..Default::default()
    };

    let initialize_data = serde_json::json!({
        "capabilities": server_capabilities,
        "serverInfo": {
            "name": "pfconf-ls", // TODO:
            "version": "unknown" // TODO:
        }
    });

    connection
        .initialize_finish(initialize_id, initialize_data)
        .into_diagnostic()?;

    loop_on_lsp_messages(connection, initialize_params)?;
    io_threads.join().into_diagnostic()?;

    tracing::info!("Shutting down pfconf-ls server.");
    Ok(())
}

pub fn loop_on_lsp_messages(
    connection: Connection,
    _params: serde_json::Value
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
