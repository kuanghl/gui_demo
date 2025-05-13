# notes

- cann't run in vscode terminal.

# build

```sh
# linux 
sudo apt-get install libglu1-mesa-dev
export CPATH=/usr/include/GL:$CPATH
mkdir build
cmake ..
make -j8

# windows
# open visual studio --> open local folders --> glfw_microui --> build
```