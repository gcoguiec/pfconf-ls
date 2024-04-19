export interface Action {
  name: string;
  execute(...args: unknown[]): Promise<void> | void;
}
