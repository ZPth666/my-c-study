#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int m=0;
        int cost=0;
        if(n>=38)
        {
            m+=n/38;
            n%=38;
            cost+=m*38;
        }
        if (n>=18)
        {
            m+=n/18;
            int a=n/18;
            n%=18;
            cost+=a*18;
        }
        if (n>=8)
        {
            m+=n/8;
            int b=n/8;
            n%=8;
            cost+=b*8;
        }
        if (cost>68)
        {
            m++;
        }
        printf("%d\n",m);
    }
    return 0;
}