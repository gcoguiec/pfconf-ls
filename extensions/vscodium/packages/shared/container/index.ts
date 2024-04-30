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

export * from './container.error';
export * from './container';
