/**
 * Defines absolute minimum for a generic editor command implementation.
 */
export interface Command {
  /**
   * Name associated with the command.
   */
  name: string;

  /**
   * Executes the editor command asynchronously/synchronously.
   *
   * @param args The arguments provided to the command for execution purposes.
   */
  execute(...args: unknown[]): Promise<void> | void;
}

export { CommandsService } from './commands.service';
