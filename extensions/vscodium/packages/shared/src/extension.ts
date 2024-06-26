import type { ExtensionInterface, ExtensionOptions } from './index.js';
import type { Container, ServiceToken } from './container/index.js';

import { ExtensionError } from './extension.error.js';

export class Extension implements ExtensionInterface {
  protected static _container: Container | undefined;

  public constructor(public readonly options: ExtensionOptions) {}

  /**
   * Activates the extension and its components.
   */
  public activate(): void {
    Extension._container?.activate();
  }

  /**
   * Deactivates and cleans up the extension components and resources.
   */
  public deactivate(): void {
    Extension.incinerateContainer();
  }

  /**
   * Registers container instance with the extension.
   *
   * @param container The container to be registered.
   */
  public static setContainer(container: Container): void {
    this._container = container;
  }

  /**
   * Checks if the container is still instantiated or not.
   */
  public static hasContainer(): boolean {
    return !!this._container;
  }

  /**
   * Incinerates container and its disposable services.
   */
  public static incinerateContainer(): void {
    Extension._container?.dispose();
    Extension._container = undefined;
  }

  /**
   * Registers a service instance against the container.
   * Service instances can be retrieved via `Extension::injectService` static method.
   *
   * @param token The token to register the service at.
   * @param instance The service instance that will be registered with its associated token.
   */
  public static registerService<T>(token: ServiceToken<T>, instance: T): void {
    this._container?.register(token, instance);
  }

  /**
   * Injects a service instance from the container.
   *
   * @param token The service token to be injected.
   * @returns The service instance stored inside container registry.
   */
  public static injectService<T>(token: ServiceToken<T>): Readonly<T> {
    if (!this._container) {
      throw new ExtensionError(
        'Cannot inject a service from an uninitialized container.'
      );
    }
    return this._container.inject(token);
  }
}
