import type { Action } from './action.interface';

import { LogService } from '../log/log.service';
import { ContainerService } from '../container/container.service';

export class RestartServerAction implements Action {
  public name: string = 'pfconf-ls.action.restartServer';

  protected readonly _log = ContainerService.inject(LogService);

  public execute(): void {
    this._log.info('Restarting server.', [this.name]);
  }
}
