import { commands } from 'vscode';

import type { Command } from './index.js';

import { Extension } from '../extension.js';
import { ExtensionError } from '../extension.error.js';
import { ExtensionContextService } from '../container/index.js';

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
    this._commands[command.name] = command;
    this._context.subscriptions.push(
      commands.registerCommand(
        command.name,
        async () => {
          await command.execute();
        },
        command
      )
    );
  }
}
