import type { ExtensionContext } from 'vscode';

import { double } from 'vitest-double';
import { afterEach, beforeEach, describe, expect, it } from 'vitest';

import { Extension } from '../src/extension.js';
import { ExtensionFactory } from '../src/extension.factory.js';

describe('Dependency Injection', () => {
  let context: ExtensionContext;
  let extension: Extension;

  // eslint-disable-next-line @typescript-eslint/no-extraneous-class
  class MyFirstService {}

  class MySecondService {
    public readonly dependency = Extension.injectService(MyFirstService);
  }

  beforeEach(() => {
    context = double<ExtensionContext>({
      subscriptions: []
    });
    extension = ExtensionFactory.create({ context });
    extension.activate();
  });

  afterEach(() => {
    extension.deactivate();
  });

  it('registers a service with its dependencies', () => {
    const firstService = new MyFirstService();
    Extension.registerService(MyFirstService, firstService);
    Extension.registerService(MySecondService, new MySecondService());

    const secondService = Extension.injectService(MySecondService);
    expect(secondService.dependency).toBe(firstService);
  });
});
