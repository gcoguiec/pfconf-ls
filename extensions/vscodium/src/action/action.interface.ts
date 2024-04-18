export interface Action {
  name: string;
  execute(...args: unknown[]): void;
}
