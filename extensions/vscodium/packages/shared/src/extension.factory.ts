import type { ExtensionContext } from 'vscode';

import { window } from 'vscode';

import { LineFormatter, LoggerService } from './logger/index.js';
import {
  CommandsService,
  ExtensionContextService,
  ExtensionNameService,
  LogOutputChannelService,
  type ExtensionFactoryOptions,
  type ExtensionOptions
} from './index.js';
import { Extension } from './extension.js';
import { ExtensionError } from './extension.error.js';
import { Container } from './container/index.js';
import { ConfigService } from './config/index.js';

export const defaultOptions: ExtensionFactoryOptions = {
  extensionName: 'pfconf-ls',
  builtinServices: true,
  logOutputChannel: {
    name: 'Packet Filter Configuration Language Server'
  },
  logger: {
    formatter: new LineFormatter()
  }
};

// eslint-disable-next-line @typescript-eslint/no-extraneous-class
export class ExtensionFactory {
  /**
   * Creates an initialized extension instance using provided
   * @param setupOptions
   * @returns
   */
  public static create(setupOptions: ExtensionFactoryOptions): Extension {
    const options = {
      ...defaultOptions,
      ...setupOptions
    } as ExtensionOptions;
    const { extensionName, context } = options;

    if (Extension.hasContainer()) {
      throw new ExtensionError(
        'Extension container has already been initialized. Did you `deactivate()` the previous extension instance?'
      );
    }

    // Since the extension context is the only option that can't be provided in
    // default options: we make sure it has been provided.
    // eslint-disable-next-line @typescript-eslint/no-unnecessary-condition
    if (!context) {
      throw new ExtensionError(
        `Extension context is a requirement and must be provided using the 'context' option key.`
      );
    }

    Extension.setContainer(new Container());
    Extension.registerService(ExtensionNameService, extensionName);
    const extension = new Extension(options);

    if (options.builtinServices) {
      this.registerBuiltinServices(options);
    }

    return extension;
  }

  /**
   * Registers default framework services to the extension service container.
   * This step can be skipped by setting `builtinServices` option to false.
   *
   * @param extension Extension to register built-in services on.
   * @param options Extension options.
   */
  public static registerBuiltinServices(options: ExtensionOptions): void {
    this.registerConfigurationService();
    this.registerExtensionContextService(options.context);
    this.registerLogOutputChannelService(options.logOutputChannel);
    this.registerLoggerService(options.logger);
    this.registerCommandsService();
  }

  /**
   * Registers extension context globally.
   *
   * @param context Extension context to be registered as a service.
   */
  public static registerExtensionContextService(
    context: ExtensionContext
  ): void {
    Extension.registerService(ExtensionContextService, context);
  }

  /**
   * Registers configuration service globally.
   */
  public static registerConfigurationService(): void {
    Extension.registerService(ConfigService, new ConfigService());
  }

  /**
   * Registers output channel service to the extension service container.
   *
   * This static method is public, so developers who opted out of built-in
   * service automatic registration can register the output channel service
   * individually.
   *
   * @param extension Extension to register output channel service on.
   * @param options Output channel service options.
   */
  public static registerLogOutputChannelService(
    options: ExtensionOptions['logOutputChannel']
  ): void {
    Extension.registerService(
      LogOutputChannelService,
      window.createOutputChannel(options.name, { log: true })
    );
  }

  /**
   * Registers logger service to the extension service container.
   *
   * This static method is public, so developers who opted out of built-in
   * service automatic registration can register the logger service individually.
   *
   * @param extension Extension to register logger service on.
   * @param options Logger service options.
   */
  public static registerLoggerService(
    options: ExtensionOptions['logger']
  ): void {
    Extension.registerService(LoggerService, new LoggerService(options));
  }

  /**
   * Registers command service with service container.
   */
  public static registerCommandsService(): void {
    Extension.registerService(CommandsService, new CommandsService());
  }
}
