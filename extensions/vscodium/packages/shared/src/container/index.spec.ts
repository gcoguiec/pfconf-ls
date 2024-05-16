import type * as vscode from 'vscode';

import { describe, expect, it } from 'vitest';

import { isServiceDisposable, tokenToStr } from './index.js';

describe('isServiceDisposable()', () => {
  describe('when service is not disposable', () => {
    // eslint-disable-next-line @typescript-eslint/no-extraneous-class
    class MyService {}

    it('returns false', () => {
      expect(isServiceDisposable(new MyService())).toBe(false);
    });
  });

  describe('when service is disposable', () => {
    class MyService implements vscode.Disposable {
      public dispose() {}
    }

    it('returns true', () => {
      expect(isServiceDisposable(new MyService())).toBe(true);
    });
  });
});

describe('tokenToStr()', () => {
  // eslint-disable-next-line @typescript-eslint/no-extraneous-class
  class MyService {}

  it('converts a service token to a string', () => {
    expect(tokenToStr(MyService)).toBe('MyService');
    expect(tokenToStr('string')).toBe('string');
    expect(tokenToStr(Symbol('string'))).toBe('Symbol(string)');
  });
});
