import type { ExtensionContext } from 'vscode';

import {
  CommandsService,
  Extension,
  ExtensionFactory
} from '@pfconf-ls/shared/src';

import { StatusBarService } from './ui/status-bar.service.js';
import { OpenLogsCommand } from './commands/open-logs.command.js';

let extension: Extension;

export function activate(context: ExtensionContext) {
  extension = ExtensionFactory.create({ context });

  Extension.registerService(StatusBarService, new StatusBarService());

  // Registers extension editor commands.
  const commands = Extension.injectService(CommandsService);
  commands.add(new OpenLogsCommand());

  extension.activate();
}

export function deactivate() {
  extension.deactivate();
}
