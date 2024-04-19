import type { ServerOptions } from 'vscode-languageclient/node';
import type { LanguageClientOptions } from 'vscode-languageclient';
import type { ExtensionContext, OutputChannel } from 'vscode';

import { LanguageClient } from 'vscode-languageclient/node';
import { window, workspace } from 'vscode';

import { StatusBarService } from './status-bar/status-bar.service';
import { LogService } from './log/log.service';
import { LineFormatter } from './log/line.formatter';
import { ContainerService } from './container/container.service';
import {
  ExtensionContextService,
  OutputChannelService
} from './container/container.interface';
import { RestartServerAction } from './action/restart-server.action';
import { ActionsService } from './action/actions.service';
import { getConfiguration } from './config/config.helper';
import { OpenLogsAction } from './action/open-logs.action';

let client: LanguageClient;

export function activate(extensionContext: ExtensionContext): Thenable<void> {
  const outputChannel: OutputChannel = window.createOutputChannel(
    'Packet Filter Configuration Language Server'
  );

  const serverPath = getConfiguration<string>('server.path');

  if (!serverPath) {
    // @TODO binary bundling, better message handling, etc...
    window.showErrorMessage('Server path must be configured.');
    return Promise.reject();
  }

  const serverOptions: ServerOptions = {
    run: {
      command: serverPath,
      options: {
        env: {
          PFCONFLS_LOG: 'info'
        }
      }
    },
    debug: {
      command: serverPath,
      options: {
        env: {
          PFCONFLS_LOG: 'trace',
          PFCONFLS_LOG_VERBOSE_THREAD: 1
        }
      }
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

  ContainerService.register(ExtensionContextService, extensionContext);
  ContainerService.register(LanguageClient, client);
  ContainerService.register(OutputChannelService, outputChannel);

  const log = new LogService();
  log.formatter = new LineFormatter();
  ContainerService.register(LogService, log);

  // @TODO more status bar love.
  const statusBar = new StatusBarService();
  statusBar.render();

  ContainerService.register(StatusBarService, statusBar);
  ContainerService.register(
    ActionsService,
    new ActionsService()
      .add(new RestartServerAction())
      .add(new OpenLogsAction())
  );

  return client.start();
}

export function deactivate(): Thenable<void> | undefined {
  ContainerService.dispose();
  return client.stop();
}
