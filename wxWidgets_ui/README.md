# repo

```sh
wxWidgets-3.2.8: tag v3.2.8
```

# notes

- wx_wrapsizers_tutorial: not support linux.

# Build

```sh
# reference: https://github.com/lszl84
# dependence: https://github.com/wxWidgets/wxWidgets.git

# windows
cmake -S. -Bbuild
cmake --build build
cmake --build build -j8

# linux
sudo apt install libwxgtk3.0-gtk3-dev libgtk-3-dev
dpkg -L libgtk-3-dev | grep gtk.h
pkg-config --cflags --libs gtk+-3.0
find /usr -name "gtk+-3.0.pc" 2>/dev/null
# /usr/lib/x86_64-linux-gnu/pkgconfig/gtk+-3.0.pc
export PKG_CONFIG_PATH="/usr/lib/x86_64-linux-gnu/pkgconfig:$PKG_CONFIG_PATH"
```