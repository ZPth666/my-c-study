#include <stdio.h>
int main()
{
    int a,b;
    char cal;
    char eq;
    int n = 0;
    int c = -1;
    while(scanf("%d %c %d %c %d",&a,&cal,&b,&eq,&c)!=EOF)
    {
        getchar();
        if (c==-1) continue;
        
        if (cal=='+')
        {
            if (a+b==c)
            {
                n++;
            }
        }
        if (cal=='-')
        {
            if (a-b==c)
            {
                n++;
            }
        }
        c = -1;
    }
    printf("%d",n);
}