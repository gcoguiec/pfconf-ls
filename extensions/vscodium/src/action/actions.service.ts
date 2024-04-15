import { commands } from 'vscode';
import { Action } from './action.interface';
import { ContainerService } from '../container/container.service';
import { ExtensionContextService } from '../container/container.interface';

export class ActionsService {
  protected _actions: Record<string, Action> = {};

  public constructor(protected readonly container: ContainerService) {}

  public add(action: Action): ActionsService {
    if (this._actions[action.name]) {
      throw new Error(`Action '${action.name}' is already registered.`);
    }
    this._actions[action.name] = action;
    this.container
      .inject(ExtensionContextService)
      .subscriptions.push(
        commands.registerCommand(action.name, (...args: any[]): any =>
          action.execute(this.container, ...args)
        )
      );
    return this;
  }
}
