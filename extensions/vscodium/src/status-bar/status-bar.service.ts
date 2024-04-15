import { MarkdownString, StatusBarAlignment, StatusBarItem } from 'vscode';
import { ContainerService } from '../container/container.service';
import { Disposable } from 'vscode-languageclient';
import { WindowService } from '../container/container.interface';
import { RestartServerAction } from '../action/restart-server.action';

export class StatusBarService implements Disposable {
  protected statusBar!: StatusBarItem;

  public constructor(protected readonly container: ContainerService) {}

  public create(): StatusBarService {
    this.statusBar = this.container
      .inject(WindowService)
      ?.createStatusBarItem(StatusBarAlignment.Left);
    return this;
  }

  public render() {
    this.statusBar.show();
    this.statusBar.tooltip = new MarkdownString('', true);
    this.statusBar.tooltip.isTrusted = true;
    this.statusBar.tooltip.appendMarkdown(
      `\n\n[Restart server](command:${new RestartServerAction().name})`
    );
    this.statusBar.text = `pfconf-ls`;
  }

  public dispose(): void {
    this.statusBar?.dispose();
  }
}
