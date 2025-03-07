#### 更改

```sh
# 1. 抽离出fb/ncurses/pdcurses/tests/vt/wincon/wingui/x11
# 2. pdcurses未变更任何东西
# 3. 更改fb/ncurses/vt/wincon/wingui/x11的CMakeLists.txt, 代码部分未做出更改
```

#### 依赖

```sh
# 头文件依赖包查找和安装
sudo apt-get install apt-file
sudo apt-file update
apt-file search Intrinsic.h

# 安装x11依赖
sudo apt install libxt-dev libx11-dev
```

#### 编译

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


