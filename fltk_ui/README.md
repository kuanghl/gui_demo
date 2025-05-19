# build fltk_cpp.

```sh
# linux 
sudo apt-get install libglu1-mesa-dev
export CPATH=/usr/include/GL:$CPATH
mkdir build
cmake ..
make -j8

# windows
# open visual studio --> open local folders --> fltk_ui --> build
```

# build fltk-theme.

```sh
export PKG_CONFIG_PATH="/usr/lib/x86_64-linux-gnu/pkgconfig:$PKG_CONFIG_PATH"
cargo build --release
cargo build
cargo build --examples --features=fltk/fltk-bundled --verbose
# get the binaries of execution to the bin.
```