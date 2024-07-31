use std::process::ExitCode;

use miette::Result;
use tracing::info;

use crate::cli::{
    flags::{self, GenerateGrammar},
    Command
};

#[derive(Debug, Clone)]
pub enum BuildState {
    Idle,
    GrammarGenerated,
    ServerBuilt,
    ExtensionBuilt,
    Failed { reason: String },
    Completed
}

#[derive(Debug)]
pub enum BuildEvent {
    GenerateGrammar,
    BuildServer
}

impl BuildState {
    pub fn transition(self, event: &BuildEvent) -> Result<BuildState> {
        match (self, event) {
            (Self::Idle, BuildEvent::GenerateGrammar) => {
                GenerateGrammar.run()?;
                Ok(BuildState::GrammarGenerated)
            }
            (..) => todo!()
        }
    }
}

impl Command for flags::BuildVscodium {
    /// Builds vsix extension for VSCodium.
    fn run(&self) -> Result<ExitCode> {
        info!("Building VSCodium Extension.");
        let mut state = BuildState::Idle;
        [BuildEvent::GenerateGrammar]
            .iter()
            .for_each(|event| state = state.clone().transition(event).unwrap());
        info!("✅ Extension built.");
        Ok(ExitCode::SUCCESS)
    }
}
