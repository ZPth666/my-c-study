#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int *a = (int*)malloc(n*sizeof(int));

        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        
        int m;
        scanf("%d",&m);
        int book;

        for (int i1 = 0; i1 < m; i1++)
        {
            scanf("%d",&book);
            for (int i2 = 0; i2 < n; i2++)
            {   
                int num =0;
                num+=a[i2];
                if (book<=num)
                {
                    printf("%d\n",i2+1);
                    break;
                }
            }
        }
        free(a);
    }
    return 0;
}