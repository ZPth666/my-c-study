#include <stdio.h>
#include <string.h>
#include <ctype.h> // 用于 isdigit 函数

int main() {
    int n;
    scanf("%d", &n);
    // 清除输入缓冲区中的剩余字符（包括换行符）
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        // 清除换行符
        while ((c = getchar()) != '\n' && c != EOF);

        int instructions[100] = {0}; // 存储每条指令的移动值

        for (int j = 0; j < m; j++) {
            char line[20]; // 增大缓冲区
            fgets(line, sizeof(line), stdin);

            // 去除换行符（如果存在）
            size_t len = strlen(line);
            if (len > 0 && line[len-1] == '\n') {
                line[len-1] = '\0';
            }

            if (strcmp(line, "LEFT") == 0) {
                instructions[j] = -1;
            } else if (strcmp(line, "RIGHT") == 0) {
                instructions[j] = 1;
            } else if (strncmp(line, "SAME AS", 7) == 0) {
                int index;
                // 使用 sscanf 提取数字，支持多位数
                sscanf(line + 8, "%d", &index); // line+8 跳过 "SAME AS " 的前8个字符（包括空格）
                instructions[j] = instructions[index - 1]; // 复制对应指令的值
            }
        }

        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += instructions[j];
        }
        printf("%d\n", sum);
    }
    return 0;
}