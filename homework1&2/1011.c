#include <stdio.h>
int main()
{
    int m=0;
    int i;
    int s1[100000];
    int n=0;

    for ( i = 1; i <=214287; i++)
    {
        if (i%3==0 || i%5==0)
        {
            s1[m++]=i;
        }
        
    }
    while (scanf("%d",&n)!=EOF)
    {
        printf("%d\n",s1[n-1]);
    }
    

    return 0;
}