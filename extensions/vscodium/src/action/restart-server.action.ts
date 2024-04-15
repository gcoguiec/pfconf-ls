import { Action } from './action.interface';
import { ContainerService } from '../container/container.service';
import { OutputChannelService } from '../container/container.interface';

export class RestartServerAction implements Action {
  public name: string = 'pfconf-ls.action.restartServer';

  public execute(container: ContainerService): void {
    container.inject(OutputChannelService)?.appendLine('restart server');
  }
}
