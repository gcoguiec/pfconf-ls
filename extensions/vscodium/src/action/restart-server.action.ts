import { LanguageClient } from 'vscode-languageclient/node';

import type { Action } from './action.interface';

import { ContainerService } from '../container/container.service';

export class RestartServerAction implements Action {
  public name: string = 'pfconf-ls.action.restartServer';

  public async execute(): Promise<void> {
    const client = ContainerService.inject(LanguageClient);
    if (client.isRunning()) {
      await client.stop();
    }
    await client.start();
  }
}
