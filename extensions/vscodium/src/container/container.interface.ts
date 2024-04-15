export type ServiceToken<T = any> =
  | {
      new (...args: any[]): T;
    }
  | string
  | symbol;

export const ExtensionContextService: ServiceToken =
  Symbol('extension-context');

export const OutputChannelService: ServiceToken = Symbol('output-channel');

export const WindowService: ServiceToken = Symbol('window');
