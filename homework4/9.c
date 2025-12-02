#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ret;
        char s[400005] = " ";
        char *p = s;
        int sum = 0;
        for (int i = 1; i < 10000; i++)
        {
            ret = snprintf(p,10*sizeof(char),"%d",i);
            p += ret;
            sum += ret;
            if (sum > n)
            {
                printf("%c\n",s[n-1]);
                break;
            }
        }
    }
    return 0;
}
