import type { Disposable } from 'vscode';
import type { Activable } from '@pfconf-ls/shared/src/index.js';

import { MarkdownString, StatusBarAlignment, window } from 'vscode';

import { OpenLogsCommand } from '../commands/open-logs.command.js';

export class StatusBarService implements Activable, Disposable {
  protected bar = window.createStatusBarItem(StatusBarAlignment.Left);

  public render() {
    this.bar.command = new OpenLogsCommand().name;
    this.bar.tooltip = new MarkdownString('', true);
    this.bar.tooltip.isTrusted = true;
    this.bar.text = `pfconf-ls`;
  }

  public activate(): void {
    this.render();
    this.bar.show();
  }

  public dispose(): void {
    this.bar.dispose();
  }
}
