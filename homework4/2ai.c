#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    enum { MAXN = 100005 };
    static char s[MAXN + 5];

    while (fgets(s, sizeof s, stdin)) {
        int len = strlen(s);
        while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) --len;
        if (len == 0) continue;

        /* 动态按本行长度分配，避免跨用例残留 */
        int *left_pos = (int*)malloc((len + 1) * sizeof(int));
        int *right_pos = (int*)malloc((len + 1) * sizeof(int));
        int *st = (int*)malloc((len + 1) * sizeof(int));
        if (!left_pos || !right_pos || !st) {
            /* 内存分配失败（极少见），直接退出 */
            return 0;
        }

        int cnt = 0, top = 0;
        for (int i = 0; i < len; ++i) {
            char c = s[i];
            if (c == '(') {
                left_pos[cnt] = i + 1;
                right_pos[cnt] = 0;
                st[top++] = cnt++;
            } else if (c == ')') {
                if (top > 0)
                    right_pos[st[--top]] = i + 1;
            }
        }

        /* 题目保证合法序列：按左括号下标（即出现顺序）输出 */
        for (int i = 0; i < cnt; ++i)
            printf("%d %d\n", left_pos[i], right_pos[i]);

        free(left_pos);
        free(right_pos);
        free(st);
    }
    return 0;
}
