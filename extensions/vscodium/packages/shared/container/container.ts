import type { Disposable } from 'vscode';

import type { ServiceToken } from '.';

import { ContainerError, isServiceDisposable } from '.';

/**
 * A dependency injection container.
 *
 * No advanced features like scoping, constructor parameters, dynamic
 * services, factories and the like.
 *
 * It's the closest to the most straightforward dependency injection container
 * one could write.
 *
 * The goal is to achieve a low ceremony dependency injection:
 * - No constructor or method injection mechanism; Only target properties are injectable.
 * - No automatic registration; service instance must be registered manually.
 * - No container namespacing; every service instance is global by default.
 * - Symbols or strings as service tokens are allowed to differentiate two instances from the same prototype.
 *
 * Our dependency injector helps implement a minimal inversion of control flow
 * and coherent dependency graph with a considerable engineering tradeoff of not
 * relying on local state storage in services as much as possible (if any) while
 * not moving all the logic into static methods (allowing multiple instances of
 * the same service inside the graph).
 *
 * The quest for simplicity and elegance can make you build unreasonable
 * components and this one of them.
 *
 * @example
 * import { Container, ServiceToken, inject } from '@pfconf-ls/shared';
 *
 * const container = new Container();
 *
 * // Basic service registration case.
 * container.register(GenericService, new GenericService({ optionA: true }));
 *
 * // Unique instance registration case by providing a Symbol or string.
 * const UniqueService: ServiceToken<NotUnique> = Symbol('unique-service'); // could be a string as well
 * container.register(UniqueService, new NotUnique());
 *
 * // Service instances can be fetched from container manually:
 * const generic = container.inject(GenericService);
 * const uniqueService = container.inject(UniqueService);
 *
 * // `inject` property decorator can be used to inject dependencies in place.
 * class Service {
 *   @inject protected readonly generic: GenericService;
 * }
 */
export class Container implements Disposable {
  /**
   * All service instances are injected from this registry.
   */
  protected _registry = new Map<ServiceToken, unknown>();

  /**
   * Checks if container has a specific service instance in its registry.
   *
   * @param token The service prototype/constructor, a symbol or string.
   * @returns boolean
   */
  public has<T>(token: ServiceToken<T>): boolean {
    return this._registry.has(token);
  }

  /**
   * Registers a service instance in the container.
   *
   * @param token The service prototype/constructor, a symbol or a string.
   * @param instance Instance to be associated with the token.
   */
  public register<T>(token: ServiceToken<T>, instance: T): void {
    if (this.has(token)) {
      throw new ContainerError(
        `A service instance for '${String(token)}' is already registered.`
      );
    }
    this._registry.set(token, instance);
  }

  /**
   * Returns instance associated with the service token.
   *
   * @param token The service prototype/constructor, a symbol or a string.
   * @returns Readonly<T>
   */
  public inject<T>(token: ServiceToken<T>): Readonly<T> {
    if (!this.has(token)) {
      throw new ContainerError(
        `Could not inject service '${String(token)}'. Did you register it?`
      );
    }

    return this._registry.get(token) as Readonly<T>;
  }

  /**
   * Disposes container's throwable resources and clear its registry.
   */
  public dispose(): void {
    /**
     * We already track vscode entities for disposal (via the extension context
     * subscriptions) but we still need to dispose services from our micro
     * framework manually.
     */
    this._registry.forEach(service => {
      if (!isServiceDisposable(service)) {
        return;
      }
      service.dispose();
    });
    this._registry.clear();
  }
}
