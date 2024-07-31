use std::{
    env::{self, VarError},
    ffi::OsString,
    fmt,
    io::{stderr, IsTerminal}
};

use miette::{Diagnostic, Result};
use nu_ansi_term::Color;
use thiserror::Error;
use tracing::{level_filters::LevelFilter, Event, Level, Subscriber};
use tracing_log::{log::SetLoggerError, NormalizeEvent};
use tracing_subscriber::{
    filter::Directive,
    fmt::{format, FmtContext, FormatEvent, FormatFields},
    registry::LookupSpan,
    EnvFilter
};

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
    #[diagnostic(code(pfconf_ls::log::global_registration_failed))]
    GlobalRegistrationFailed(#[from] SetLoggerError)
}

pub struct LoggerConfig {
    pub filter: Result<String, VarError>,
    pub color: Result<String, VarError>
}

impl LoggerConfig {
    pub fn from_env(env: &str) -> Self {
        Self {
            filter: env::var(env),
            color: env::var(format!("{env}_COLOR"))
        }
    }
}

#[derive(Debug)]
pub struct LoggerFormatter;

impl<S, N> FormatEvent<S, N> for LoggerFormatter
where
    S: Subscriber + for<'a> LookupSpan<'a>,
    N: for<'a> FormatFields<'a> + 'static
{
    fn format_event(
        &self,
        ctx: &FmtContext<'_, S, N>,
        mut writer: format::Writer<'_>,
        event: &Event<'_>
    ) -> fmt::Result {
        let normalized_meta = event.normalized_metadata();
        let meta = normalized_meta.as_ref().unwrap_or_else(|| event.metadata());

        // Target
        let target = if writer.has_ansi_escapes() {
            Color::DarkGray
                .paint(format!("[{}]", meta.target()))
                .to_string()
        } else {
            format!("[{}]", meta.target())
        };
        write!(writer, "{}", target)?;
        write!(writer, " ")?;

        // Level
        let level = if writer.has_ansi_escapes() {
            self.format_level(*meta.level())
        } else {
            meta.level().to_string()
        };
        write!(writer, "{}: ", level)?;

        if *meta.level() == Level::ERROR {
            write!(writer, "❌ ")?;
        }

        // Fields
        ctx.field_format().format_fields(writer.by_ref(), event)?;

        if *meta.level() != Level::ERROR {
            return writeln!(writer)
        }
        writeln!(writer)?;
        writeln!(
            writer,
            "You can re-run this task using `XTASK_LOG=debug` for more \
             details."
        )
    }
}

impl LoggerFormatter {
    pub fn format_level(&self, level: Level) -> String {
        let lowercased_level = level.as_str().to_lowercase();
        let painted = match level {
            Level::TRACE => Color::Purple.paint(lowercased_level),
            Level::DEBUG => Color::Blue.paint(lowercased_level),
            Level::INFO => Color::Green.paint(lowercased_level),
            Level::WARN => Color::Yellow.paint(lowercased_level),
            Level::ERROR => Color::Red.paint(lowercased_level)
        };
        painted.to_string()
    }
}

pub fn init_logger(config: LoggerConfig) -> Result<(), LoggerError> {
    let filter = match config.filter {
        Ok(env) => EnvFilter::new(env),
        _ => EnvFilter::default()
            .add_directive(Directive::from(LevelFilter::INFO))
    };

    let has_color = match config.color {
        Ok(value) => match value.as_ref() {
            "always" => true,
            "never" => false,
            "auto" => stderr().is_terminal(),
            _ => return Err(LoggerError::InvalidColorValue(value))
        },
        Err(VarError::NotPresent) => stderr().is_terminal(),
        Err(VarError::NotUnicode(value)) => {
            return Err(LoggerError::NonUnicodeColorValue(value))
        }
    };

    tracing_subscriber::fmt()
        .with_env_filter(filter)
        .with_writer(std::io::stderr)
        .with_ansi(has_color)
        .event_format(LoggerFormatter)
        .init();

    if let Err(error) = tracing_log::LogTracer::init() {
        return Err(LoggerError::GlobalRegistrationFailed(error))
    }
    Ok(())
}
