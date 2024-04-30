import type { ExtensionContext } from 'vscode';

import {
  CommandsService,
  Extension,
  ExtensionFactory
} from '@pfconf-ls/shared';

import { OpenLogsCommand } from './commands/open-logs.command';

export let extension: Extension;

export function activate(
  context: ExtensionContext
): Thenable<void> | undefined {
  extension = ExtensionFactory.create({ context });

  // Registers extension editor commands.
  const commands = Extension.injectService(CommandsService);
  commands.add(new OpenLogsCommand());

  return extension.activate();
}

export function deactivate(): Thenable<void> | undefined {
  return extension.deactivate();
}
