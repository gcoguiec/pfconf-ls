import type { LogFormatter, LogFormatterOutput, LogRecord } from '../index.js';

/**
 * Formats a log record as a JSON string representation.
 */
export class JSONFormatter implements LogFormatter {
  public format(record: LogRecord): LogFormatterOutput {
    const { message, metadata } = record;
    return [JSON.stringify({ message, ...metadata })];
  }
}
