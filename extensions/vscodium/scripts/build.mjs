// @ts-check
import { context } from 'esbuild';

context({
  entryPoints: {
    client: './out/main.js'
  },
  bundle: true,
  outdir: './dist',
  external: ['vscode'],
  format: 'cjs',
  platform: 'node',
  tsconfig: './tsconfig.json'
}).then(async ctx => {
  console.log('building client...');
  await ctx.rebuild();
  await ctx.dispose();
  console.log('finished');
});
