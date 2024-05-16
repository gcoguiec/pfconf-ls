import type * as vscode from 'vscode';

import { describe, beforeEach, it, expect, vi } from 'vitest';

import { Container } from './container.js';

describe(Container.name, () => {
  // eslint-disable-next-line @typescript-eslint/no-extraneous-class
  class MyService {}

  let subject: Container;
  let service: MyService;

  beforeEach(() => {
    subject = new Container();
    service = new MyService();
  });

  describe('has()', () => {
    describe('when container does not have a specific service in its registry', () => {
      it('returns false', () => {
        expect(subject.has(MyService)).toBe(false);
      });
    });

    describe('when container has a specific service in its registry.', () => {
      beforeEach(() => {
        subject['_registry'].set(MyService, service);
      });

      it('returns true', () => {
        expect(subject.has(MyService)).toBe(true);
      });
    });
  });

  describe('register()', () => {
    describe('when service instance was already registered', () => {
      beforeEach(() => {
        subject.register(MyService, service);
      });

      it('throws an error', () => {
        expect(() => {
          subject.register(MyService, service);
        }).toThrowError(
          `A service instance for '${MyService.name}' is already registered.`
        );
      });
    });

    describe('when service instance was not registered before', () => {
      it('registers the service inside the container', () => {
        subject.register(MyService, service);
        expect(subject['_registry'].has(MyService)).toBe(true);
      });
    });
  });

  describe('inject()', () => {
    describe('when service was not registered with the container', () => {
      it('throws an error', () => {
        expect(() => subject.inject(MyService)).toThrowError(
          `Could not inject service '${MyService.name}'. Did you register it?`
        );
      });
    });

    describe('when service was registered with the container', () => {
      beforeEach(() => {
        subject.register(MyService, service);
      });

      it('returns service instance', () => {
        expect(subject.inject(MyService)).toBe(service);
      });
    });
  });

  describe('dispose()', () => {
    class MyDisposableService implements vscode.Disposable {
      public dispose = vi.fn();
    }

    let disposableService: MyDisposableService;

    beforeEach(() => {
      disposableService = new MyDisposableService();
      subject.register(Symbol('service'), 'value');
      subject.register(MyService, service);
      subject.register(MyDisposableService, disposableService);
    });

    it('disposes the service instances and clear the registry', () => {
      subject.dispose();
      expect(disposableService.dispose).toHaveBeenCalledOnce();
    });
  });
});
