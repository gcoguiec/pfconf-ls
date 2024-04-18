import type { ConfigurationChangeEvent } from 'vscode';

import { workspace } from 'vscode';

export const section = 'pfconf-ls';

export function getConfiguration(key: string) {
  return workspace.getConfiguration(section).get(key);
}

export function affectsConfiguration(
  event: ConfigurationChangeEvent,
  key: string
) {
  return event.affectsConfiguration(`${section}.${key}`);
}
