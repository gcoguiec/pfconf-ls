import { commands } from 'vscode';

import type { Command } from '.';

import { ExtensionError } from '../extension.error';
import { Extension } from '../extension';
import { ExtensionContextService } from '../container';

export class CommandsService {
  protected _commands: Record<string, Command> = {};

  protected readonly _context = Extension.injectService(
    ExtensionContextService
  );

  /**
   * Registers a command with the editor.
   *
   * @param command The command definition to be added.
   */
  public add(command: Command): void {
    if (this._commands[command.name]) {
      throw new ExtensionError(
        `Command '${command.name}' is already registered.`
      );
    }
    this._context.subscriptions.push(
      // Method's `this` context is bound by the third argument.
      // eslint-disable-next-line @typescript-eslint/unbound-method
      commands.registerCommand(command.name, command.execute, command)
    );
  }
}
