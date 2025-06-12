#### ubuntu build webview.

```sh
# https://github.com/webview/webview.git
# master: f1a9d6b6fb8bcc2e266057224887a3d628f30f90
sudo apt update
sudo apt install libwebkit2gtk-4.1-dev \
  build-essential \
  curl \
  wget \
  file \
  libxdo-dev \
  libssl-dev \
  libayatana-appindicator3-dev \
  librsvg2-dev

# libwebkit2gtk-4.1-dev need ubuntu 22.04, now using ubuntu 20.04
sudo vim /etc/apt/sources.list # 追加以下源，完成安装后删掉 
deb http://archive.ubuntu.com/ubuntu jammy main restricted universe
sudo apt update
sudo apt install libwebkit2gtk-4.1-0 -t jammy
sudo apt-get install -y --allow-downgrades libgtk-3-dev/jammy libsoup-3.0-dev/jammy libwebkit2gtk-4.1-dev/jammy
sudo vim /etc/apt/sources.list # 删掉jammy源
sudo apt update
dpkg -l libwebkit2gtk-4.1-0 libwebkit2gtk-4.1-dev
pkg-config --cflags --libs webkit2gtk-4.1
find /usr -name "webkit2gtk-4.1.pc" 2>/dev/null
export PKG_CONFIG_PATH="/usr/lib/x86_64-linux-gnu/pkgconfig:$PKG_CONFIG_PATH"

mkdir build && cd build
cmake ..
make -j8 
```

#### build tauri2.0 on windows.

```sh
# 架构1
# vue3 + typescript --(P/invoke)--> rust --(cc)--> c/c++
# 架构2
# xaml + C# --(P/invoke-C++/CLI)--> c/c++
# 注意事项
# [tauri::command]
# // 传参不能使用下滑线，如name不能为inf_name

# 技术栈
# tauri 2.0
# vue3
# - Shadcn Vue + Tailwind CSS v4 
# - Vue Router 
# - Vue I18n
# - Pinia
# vite6
# rust
# c/c++

# build
set PATH=%PATH%;C:\Users\kuanghl\.cargo\bin
$env:PATH += ";C:\Users\kuanghl\.cargo\bin"
Start-Process powershell -Verb RunAs # need run as administrator
pnpm i
pnpm tauri build
pnpm tauri build -- --verbose
pnpm tauri dev          # build and run
pnpm install vue-router
pnpm install @vueuse/core
pnpm install @tauri-apps/plugin-os

# rust添加包
# cargo add --build cc@1.1.36
cargo add sysinfo serde
cargo add libc 
cargo add --build cc
cargo add encoding_rs
cargo add whoami
# cargo new --bin test

# # tree for folder
# ├── src/
# │   ├── mod/
# │   │   ├── demo/
# │   │   │   ├── demo.c
# │   │   │   └── demo.rs
# │   │   └── mod.rs
# │   └── main.rs

# failed test
# pnpm add vue-router
# pnpm rm vue-router
# pnpm add tailwindcss @tailwindcss/vite @vitejs/plugin-react
# pnpm add vue-router @headlessui/vue @heroicons/vue
# pnpm add -D @types/node

# extensions: https://v2.tauri.app/zh-cn/plugin/
pnpm tauri add http                 # js: @tauri-apps/plugin-http / rust: tauri_plugin_http
pnpm tauri add autostart            # js: @tauri-apps/plugin-autostart / rust: tauri_plugin_autostart
pnpm tauri add clipboard-manager    # js: @tauri-apps/plugin-clipboard-manager / rust: tauri_plugin_clipboard_manager

# issues: 下划线
# Error The bundle identifier "com.rpp_control.app" set in `tauri.conf.json identifier`
"identifier": "com.rpp_control.app", --> "identifier": "com.rpp-control.app",

# https://www.liesauer.net/blog/post/make-tauri-frontend-side-better-debugging-experience-as-a-regular-web-app.html
# debug调试步骤
# 1. 启动Tauri App Ctrl+Shift+D然后选择Attach to tauri webview，启动Tauri App。
# 2. F5启动调试
```

#### build tauri2.0 on ubuntu22.04LTSC.

