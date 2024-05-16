import { typescript, vitest } from '@gcoguiec/eslint-config';

export default [
  {
    ignores: ['out/*', 'dist/*', 'packages/*', 'vitest.config.ts']
  },
  ...(await typescript()),
  ...(await vitest({ typescript: true }))
];
