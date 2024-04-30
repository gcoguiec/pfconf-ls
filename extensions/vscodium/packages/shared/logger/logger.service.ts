import { LogLevel } from 'vscode';

import type { LogRecord, LoggerServiceOptions } from '.';

import { Extension } from '../extension';
import { ExtensionContextService, LogOutputChannelService } from '../container';
import { ConfigService } from '../config';

export class LoggerService {
  protected _level!: LogLevel;

  protected readonly _output = Extension.injectService(LogOutputChannelService);

  protected readonly _context = Extension.injectService(
    ExtensionContextService
  );

  protected readonly _config = Extension.injectService(ConfigService);

  public constructor(protected readonly options: LoggerServiceOptions) {
    this._output.clear(); // Doesn't seem to do anything? (vscodium@1.88.1)

    this._level = this._config.get<boolean>('trace.extension')
      ? LogLevel.Trace
      : LogLevel.Info;

    this._context.subscriptions.push(
      this._output.onDidChangeLogLevel(this.handleLogLevelChange.bind(this))
    );
  }

  /**
   * Changes the local level when the output channel level is changed.
   *
   * @param level The new log level selected by the end-user.
   */
  protected handleLogLevelChange(level: LogLevel) {
    this.setLevel(
      this._config.get<boolean>('trace.extension') ? LogLevel.Trace : level
    );
  }

  /**
   * Appends a new log record to output channel.
   * Set the log level to `LogLevel.Off` if you want to disable any output
   * channel updates.
   *
   * @param record The log record to be added.
   */
  public addRecord(record: LogRecord): void {
    if (this._level === LogLevel.Off || this._level > record.level) {
      return;
    }
    switch (record.level) {
      case LogLevel.Debug: {
        this._output.debug(...this.options.formatter.format(record));
        return;
      }
      case LogLevel.Error: {
        this._output.error(...this.options.formatter.format(record));
        return;
      }
      case LogLevel.Warning: {
        this._output.warn(...this.options.formatter.format(record));
        return;
      }
      case LogLevel.Trace: {
        this._output.trace(...this.options.formatter.format(record));
        return;
      }
      default: {
        this._output.info(...this.options.formatter.format(record));
      }
    }
  }

  /**
   * Simply sets log level on logger.
   *
   * @param level The desired log level.
   */
  public setLevel(level: LogLevel) {
    this._level = level;
  }
}
