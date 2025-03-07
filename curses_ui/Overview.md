#### 1. Introduce.

- 源文件宏依赖
  - XCURSES -- x11
  - PDC_RGB -- RGB
  - PDC_WIDE -- 宽字符支持
  - PDC_FORCE_UTF8 -- 使用utf-8
  - PDC_DLL_BUILD -- windows dll动态库
  - PDC_NCMOUSE -- pdcurses和ncurses鼠标
  - ...
- cmake库依赖
- system
  - dos MS/IBM老旧废弃考古系统
    - dos
    - dosvga
  - plan9 9fronts废弃考古系统
    - plan9
  - os/2 MS/IBM老旧废弃考古系统
    - os2
  - linux/*BSD framebuffer帧缓冲
    - fb
  - linux
    - x11 图形窗口
    - vt  虚拟终端
  - windows
    - x11 图形窗口
    - vt  虚拟终端
    - wincon 命令终端
    - wingui gui窗口
- other 各种库
  - sdl1.x
  - sdl2.x
  - freetype2
  - sdl2_ttf
  - zlib
  - openGL

#### 2. Build and tests.

Windows:

```sh
# Makefile:
cd vt
nmake -f Makefile.vc WIDE=Y UTF8=Y DEBUG=Y demos 
cd wincon
nmake -f Makefile.vc WIDE=Y UTF8=Y DEBUG=Y demos 
cd wingui
nmake -f Makefile.vc WIDE=Y UTF8=Y DEBUG=Y demos 

# CMakeLists.txt
mkdir build
cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_SUBTARGET_NAME=vt ..
nmake 
```

Linux/macOS:

```sh
# Makefile:
cd vt
make -f Makefile WIDE=Y UTF8=Y DEBUG=Y demos 
cd ncurses
make -f Makefile WIDE=Y UTF8=Y DEBUG=Y demos 
cd fb
make -f Makefile WIDE=Y UTF8=Y DEBUG=Y demos 

# CMakeLists.txt
mkdir build
cmake -DBUILD_SUBTARGET_NAME=vt ..
make 
```