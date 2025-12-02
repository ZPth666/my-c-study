#include <stdio.h>
int main()
{
    int h;
    int m;
    char q[5];
    while (scanf("%d:%d",&h,&m)!=EOF)
    {
        scanf("%s",q);

        if ((q[0]=='p'|| q[0]=='P') && h!=12)
        {
            h+=12;
        }
        if ((q[0]=='a' || q[0]=='A')&& h==12)
        {
            h-=12;
        }
        
        printf("%02d:%02d\n",h,m);        
    }
    
}