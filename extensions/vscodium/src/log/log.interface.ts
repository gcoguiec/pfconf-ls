import type { LogLevel } from 'vscode';

export interface LogRecord {
  level: LogLevel;
  message: string;
  context: string[];
}

export interface LogFormatter {
  format(record: LogRecord): string;
}
