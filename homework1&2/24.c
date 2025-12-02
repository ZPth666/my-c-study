#include <stdio.h>
double cal(int n);
double cal(int n)
{
    int m=1;
    for (int i = 1; i <= n; i++)
    {
        m*=i;
    }
    return 1.0/m;
}

int main()
{
    int n=0;
    double e=1.0;
    scanf("%d",&n);
    for (int a = 1; a <= n; a++)
    {
        e+=cal(a);
    }
    printf("%.6f",e);
}