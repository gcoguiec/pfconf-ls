import { typescript, vitest } from '@gcoguiec/eslint-config';

export default [
  {
    ignores: ['coverage', 'vitest.config.ts']
  },
  ...(await typescript()),
  ...(await vitest({
    typescript: true,
    overrides: {
      '@typescript-eslint/dot-notation': 'off'
    }
  }))
];
