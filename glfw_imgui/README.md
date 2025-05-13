# repo

```sh
imgui(msater): 4c0604ec2ee9a9121ea4ecb55543ff507ca81bcc
```

# build

```sh
# linux 
sudo apt-get install libglu1-mesa-dev
export CPATH=/usr/include/GL:$CPATH
mkdir build
cmake ..
make -j8

# windows
# open visual studio --> open local folders --> glfw_imgui --> build
```