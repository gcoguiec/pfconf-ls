import { commands } from 'vscode';

import type { Action } from './action.interface';

import { ContainerService } from '../container/container.service';
import { ExtensionContextService } from '../container/container.interface';

export class ActionsService {
  protected _actions: Record<string, Action> = {};

  protected readonly extensionContext = ContainerService.inject(
    ExtensionContextService
  );

  public add(action: Action): this {
    if (this._actions[action.name]) {
      throw new Error(`Action '${action.name}' is already registered.`);
    }
    this._actions[action.name] = action;
    this.extensionContext.subscriptions.push(
      commands.registerCommand(
        action.name,
        action.execute.bind({ name: action.name })
      )
    );
    return this;
  }
}
