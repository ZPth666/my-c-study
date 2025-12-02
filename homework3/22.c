#include <stdio.h>
#include <stdlib.h>
int *isprime(int result)
{
    const int m=3500;
    int prime[m];
    int *primes = (int*)malloc(result*sizeof(int));
    int a=0;
    for (int i = 0; i < m; i++)
    {
        prime[i]=1;
    }
    for (int i1 = 2; i1 < m; i1++)
    {
        if (prime[i1])
        {
            for (int i2 = 2; i2*i1 < m; i2++)
            {
                prime[i1*i2]=0;
            }
        }
    }
    for (int i3 = 2; i3 < m; i3++)
    {
        if (prime[i3])
        {
            primes[a]=i3;
            a++;
            if (a>=result)
            {
                break;
            }
        }
    }
    return primes;
}
int sum(int num)
{
    int result;
    result = (num+1)*num/2;
    return result;
}
int *yanghui(int n)
{
    int *yh = (int*)malloc(sum(n)*sizeof(int));
    yh[0]=1;
    yh[1]=1;
    yh[2]=1;
    int a=3;
    for (int i = 3; i <= n; i++)
    {
        yh[a++]=1;
        for(int i1 = 0; i1 < i-2; i1++)
        {
            yh[a]=yh[a-i]+yh[a-i+1];
            a++;
        }
        yh[a++]=1;
    }
    return yh;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int *p = isprime(sum(n-1));
        int *y = yanghui(n);
        int m=0;
        int j=0;
        for (int i = 0; i < n; i++)
        {
            for (int i1 = 0; i1 < i+1; i1++)
            {
                printf("%d ",y[m++]);
            }
            for (int i2 = 0; i2 < n-i-1; i2++)
            {
                printf("%d ",p[j++]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}