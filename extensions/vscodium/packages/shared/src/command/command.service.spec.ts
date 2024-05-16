import type { Disposable, ExtensionContext } from 'vscode';
import type { Mock } from 'vitest';

import { commands } from 'vscode';
import { double } from 'vitest-double';
import {
  afterAll,
  afterEach,
  beforeAll,
  beforeEach,
  describe,
  expect,
  it,
  vi
} from 'vitest';

import type { Command } from '../index.js';

import { CommandsService } from './commands.service.js';
import { Extension, ExtensionContextService } from '../index.js';
import { Container } from '../container/container.js';

describe(CommandsService.name, () => {
  let subject: CommandsService;
  let container: Container;
  let context: ExtensionContext;

  beforeAll(() => {
    context = double<ExtensionContext>({
      subscriptions: []
    });
    container = new Container();
    container.register(ExtensionContextService, context);
    Extension.setContainer(container);
  });

  afterAll(() => {
    Extension.incinerateContainer();
  });

  beforeEach(() => {
    subject = new CommandsService();
  });

  afterEach(() => {
    vi.resetAllMocks();
  });

  describe('add()', () => {
    let command: Command;

    beforeEach(() => {
      command = double({
        name: 'my-command',
        execute: vi.fn()
      });
    });

    describe('when command was already registered', () => {
      beforeEach(() => {
        subject.add(command);
      });

      it('raises an error', () => {
        expect(() => {
          subject.add(command);
        }).toThrowError(`Command '${command.name}' is already registered.`);
      });
    });

    describe('when command was not already registered', () => {
      const disposable = double<Disposable>();

      beforeEach(() => {
        (commands.registerCommand as Mock).mockReturnValueOnce(disposable);
        subject.add(command);
      });

      it('registers command instance', () => {
        expect(subject['_commands']).toHaveProperty(command.name);
      });

      it('adds it to extension disposables', () => {
        expect(commands.registerCommand).toHaveBeenCalledWith(
          command.name,
          expect.any(Function),
          command
        );
        expect(context.subscriptions).toContain(disposable);
      });
    });

    describe('when command callback is executed', () => {
      beforeEach(() => {
        subject.add(command);
        const args = (
          commands.registerCommand as Mock<
            Parameters<typeof commands.registerCommand>
          >
        ).mock.calls.at(-1);
        // eslint-disable-next-line @typescript-eslint/no-unsafe-call
        args?.at(1)(); // The callback is positioned as second parameter.
      });

      it('calls command `execute` method', () => {
        expect(command.execute).toHaveBeenCalledOnce();
      });
    });
  });
});
