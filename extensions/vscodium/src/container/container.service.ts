import { Disposable } from 'vscode';
import { ServiceToken } from './container.interface';

export function isServiceDisposable(object: any): object is Disposable {
  return 'dispose' in object;
}

export class ContainerService implements Disposable {
  protected _registry: Map<ServiceToken, any> = new Map();

  public has(token: ServiceToken<any>): boolean {
    return this._registry.has(token);
  }

  public inject(token: ServiceToken<any>): any | undefined {
    return this._registry.get(token);
  }

  public register<T>(token: ServiceToken<T>, value: T): ContainerService {
    if (this.has(token)) {
      throw new Error(
        `A service instance for '${String(token)}' is already registered.`
      );
    }
    this._registry.set(token, value);
    return this;
  }

  public dispose(): void {
    this._registry.forEach(value => {
      if (!isServiceDisposable(value)) {
        return;
      }
      value.dispose();
    });
    this._registry.clear();
  }
}
