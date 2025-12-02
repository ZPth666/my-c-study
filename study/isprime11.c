//构造素数表，妙妙秒。
#include <stdio.h>
int main()
{
    const int n=25;
    int i;
    int prime[n];
    int x;

    for ( i = 0; i < n; i++)
    {
        prime[i]=1;
    }
    for ( x = 2; x < n; x++)
    {
        if (prime[x])
        {
            for ( int a = 2; a*x < n; a++)
            {
                prime[a*x]=0;
            }
            
        }
        
    }
    for (int b = 2; b < n; b++)
    {
        if (prime[b])
        {
            printf("%d\t",b);
        }
        
    }
    printf("\n");

    return 0;
}