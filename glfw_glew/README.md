# glfw_glew

Minimal glfw glew CMake project, all dependencies are fetched from internet.

# build

```sh
# linux 
sudo apt-get install libglu1-mesa-dev
export CPATH=/usr/include/GL:$CPATH
mkdir build
cmake ..
make -j8

# windows
# open visual studio --> open local folders --> glfw_glew --> build
```