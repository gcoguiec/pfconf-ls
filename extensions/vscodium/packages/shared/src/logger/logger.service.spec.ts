import type { Disposable, ExtensionContext, LogOutputChannel } from 'vscode';
import type { Mock } from 'vitest';

import { LogLevel } from 'vscode';
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

import type {
  LogFormatter,
  LogRecord,
  LoggerServiceOptions
} from '../index.js';

import {
  ConfigService,
  Container,
  Extension,
  ExtensionContextService,
  JSONFormatter,
  LogOutputChannelService,
  LoggerService
} from '../index.js';

describe(LoggerService.name, () => {
  let container: Container;
  let subject: LoggerService;
  let output: LogOutputChannel;
  let config: ConfigService;
  let context: ExtensionContext;

  function buildSubject(options: Partial<LoggerServiceOptions> = {}) {
    return new LoggerService({
      formatter: new JSONFormatter(),
      ...options
    });
  }

  beforeAll(() => {
    output = double<LogOutputChannel>({
      clear: vi.fn(),
      onDidChangeLogLevel: vi.fn(),
      trace: vi.fn(),
      debug: vi.fn(),
      info: vi.fn(),
      warn: vi.fn(),
      error: vi.fn()
    });
    config = double<ConfigService>({
      get: vi.fn()
    });
    context = double<ExtensionContext>({
      subscriptions: []
    });
    container = new Container();
    container.register(LogOutputChannelService, output);
    container.register(ConfigService, config);
    container.register(ExtensionContextService, context);
    Extension.setContainer(container);
  });

  afterAll(() => {
    Extension.incinerateContainer();
  });

  afterEach(() => {
    vi.resetAllMocks();
  });

  describe('constructor()', () => {
    describe('when extension tracing is not enabled', () => {
      beforeEach(() => {
        (config.get as Mock).mockImplementation((key: string) => {
          return key === 'trace.extension' ? false : undefined;
        });
        subject = buildSubject();
      });

      it('sets log level to `info`', () => {
        expect(subject['_level']).toBe(LogLevel.Info);
      });
    });

    describe('when extension tracing is enabled', () => {
      beforeEach(() => {
        (config.get as Mock).mockImplementation((key: string) => {
          return key === 'trace.extension' ? true : undefined;
        });
        subject = buildSubject();
      });

      it('sets log level to `trace`', () => {
        expect(subject['_level']).toBe(LogLevel.Trace);
      });
    });

    it('registers a disposable didChangeLogLevel handler into extension context', () => {
      const disposable = double<Disposable>();
      (output.onDidChangeLogLevel as Mock).mockReturnValueOnce(disposable);
      subject = buildSubject();

      expect(context.subscriptions).toContain(disposable);
    });
  });

  describe('handleLogLevelChange()', () => {
    describe('when extension tracing is not enabled', () => {
      beforeEach(() => {
        (config.get as Mock).mockImplementation((key: string) => {
          return key === 'trace.extension' ? false : undefined;
        });
        subject = buildSubject();
      });

      it('sets level provided as argument', () => {
        const level = LogLevel.Debug;
        subject['handleLogLevelChange'](level);

        expect(subject['_level']).toBe(level);
      });
    });

    describe('when extension tracing is enabled', () => {
      beforeEach(() => {
        (config.get as Mock).mockImplementation((key: string) => {
          return key === 'trace.extension' ? true : undefined;
        });
        subject = buildSubject();
      });

      it('sets level to trace and ignore provided parameter', () => {
        const level = LogLevel.Debug;
        subject['handleLogLevelChange'](level);

        expect(subject['_level']).toBe(LogLevel.Trace);
      });
    });
  });

  describe('addRecord()', () => {
    let formatter: LogFormatter;
    let record: LogRecord;

    beforeEach(() => {
      formatter = double<LogFormatter>({
        format: vi.fn(() => ['log'])
      });
      subject = buildSubject({ formatter });
      subject.setLevel(LogLevel.Trace);
    });

    describe('when the log level is set to `Off`', () => {
      beforeEach(() => {
        subject['_level'] = LogLevel.Off;
      });

      it('does not output anything', () => {
        subject.addRecord({
          level: LogLevel.Trace,
          message: 'trace',
          metadata: {}
        });

        expect(output.info).not.toHaveBeenCalled();
      });
    });

    describe('when the record log level is higher than current logger level', () => {
      beforeEach(() => {
        subject['_level'] = LogLevel.Warning;
        record = {
          level: LogLevel.Info,
          message: 'info',
          metadata: {}
        };
      });

      it('does not output anything', () => {
        subject.addRecord(record);

        expect(output.trace).not.toHaveBeenCalled();
      });
    });

    describe('when the record log level is lower or equal to current logger level', () => {
      beforeEach(() => {
        subject['_level'] = LogLevel.Info;
        record = {
          level: LogLevel.Info,
          message: 'info',
          metadata: {}
        };
      });

      it('outputs the log', () => {
        subject.addRecord(record);

        expect(output.info).toHaveBeenCalled();
      });
    });

    Object.entries(LogLevel).forEach(([key, value]) => {
      if (key === 'Off') {
        return; // handled in another test case above.
      }
      describe(`when log record has a ${key.toLowerCase()} level`, () => {
        const level = key.toLowerCase();
        const method = level === 'warning' ? 'warn' : level;

        beforeEach(() => {
          record = {
            level: value as LogLevel,
            message: 'a message',
            metadata: {}
          };
        });

        it(`calls ${level} on log output channel`, () => {
          subject.addRecord(record);

          expect(
            (
              output as LogOutputChannel &
                // eslint-disable-next-line @typescript-eslint/no-explicit-any
                Record<string, (message: string, ...args: any[]) => void>
            )[method]
          ).toBeCalled();
          expect(formatter.format).toHaveBeenCalledWith(record);
        });
      });
    });
  });

  describe('setLevel()', () => {
    beforeEach(() => {
      subject = buildSubject();
    });

    it('sets the level on logger service', () => {
      const level = LogLevel.Warning;
      subject.setLevel(level);

      expect(subject['_level']).toBe(level);
    });
  });
});
