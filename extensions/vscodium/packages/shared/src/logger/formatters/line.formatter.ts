import type { LogFormatter, LogFormatterOutput, LogRecord } from '../index.js';

/**
 * Formats log record as a string line in its most classic form.
 */
export class LineFormatter implements LogFormatter {
  public format(record: LogRecord): LogFormatterOutput {
    return [record.message, record.metadata];
  }
}
