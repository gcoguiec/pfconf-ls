import type { LogLevel as VscodeLogLevel } from 'vscode';

/**
 * Log levels (identical to VSCode's).
 */
export type LogLevel = VscodeLogLevel;

/**
 * This interface defines minimal requirements for a logger implementation.
 */
export interface LoggerInterface {
  /**
   * Writes a log record with an ERROR level.
   *
   * @param message The log record message.
   * @param metadata Additional contextual metadata to push with the log record.
   */
  error(message: string, metadata?: Record<string, unknown>): void;

  /**
   * Writes a log record with an WARNING level.
   *
   * @param message The log record message.
   * @param metadata Additional contextual metadata to push with the log record.
   */
  warn(message: string, metadata?: Record<string, unknown>): void;

  /**
   * Writes a log record with an INFO level.
   *
   * @param message The log record message.
   * @param metadata Additional contextual metadata to push with the log record.
   */
  info(message: string, metadata?: Record<string, unknown>): void;

  /**
   * Writes a log record with an DEBUG level.
   *
   * @param message The log record message.
   * @param metadata Additional contextual metadata to push with the log record.
   */
  debug(message: string, metadata?: Record<string, unknown>): void;

  /**
   * Writes a log record with an TRACE level.
   *
   * @param message The log record message.
   * @param metadata Additional contextual metadata to push with the log record.
   */
  trace(message: string, metadata: Record<string, unknown>): void;
}

/**
 * Holds log record information.
 */
export interface LogRecord {
  /**
   * A log record can be routed through other means than simply writing it to
   * standard output; that's why we want to retain the record's level information
   * with its message.
   */
  level: LogLevel;

  /**
   * This one should be fine without an explanation, as the reader knows that
   * majority of loggers provide a way to send a message or an error somehow.
   */
  message: string;

  /**
   * Additional contextual metadata associated with the log record.
   * Please note the assigned log formatter is most likely to stringify
   * the metadata in JSON format.
   */
  metadata: Record<string, unknown>;
}

// eslint-disable-next-line @typescript-eslint/no-explicit-any
export type LogFormatterOutput = [string, ...args: any[]];

/**
 * Essentials for a log formatter implementation.
 */
export interface LogFormatter {
  /**
   * Formats a log record so it's consumable by an OutputChannel.
   *
   * @param record The log record to be formatted.
   */
  format(record: LogRecord): LogFormatterOutput;
}

/**
 * Options for the logger service.
 */
export interface LoggerServiceOptions {
  /**
   * Configure a formatter to transform the log record before appending it to
   * the destination output channel.
   */
  formatter: LogFormatter;
}

export { LineFormatter } from './formatters/line.formatter';
export { JSONFormatter } from './formatters/json.formatter';
export * from './logger.service';
