import type { ExtensionContext } from 'vscode';

import { double } from 'vitest-double';
import { describe, beforeEach, it, expect, vi, afterEach } from 'vitest';

import type {
  Container,
  ExtensionFactoryOptions,
  LogFormatter
} from './index.js';

import { Extension } from './index.js';

describe(Extension.name, () => {
  // eslint-disable-next-line @typescript-eslint/no-extraneous-class
  class MyService {}

  function buildExtension(options: ExtensionFactoryOptions = {}) {
    return new Extension({
      extensionName: 'ext',
      context: double<ExtensionContext>(),
      builtinServices: true,
      logOutputChannel: { name: 'channel' },
      logger: {
        formatter: double<LogFormatter>()
      },
      ...options
    });
  }

  beforeEach(() => {
    buildExtension();
  });

  afterEach(() => {
    vi.resetAllMocks();
  });

  describe(`${Extension.name}.setContainer()`, () => {
    let container: Container;

    beforeEach(() => {
      container = double<Container>();
    });

    it('sets container on the extension instance', () => {
      Extension.setContainer(container);

      expect(Extension['_container']).toBe(container);
    });
  });

  describe(`${Extension.name}.hasContainer()`, () => {
    describe('when container is not registered', () => {
      beforeEach(() => {
        Extension['_container'] = undefined;
      });

      it('returns false', () => {
        expect(Extension.hasContainer()).toBe(false);
      });
    });

    describe('when container is registered', () => {
      beforeEach(() => {
        Extension['_container'] = double<Container>();
      });

      it('returns true', () => {
        expect(Extension.hasContainer()).toBe(true);
      });
    });
  });

  describe(`${Extension.name}.incinerateContainer()`, () => {
    let container: Container;

    beforeEach(() => {
      container = double<Container>({
        dispose: vi.fn()
      });
      Extension['_container'] = container;
      Extension.incinerateContainer(); // UUT
    });

    it('calls dispose on the container', () => {
      expect(container.dispose).toHaveBeenCalledOnce();
    });

    it('sets container to undefined', () => {
      expect(Extension['_container']).toBeUndefined();
    });
  });

  describe(`${Extension.name}.registerService()`, () => {
    let container: Container;
    let service: MyService;

    describe('when a service is registered via the extension', () => {
      beforeEach(() => {
        service = double<MyService>();
        container = double<Container>({
          register: vi.fn()
        });
        Extension['_container'] = container;
        Extension.registerService(MyService, service); // UUT
      });

      it('calls register on the container', () => {
        expect(container.register).toHaveBeenCalledOnce();
      });
    });
  });

  describe(`${Extension.name}.injectService()`, () => {
    let container: Container;

    beforeEach(() => {
      container = double<Container>({
        inject: vi.fn()
      });
    });

    describe('when container is not initialized', () => {
      beforeEach(() => {
        Extension['_container'] = undefined;
      });

      it('throws an error', () => {
        expect(() => Extension.injectService(MyService)).toThrowError(
          'Cannot inject a service from an uninitialized container.'
        );
      });
    });

    describe('when container is initialized', () => {
      beforeEach(() => {
        Extension['_container'] = container;
      });

      it('calls inject method on the container', () => {
        Extension.injectService(MyService);

        expect(container.inject).toHaveBeenCalledWith(MyService);
      });
    });
  });
});
