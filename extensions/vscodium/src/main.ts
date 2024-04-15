import type { ServerOptions } from 'vscode-languageclient/node';
import type { LanguageClientOptions } from 'vscode-languageclient';
import type { ExtensionContext, OutputChannel } from 'vscode';

import { LanguageClient } from 'vscode-languageclient/node';
import { window, workspace } from 'vscode';
import { ContainerService } from './container/container.service';
import { ActionsService } from './action/actions.service';
import { RestartServerAction } from './action/restart-server.action';
import { StatusBarService } from './status-bar/status-bar.service';
import {
  ExtensionContextService,
  OutputChannelService,
  WindowService
} from './container/container.interface';

let client: LanguageClient;

export function activate(extensionContext: ExtensionContext): Thenable<void> {
  const outputChannel: OutputChannel = window.createOutputChannel(
    'Packet Filter Configuration Language Server'
  );

  const serverOptions: ServerOptions = {
    run: {
      command: '/Users/yugo/projects/pfconf-ls/target/debug/pfconf-ls' // @TODO move this to workspace settings
    },
    debug: {
      command: '/Users/yugo/projects/pfconf-ls/target/debug/pfconf-ls' // @TODO move this to workspace settings
    }
  };

  const clientOptions: LanguageClientOptions = {
    documentSelector: [{ scheme: 'file', language: 'pfconf' }],
    diagnosticCollectionName: 'pfconf-ls',
    synchronize: {
      fileEvents: workspace.createFileSystemWatcher('**/pf.conf')
    },
    outputChannel
  };

  client = new LanguageClient(
    'pfconf-ls',
    'Packet Filter Configuration Language Server',
    serverOptions,
    clientOptions
  );

  const container = new ContainerService()
    .register(WindowService, window)
    .register(ExtensionContextService, extensionContext)
    .register(LanguageClient, client)
    .register(OutputChannelService, outputChannel);

  const statusBar = new StatusBarService(container).create();

  statusBar.render();

  container
    .register(StatusBarService, statusBar)
    .register(
      ActionsService,
      new ActionsService(container).add(new RestartServerAction())
    );

  return client.start();
}

export function deactivate(): Thenable<void> | undefined {
  return client?.stop();
}
