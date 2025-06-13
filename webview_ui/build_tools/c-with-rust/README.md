#### 结构要点。

```sh
├── CMakeLists.txt
├── include             # rust封装成c接口的声明头文件，有新接口添加则需要新添加接口声明到里面的头文件
├── README.md       
├── rust                # rust静态库生成的源文件
└── src                 # c/cpp源文件
```

#### 构建。

```sh
mkdir build && cd build
cmake ..
make -j8
./c-with-rust 
# 输出:
# name: Alice
# age: (not found)   // 注意：age 是数字类型，非字符串
# email: alice@example.com
```