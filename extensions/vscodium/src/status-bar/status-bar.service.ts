import type { Disposable } from 'vscode-languageclient';
import type { StatusBarItem } from 'vscode';

import { MarkdownString, StatusBarAlignment, window } from 'vscode';

import { RestartServerAction } from '../action/restart-server.action';
import { OpenLogsAction } from '../action/open-logs.action';

export class StatusBarService implements Disposable {
  protected statusBar!: StatusBarItem;

  public constructor() {
    this.statusBar = window.createStatusBarItem(StatusBarAlignment.Left);
  }

  public render() {
    this.statusBar.hide();
    this.statusBar.command = new OpenLogsAction().name;
    this.statusBar.tooltip = new MarkdownString('', true);
    this.statusBar.tooltip.isTrusted = true;
    this.statusBar.tooltip.appendMarkdown(
      `\n\n[Restart server](command:${new RestartServerAction().name})`
    );
    this.statusBar.text = `pfconf-ls`;
    this.statusBar.show();
  }

  public dispose(): void {
    this.statusBar.dispose();
  }
}
