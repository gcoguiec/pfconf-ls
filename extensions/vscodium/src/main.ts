import type { ExtensionContext } from 'vscode';
import type { Extension } from '@pfconf-ls/shared';

import { ExtensionFactory } from '@pfconf-ls/shared';

export let extension: Extension;

export function activate(
  context: ExtensionContext
): Thenable<void> | undefined {
  extension = ExtensionFactory.create({ context });

  return extension.activate();
}

export function deactivate(): Thenable<void> | undefined {
  return extension.deactivate();
}
