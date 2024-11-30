# setup

```bash
# 根目录依赖
pnpm i -D typescript vite jest @types/jest ts-jest @testing-library/react @testing-library/jest-dom cypress @storybook/react @storybook/vue3 @storybook/svelte @storybook/addon-essentials eslint prettier husky lint-staged

# Core 包依赖
pnpm --filter @elephantd/core i @emotion/css
pnpm --filter @elephantd/core i -D typescript vite @types/react

# React 包依赖
pnpm --filter @elephantd/react i react react-dom
pnpm --filter @elephantd/react i -D @types/react @types/react-dom @vitejs/plugin-react vite typescript

# Vue 包依赖
pnpm --filter @elephantd/vue i vue
pnpm --filter @elephantd/vue i -D @vitejs/plugin-vue vite typescript

# Svelte 包依赖
pnpm --filter @elephantd/svelte i svelte
pnpm --filter @elephantd/svelte i -D @sveltejs/vite-plugin-svelte vite typescript

# 文档依赖 (如果使用 VitePress)
pnpm --filter @elephantd/docs i -D vitepress
```

pnpm i -D jest-environment-jsdom -w