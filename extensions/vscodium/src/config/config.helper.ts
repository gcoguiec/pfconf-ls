import type { ConfigurationChangeEvent } from 'vscode';

import { workspace } from 'vscode';

export const section = 'pfconf-ls';

export function getConfiguration<T>(key: string): T | undefined {
  return workspace.getConfiguration(section).get<T>(key);
}

export function affectsConfiguration(
  event: ConfigurationChangeEvent,
  key: string
): boolean {
  return event.affectsConfiguration(`${section}.${key}`);
}
