#include <stdio.h>
int main()
{
    int a,b,c;
    
    while (scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if (a>=-10000 && a<=10000 && b>=-10000 && b<=10000 && c>=-10000 && c<=10000)
        {
            printf("%d\n",(a+b)*c);
        }
        else break;
    }
    
    return 0;
}