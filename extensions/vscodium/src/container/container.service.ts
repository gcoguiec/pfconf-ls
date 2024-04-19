import type { Disposable } from 'vscode';

import type { ServiceToken } from './container.interface';

// eslint-disable-next-line @typescript-eslint/no-explicit-any
export function isServiceDisposable(object: any): object is Disposable {
  return 'dispose' in object;
}

// eslint-disable-next-line @typescript-eslint/no-extraneous-class
export class ContainerService {
  protected static _registry = new Map<ServiceToken, unknown>();

  public static has<T>(token: ServiceToken<T>): boolean {
    return this._registry.has(token);
  }

  public static inject<T>(token: ServiceToken<T>): Readonly<T> {
    if (!this._registry.has(token)) {
      throw Error(
        `Could not inject service '${String(token)}'. Did you register it?`
      );
    }
    return this._registry.get(token) as Readonly<T>;
  }

  public static register<T>(token: ServiceToken<T>, value: T) {
    if (this.has(token)) {
      throw new Error(
        `A service instance for '${String(token)}' is already registered.`
      );
    }
    this._registry.set(token, value);
  }

  public static dispose(): void {
    this._registry.forEach(service => {
      if (!isServiceDisposable(service)) {
        return;
      }
      service.dispose();
    });
    this._registry.clear();
  }
}
