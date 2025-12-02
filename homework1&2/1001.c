#include <stdio.h>

int main ()
{
    int n,p,q;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("\n%d %d",&p,&q);
        printf("%d\n",p+q);
    }

    return 0;
    
}