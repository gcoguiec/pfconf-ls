import type * as vscode from 'vscode';
import type { Mock } from 'vitest';

import { workspace } from 'vscode';
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

import { Extension } from '../index.js';
import { ExtensionNameService } from '../container/index.js';
import { Container } from '../container/container.js';
import { ConfigService } from '../config/config.service.js';

describe(ConfigService.name, () => {
  const extensionName = 'ext';
  const setting = 'a.specific.setting';

  let subject: ConfigService;
  let container: Container;

  beforeAll(() => {
    container = new Container();
    container.register(ExtensionNameService, extensionName);
    Extension.setContainer(container);
  });

  afterAll(() => {
    Extension.incinerateContainer();
  });

  beforeEach(() => {
    subject = new ConfigService();
  });

  afterEach(() => {
    vi.resetAllMocks();
  });

  describe('get()', () => {
    const configuration = double<vscode.WorkspaceConfiguration>({
      get: vi.fn(() => {})
    });

    beforeEach(() => {
      (workspace.getConfiguration as Mock).mockReturnValueOnce(configuration);
    });

    it('calls underlying workspace using extension name as section', () => {
      subject.get(setting);

      expect(workspace.getConfiguration).toHaveBeenCalledWith(extensionName);
      expect(configuration.get).toHaveBeenCalledWith(setting);
    });
  });

  describe('affects()', () => {
    let event: vscode.ConfigurationChangeEvent;

    beforeEach(() => {
      event = double<vscode.ConfigurationChangeEvent>({
        affectsConfiguration: vi.fn()
      });
    });

    it('calls `affectsConfiguration` on provided event passing complete section', () => {
      subject.affects(event, setting);
      expect(event.affectsConfiguration).toHaveBeenCalledWith(
        `${extensionName}.${setting}`
      );
    });
  });
});
