import type { ConfigurationChangeEvent } from 'vscode';

import { workspace } from 'vscode';

import { ExtensionNameService } from '../index.js';
import { Extension } from '../extension.js';

export class ConfigService {
  protected readonly extensionName: string =
    Extension.injectService(ExtensionNameService);

  /**
   * Returns a configuration value based on its key.
   *
   * @param key The configuration key.
   * @returns The configuration value or undefined if key/value does not exist.
   */
  public get<T>(key: string): T | undefined {
    return workspace.getConfiguration(this.extensionName).get<T>(key);
  }

  /**
   * Checks if configuration affects a specific configuration value.
   *
   * @param event The configuration change event to check against.
   * @param key The configuration setting to be validated.
   */
  public affects(event: ConfigurationChangeEvent, key: string): boolean {
    return event.affectsConfiguration(`${this.extensionName}.${key}`);
  }
}
