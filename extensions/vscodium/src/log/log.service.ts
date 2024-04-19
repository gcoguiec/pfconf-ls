import type { ConfigurationChangeEvent, Disposable } from 'vscode';

import { LogLevel, env, workspace } from 'vscode';

import type { LogFormatter, LogRecord } from './log.interface';

import { ContainerService } from '../container/container.service';
import { OutputChannelService } from '../container/container.interface';
import {
  affectsConfiguration,
  getConfiguration
} from '../config/config.helper';

export class LogService implements Disposable {
  protected _level = LogLevel.Info;

  protected _disposables: Disposable[] = [];

  protected readonly _outputChannel =
    ContainerService.inject(OutputChannelService);

  public formatter?: LogFormatter;

  public constructor() {
    this.setLevel(
      getConfiguration('trace.extension') ? LogLevel.Trace : env.logLevel
    );
    this._disposables.push(
      env.onDidChangeLogLevel(this.handleLogLevelChange.bind(this))
    );
    this._disposables.push(
      workspace.onDidChangeConfiguration(
        this.handleConfigurationChange.bind(this)
      )
    );
  }

  protected addRecord(record: LogRecord): void {
    if (this._level === LogLevel.Off || this._level > record.level) {
      return;
    }
    if (!this.formatter) {
      throw new Error('A formatter was not set for the Log service.');
    }
    this._outputChannel.appendLine(this.formatter.format(record));
  }

  protected handleLogLevelChange(level: LogLevel) {
    if (getConfiguration('trace.extension')) {
      return;
    }
    this.setLevel(level);
  }

  protected handleConfigurationChange(event: ConfigurationChangeEvent) {
    if (!affectsConfiguration(event, 'trace.extension')) {
      return;
    }
    this.setLevel(
      getConfiguration('trace.extension') ? LogLevel.Trace : env.logLevel
    );
  }

  public setLevel(level: LogLevel) {
    this._level = level;
  }

  public error(message: string, context: string[] = []): void {
    this.addRecord({
      level: LogLevel.Error,
      message,
      context
    });
  }

  public warn(message: string, context: string[] = []): void {
    this.addRecord({
      level: LogLevel.Warning,
      message,
      context
    });
  }

  public info(message: string, context: string[] = []): void {
    this.addRecord({
      level: LogLevel.Info,
      message,
      context
    });
  }

  public debug(message: string, context: string[] = []): void {
    this.addRecord({
      level: LogLevel.Debug,
      message,
      context
    });
  }

  public trace(message: string, context: string[] = []): void {
    this.addRecord({
      level: LogLevel.Trace,
      message,
      context
    });
  }

  public flush() {
    this._outputChannel.clear();
  }

  public dispose(): void {
    this._disposables.forEach(disposable => {
      disposable.dispose();
    });
  }
}
