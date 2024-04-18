import { LogLevel, env } from 'vscode';

import type { LogFormatter, LogRecord } from './log.interface';

export const levelLabels = {
  [LogLevel.Off]: '?',
  [LogLevel.Error]: 'Error',
  [LogLevel.Warning]: 'Warning',
  [LogLevel.Info]: 'Info',
  [LogLevel.Debug]: 'Debug',
  [LogLevel.Trace]: 'Trace'
};

export class LineFormatter implements LogFormatter {
  public format(record: LogRecord): string {
    let line = `[${levelLabels[record.level]} - ${new Date().toLocaleTimeString(env.language)}] ${record.message}`;
    if (record.context.length) {
      line = line.concat(`\n  Context: ${JSON.stringify(record.context)}`);
    }
    return line;
  }
}
