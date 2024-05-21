import * as vscode from 'vscode';

import { double } from 'vitest-double';
import { vi } from 'vitest';

export const commands = double<typeof vscode.commands>({
  registerCommand: vi.fn(),
  executeCommand: vi.fn()
});

export const workspace = double<typeof vscode.workspace>({
  getConfiguration: vi.fn(() =>
    double<vscode.WorkspaceConfiguration>({
      get: vi.fn(() => {})
    })
  )
});

export const window = double<typeof vscode.window>({
  createOutputChannel: double<typeof vscode.window.createOutputChannel>(() =>
    double<vscode.LogOutputChannel>({
      clear: vi.fn(),
      onDidChangeLogLevel: vi.fn()
    })
  )
});

export const LogLevel = {
  Off: 0,
  Trace: 1,
  Debug: 2,
  Info: 3,
  Warning: 4,
  Error: 5
};
