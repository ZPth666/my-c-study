#include <stdio.h>
long long fbnq(long long x)
{
    long long m =1;
    long long n =1;
    long long mid;
    long long y =1;
    for (long long i = 0; ; i++)
    {
        if (n==x)
        {
            //printf("%d\n",y);
            break;
        }
        if (n>x)
        {
            y=0;
            break;
        }
        mid = n;
        n = m+n;
        m =mid;
        y++;
    }
    return y;
}
int main()
{
    long long x;
    while (scanf("%lld",&x)!=EOF)
    {
        printf("%lld\n",fbnq(x));
    }
    return 0;
}