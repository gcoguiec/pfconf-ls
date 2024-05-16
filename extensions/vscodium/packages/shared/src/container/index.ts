import type { Disposable, ExtensionContext, LogOutputChannel } from 'vscode';

// eslint-disable-next-line @typescript-eslint/no-explicit-any
export type Constructable<T> = new (...args: any[]) => T;

export type ServiceToken<T = unknown> = Constructable<T> | string | symbol;

export const LogOutputChannelService: ServiceToken<LogOutputChannel> =
  Symbol('log-output-channel');

export const ExtensionContextService: ServiceToken<ExtensionContext> =
  Symbol('extension-context');

export const ExtensionNameService: ServiceToken<string> =
  Symbol('extension-name');

// eslint-disable-next-line @typescript-eslint/no-explicit-any
export function isServiceDisposable(object: any): object is Disposable {
  return 'dispose' in object;
}

export function tokenToStr<T>(token: ServiceToken<T>): string {
  return typeof token === 'object' || typeof token === 'function'
    ? token.name
    : String(token);
}

export * from './container.error.js';
export * from './container.js';
