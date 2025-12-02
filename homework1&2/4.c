#include <stdio.h>
int main()
{
    int a,b,c,d,e,f;
    int s,h1,m1,s1;
    
    while (scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)!=EOF)
    {
        s=3600*a+60*b+c+3600*d+60*e+f;
        h1=s/3600;
        m1=(s%3600)/60;
        s1=((s%3600)%60);
        printf("%d %d %d\n",h1,m1,s1);
    }
    
    return 0;
}