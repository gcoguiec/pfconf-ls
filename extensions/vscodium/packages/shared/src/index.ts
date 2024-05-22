import type { ExtensionContext, LogOutputChannel } from 'vscode';

import type { LoggerServiceOptions } from './logger/index.js';
import type { ServiceToken } from './container/index.js';

/**
 * Holds options for an Extension instance.
 */
export interface ExtensionOptions {
  /**
   * Extension name, mostly used as a scope for editor/workspace configuration.
   */
  extensionName: string;

  /**
   * VScode's extension context (usually provided by the `activate` extension lifecycle
   * callback)
   */
  context: ExtensionContext;

  /**
   * Registers built-in services into extension container.
   * Set this option to `false` to disable automatic registration.
   */
  builtinServices: boolean;

  /**
   * Options related to the built-in LogOutputChannelService.
   */
  logOutputChannel: {
    name: string;
  };

  /**
   * Options related to the built-in LoggerService.
   */
  logger: LoggerServiceOptions;
}

/**
 * Holds options for ExtensionFactory.
 */
export type ExtensionFactoryOptions = Partial<ExtensionOptions>;

export interface ExtensionInterface {
  /**
   * Activates extension and its resources.
   */
  activate(): Promise<void> | void;

  /**
   * Deactivates extension and dispose of its resources.
   */
  deactivate(): Promise<void> | void;
}

/**
 * Represents a type which can activate resources.
 */
export interface Activable {
  /**
   * Activates resource related to this object.
   */
  activate(): void;
}

export const LogOutputChannelService: ServiceToken<LogOutputChannel> =
  Symbol('log-output-channel');

export const ExtensionContextService: ServiceToken<ExtensionContext> =
  Symbol('extension-context');

export const ExtensionNameService: ServiceToken<string> =
  Symbol('extension-name');

export * from './config/index.js';
export * from './logger/index.js';
export * from './extension.js';
export * from './container/index.js';
export * from './command/index.js';
export { ExtensionError } from './extension.error.js';
export { ExtensionFactory } from './extension.factory.js';
