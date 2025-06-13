#include "json_parser.h"
#include <stdio.h>

int main() {
    // 创建 JSON 解析器对象（从文件加载）
    JsonParser parser = json_parser_new("data.json");
    if (!parser) {
        printf("Failed to parse JSON\n");
        return 1;
    }

    // 查询字段值
    char buffer[256];
    const char* keys[] = {"name", "age", "email"};
    for (int i = 0; i < 3; i++) {
        int ret = json_parser_get_string(parser, keys[i], buffer, sizeof(buffer));
        if (ret == 0) {
            printf("%s: %s\n", keys[i], buffer);
        } else {
            printf("%s: (not found)\n", keys[i]);
        }
    }

    // 释放对象
    json_parser_free(parser);
    return 0;
}