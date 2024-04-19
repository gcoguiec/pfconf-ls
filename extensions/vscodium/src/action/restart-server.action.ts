import { LanguageClient } from 'vscode-languageclient/node';

import type { Action } from './action.interface';

import { LogService } from '../log/log.service';
import { ContainerService } from '../container/container.service';

export class RestartServerAction implements Action {
  public name: string = 'pfconf-ls.action.restartServer';

  public async execute(): Promise<void> {
    const log = ContainerService.inject(LogService);
    const client = ContainerService.inject(LanguageClient);

    if (client.isRunning()) {
      await client.stop();
    }

    log.flush();
    log.info('Restarting server.', [this.name]);
    await client.start();
    if (!client.isRunning()) {
      log.error('Restarting server failed.', [this.name]);
    }
  }
}
