import type { ExtensionContext } from 'vscode';

import { double } from 'vitest-double';
import { describe, beforeEach, it, expect } from 'vitest';

import type { Container } from './index.js';

import { Extension, ExtensionFactory } from './index.js';

describe(ExtensionFactory.name, () => {
  let context: ExtensionContext;

  beforeEach(() => {
    context = double<ExtensionContext>();
  });

  describe(`${ExtensionFactory.name}.create()`, () => {
    describe('when container is already initialized', () => {
      beforeEach(() => {
        Extension['_container'] = double<Container>();
      });

      it('throws an error', () => {
        expect(() => ExtensionFactory.create({ context })).toThrowError(
          'Extension container has already been initialized. Did you `deactivate()` the previous extension instance?'
        );
      });
    });

    describe('when container is not already initialized and context was not provided', () => {
      beforeEach(() => {
        Extension['_container'] = undefined;
      });

      it('throws an error', () => {
        expect(() => ExtensionFactory.create({})).toThrowError(
          `Extension context is a requirement and must be provided using the 'context' option key.`
        );
      });
    });
  });
});