```sh
# tauri new project
sudo apt update
sudo apt install libwebkit2gtk-4.1-dev \
  build-essential \
  curl \
  wget \
  file \
  libxdo-dev \
  libssl-dev \
  libayatana-appindicator3-dev \
  librsvg2-dev
# sudo apt install libwebkit2gtk-4.1-dev build-essential curl wget file libxdo-dev libssl-dev libayatana-appindicator3-dev librsvg2-dev

# 官方文档: https://v2.tauri.app/zh-cn/start/create-project/
# 参考博客: https://blog.csdn.net/weixin_47754149/article/details/135032006
# 参考示例: https://github.com/agmmnn/tauri-ui.git
# create-tauri-app -- 包管理pnpm, yarn, npm, deno, bun, cargo, dotnet
npm install pnpm -g
# npm install --global pnpm
pnpm create tauri-app vue

# ? Choose which language to use for your frontend › ❯ TypeScript / JavaScript  (pnpm, yarn, npm, deno, bun)
#                                                    Rust  (cargo)
#                                                    .NET  (dotnet)

# ? Choose your UI template ›
# ❯ Vanilla
#  Vue 
#  Svelte 
#  React 
#  Solid 
#  Angular 
#  Preact 

# ? Choose your UI flavor ›
# ❯ TypeScript
#  JavaScript

# tauri + vue/vite + TypeScript / JavaScript for new project
# 切换镜像: pnpm config set registry https://registry.npmmirror.com/
# sudo apt install libjavascriptcoregtk-4.1-dev libwebkit2gtk-4.1-dev
# find /usr -name "javascriptcoregtk-4.1.pc" 2>/dev/null
# export PKG_CONFIG_PATH="/usr/lib/x86_64-linux-gnu/pkgconfig:$PKG_CONFIG_PATH"
# export LD_LIBRARY_PATH="/usr/lib/x86_64-linux-gnu:$LD_LIBRARY_PATH" && sudo ldconfig
pnpm create tauri-app vue
✔ Identifier · vue
✔ Choose which language to use for your frontend · TypeScript / JavaScript - (pnpm, yarn, npm, deno, bun)
✔ Choose your package manager · pnpm
✔ Choose your UI template · Vue - (https://vuejs.org/)
✔ Choose your UI flavor · TypeScript

Template created!

Your system is missing dependencies (or they do not exist in $PATH):
╭───────┬─────────────────────────────────────────────────────╮
│ rsvg2 │ Visit https://tauri.app/guides/prerequisites/#linux │
╰───────┴─────────────────────────────────────────────────────╯

Make sure you have installed the prerequisites for your OS: https://tauri.app/start/prerequisites/, then run:
  cd vue
  pnpm install
  pnpm tauri android init

For Desktop development, run:
  pnpm tauri dev

For Android development, run:
  pnpm tauri android dev

# build
export PKG_CONFIG_PATH="/usr/lib/x86_64-linux-gnu/pkgconfig:$PKG_CONFIG_PATH"
cd vue
pnpm i
pnpm tauri build
pnpm tauri dev     # build and run
```

#### Note.

- **前端框架对比**
1. [React、preact、svelte、solid框架总结](https://zhuanlan.zhihu.com/p/31665022730): 框架比较和基本语法学习。
2. [js-framework-comparison](https://github.com/MarioVieilledent/js-framework-comparison.git): javascript UI框架比较。
3. [awesome-tauri](https://github.com/tauri-apps/awesome-tauri.git): tauri支持框架及[模板](https://v2.tauri.org.cn/start/create-project/)。

- **迁移升级到tauri2.0**

```sh
# https://v2.tauri.app/zh-cn/start/migrate/
pnpm update @tauri-apps/cli@latest
pnpm tauri migrate
```

```json
// tauri.conf.json
// tauri-vue3-template最大化/最小化/关闭有问题，后续修复!TODO
"windows": [{
  "decorations": false,  // 禁用系统标题栏
  "transparent": true     // 需配合自定义UI
}]
```

- **进阶示例**

1. [tauri-vue-template](https://github.com/Uninen/tauri-vue-template.git): tauri2.0官方推荐示例。
2. [tauriv2-vue-desktop-starter](https://github.com/seferino-fernandez/tauriv2-vue-desktop-starter.git): 跨平台vue3 + tauri2.0。
3. [tauri-vue3-template](https://github.com/YuChenFen/tauri-vue3-template.git): 拥有丰富控件的ui示例，但tauri version过低，linux支持有限。
4. [yogu-chat-app](https://github.com/xiaozi/yogu-chat-app.git): 使用Tauri 2.0 + Vue集成的一个大模型交流软件。
5. [vuejs examples](https://cn.vuejs.org/examples/#hello-world): vuejs官方练习和[UI库组件](https://ui-libs.vercel.app/)。

- **vue3 ui测试**

```sh
# https://ui-libs.vercel.app/
# License need buy with 淘宝(taobao)
# shadcn-vue / Reka UI完全免费,并且功能齐全

# primevue
git clone https://github.com/primefaces/primevue.git --depth=1
cd primevue/apps/volt
pnpm i
pnpm run dev
cd primevue/apps/showcase
pnpm i
pnpm run dev

# Nuxt UI
# https://ui.nuxt.com/pro/templates
# nuxt ui pro License
git clone https://github.com/nuxt-ui-pro/dashboard-vue.git
cd dashboard-vue
pnpm i
pnpm run dev

# Vuetify
git clone https://github.com/harryho/vue-crm.git
cd vue-crm
pnpm i
# pnpm update --latest
# pnpm add vue-eslint-parser@10.0.0 -D
# pnpm add shelljs@latest -D
pnpm run dev

# shadcn-vue / Reka UI -- available
git clone https://github.com/unovue/shadcn-vue.git
cd shadcn-vue/apps
pnpm i
pnpm run dev

# Element Plus
git clone https://github.com/Daymychen/art-design-pro.git
cd art-design-pro
pnpm i
pnpm run dev
```
