import type { ExtensionContext } from 'vscode';

import {
  CommandsService,
  Extension,
  ExtensionFactory
} from '@pfconf-ls/shared/src';

import { OpenLogsCommand } from './commands/open-logs.command.js';

let extension: Extension;

export function activate(context: ExtensionContext): Promise<void> | undefined {
  extension = ExtensionFactory.create({ context });

  // Registers extension editor commands.
  const commands = Extension.injectService(CommandsService);
  commands.add(new OpenLogsCommand());

  return extension.activate();
}

export function deactivate(): Promise<void> | undefined {
  return extension.deactivate();
}
