import { OutputChannelService } from '../container/container.interface';
import { ContainerService } from '../container/container.service';
import type { Action } from './action.interface';

export class OpenLogsAction implements Action {
  public name: string = 'pfconf-ls.action.openLogs';

  public execute(): void {
    ContainerService.inject(OutputChannelService).show();
  }
}
