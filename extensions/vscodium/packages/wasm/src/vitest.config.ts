import { defineConfig } from 'vitest/config';

import { resolve } from 'path';

export default defineConfig({
  test: {
    environment: 'happy-dom',
    coverage: {
      all: true,
      include: ['src/**/*.ts'],
      provider: 'v8'
    }
  },
  resolve: {
    alias: {
      vscode: resolve(process.cwd(), 'vscode.shim.ts')
    }
  }
});
