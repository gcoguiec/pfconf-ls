use std::{
    env::{self, VarError},
    ffi::OsString
};

use thiserror::Error;
use tracing::level_filters::LevelFilter;
use tracing_log::log::SetLoggerError;
use tracing_subscriber::filter::{Directive, EnvFilter};

use miette::{Diagnostic, Result};

use crate::util::is_terminal;

#[derive(Debug, Error, Diagnostic)]
pub enum LoggerError {
    #[error(
        "Unknown logger color option value '{0}': expected always, never or \
         auto."
    )]
    #[diagnostic(code(pfconf_ls::log::invalid_color_value))]
    InvalidColorValue(String),

    #[error(
        "Non-Unicode logger color option value '{0:?}': expected always, \
         never or auto."
    )]
    #[diagnostic(code(pfconf_ls::log::non_unicode_color_value))]
    NonUnicodeColorValue(OsString),

    #[error(transparent)]
    #[diagnostic(code(pfconf_ls::log::global_logger_registration_failed))]
    GlobalLoggerRegistrationFailed(#[from] SetLoggerError)
}

pub struct LoggerConfig {
    pub filter: Result<String, VarError>,
    pub color: Result<String, VarError>,
    pub verbose_thread: Result<String, VarError>
}

impl LoggerConfig {
    pub fn from_env(env: &str) -> Self {
        Self {
            filter: env::var(env),
            color: env::var(format!("{env}_COLOR")),
            verbose_thread: env::var(format!("{env}_VERBOSE_THREAD"))
        }
    }
}

pub fn init_logger(config: LoggerConfig) -> Result<(), LoggerError> {
    let filter = match config.filter {
        Ok(env) => EnvFilter::new(env),
        _ => EnvFilter::default()
            .add_directive(Directive::from(LevelFilter::WARN))
    };

    let has_color = match config.color {
        Ok(value) => match value.as_ref() {
            "always" => true,
            "never" => false,
            "auto" => is_terminal(),
            _ => return Err(LoggerError::InvalidColorValue(value))
        },
        Err(VarError::NotPresent) => is_terminal(),
        Err(VarError::NotUnicode(value)) => {
            return Err(LoggerError::NonUnicodeColorValue(value))
        }
    };

    let has_verbose_thread = match config.verbose_thread {
        Ok(value) => &value == "1",
        Err(_) => false
    };

    tracing_subscriber::fmt()
        .with_env_filter(filter)
        .with_writer(std::io::stderr)
        .with_ansi(has_color)
        .event_format(
            tracing_subscriber::fmt::format()
                .with_target(true)
                .with_thread_names(has_verbose_thread)
                .compact()
        )
        .init();

    if let Err(error) = tracing_log::LogTracer::init() {
        return Err(LoggerError::GlobalLoggerRegistrationFailed(error))
    }
    Ok(())
}
