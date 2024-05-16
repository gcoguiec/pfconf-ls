import type { Command } from '@pfconf-ls/shared/src';

import {
  Extension,
  ExtensionNameService,
  LogOutputChannelService
} from '@pfconf-ls/shared/src';

/**
 * A command that displays and focuses on the extension principal log output
 * channel.
 */
export class OpenLogsCommand implements Command {
  protected readonly _extensionName =
    Extension.injectService(ExtensionNameService);

  protected readonly _output = Extension.injectService(LogOutputChannelService);

  public name: string = `${this._extensionName}.command.openLogs`;

  public execute(): void {
    this._output.show();
  }
}
