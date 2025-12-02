#include <stdio.h>
int main()
{
    int n;

    while (scanf("%d",&n)!=EOF)
    {
        if (n>=1 && n<=1e+08)
        {
            printf("%o\n",n);
        }
        
    }
    
    return 0;
}