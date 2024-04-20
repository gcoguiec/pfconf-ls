import type { ConfigurationChangeEvent } from 'vscode';

import { LogLevel, env, window, workspace } from 'vscode';

import type { LogFormatter, LogRecord } from './log.interface';

import {
  affectsConfiguration,
  getConfiguration
} from '../config/config.helper';
import { ContainerService } from '../container/container.service';
import { ExtensionContextService } from '../container/container.interface';

export class LogService {
  protected _level = getConfiguration('trace.extension')
    ? LogLevel.Trace
    : LogLevel.Info;

  protected readonly extensionContext = ContainerService.inject(
    ExtensionContextService
  );

  public readonly outputChannel = window.createOutputChannel(
    'Packet Filter Configuration Language Server'
  );

  public constructor(public readonly formatter: LogFormatter) {
    this.extensionContext.subscriptions.push(
      env.onDidChangeLogLevel(this.handleLogLevelChange.bind(this))
    );
    this.extensionContext.subscriptions.push(
      workspace.onDidChangeConfiguration(
        this.handleConfigurationChange.bind(this)
      )
    );
  }

  protected addRecord(record: LogRecord): void {
    if (this._level === LogLevel.Off || this._level > record.level) {
      return;
    }
    this.outputChannel.appendLine(this.formatter.format(record));
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
    this.outputChannel.clear();
  }
}
