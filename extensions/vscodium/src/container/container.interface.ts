import type { ExtensionContext, OutputChannel } from 'vscode';

export type ServiceToken<T = unknown> =
  | {
      // eslint-disable-next-line @typescript-eslint/no-explicit-any
      new (...args: any[]): T;
    }
  | string
  | symbol;

export const ExtensionContextService: ServiceToken<ExtensionContext> =
  Symbol('extension-context');

export const OutputChannelService: ServiceToken<OutputChannel> =
  Symbol('output-channel');
