#include <stdio.h>
#include <string.h>
int r[100002] = {0}, p[100002] = {0};
int main()
{
    int x;
    while (1)
    {
        do
        {
            x = getchar();
            if (x == EOF)
                return 0;
        } while (x == '\n');
        int num = 0, r_num = 1, a = 0;
        if (x == '(')
        {
            p[num] = a;
            r[a] = r_num;
            a += 2;
            num++;
        }
        r_num++;
        while (1)
        {
            x = getchar();
            if (x == '\n' || x == EOF)
                break;
            if (x == '(')
            {
                p[num] = a;
                r[a] = r_num;
                a += 2;
                num++;
            }
            else
            {
                r[p[num - 1] + 1] = r_num;
                num--;
            }
            r_num++;
        }
        for (int i = 0; i < r_num - 2; i += 2)
        {
            printf("%d %d\n", r[i], r[i + 1]);
        }
        memset(r, 0, sizeof(r));
        memset(p, 0, sizeof(p));
    }
    return 0;
}