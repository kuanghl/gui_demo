#### rust静态库。

```sh
# 生成C头文件（使用cbindgen）
cargo install --force cbindgen
cbindgen --config cbindgen.toml --crate json_parser --output json_parser.h
```