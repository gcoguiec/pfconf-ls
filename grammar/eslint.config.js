import { ecmascript } from '@gcoguiec/eslint-config';

export default [
  {
    ignores: ['build/*']
  },
  ...(await ecmascript({
    overrides: {
      'no-undef': 0
    }
  }))
];
