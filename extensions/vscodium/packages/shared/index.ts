import type { ExtensionContext } from 'vscode';

import type { LoggerServiceOptions } from './logger';

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
  activate(): Promise<void>;

  /**
   * Deactivates extension and dispose of its resources.
   */
  deactivate(): Promise<void>;
}

export * from './config';
export * from './logger';
export * from './extension';
export * from './container';
export { ExtensionError } from './extension.error';
export { ExtensionFactory } from './extension.factory';
