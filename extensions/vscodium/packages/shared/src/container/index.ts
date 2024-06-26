import type { Disposable } from 'vscode';

import type { Activable } from '../index.js';

// eslint-disable-next-line @typescript-eslint/no-explicit-any
export type Constructable<T> = new (...args: any[]) => T;

export type ServiceToken<T = unknown> = Constructable<T> | string | symbol;

// eslint-disable-next-line @typescript-eslint/no-explicit-any
export function isServiceDisposable(object: any): object is Disposable {
  return 'dispose' in object;
}

// eslint-disable-next-line @typescript-eslint/no-explicit-any
export function isServiceActivable(object: any): object is Activable {
  return 'activate' in object;
}

export function tokenToStr<T>(token: ServiceToken<T>): string {
  return typeof token === 'object' || typeof token === 'function'
    ? token.name
    : String(token);
}

export * from './container.error.js';
export * from './container.js';
