#include <stdio.h>
int main()
{
    int n;
    int i;
    while (scanf("%d",&n)!=EOF)
    {
        if (n>=1 && n<=10)
        {
            for ( i = 0; i < n; i++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}