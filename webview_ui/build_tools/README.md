#### Using rust/cpp/c with cmake.

1. [tokenizers-cpp](https://github.com/mlc-ai/tokenizers-cpp.git):引用[rust tokenizers](https://github.com/huggingface/tokenizers.git)库，封装成c接口并编译成静态库，构造一个.h头文件供c/cpp使用。
2. [cargo_cmake](./cargo_cmake/README.md):rust引用c或cpp库(CMake)的示例。
3. [c-with-rust](./c-with-rust/README.md):c/cpp引用rust封装的c接口，类似tokenizers-cpp的实现。