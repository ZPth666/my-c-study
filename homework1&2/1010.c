#include <stdio.h>
int main()
{
    int n;

    while (scanf("%d",&n)!=EOF)
    {
        int s1[100];
        int m=0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&s1[i]);
        }
        
        for (int a = 0; a < n; a++)
        {
            if (s1[a]<60)
            {
                m++;
            }
            
        }
        printf("%d\n",m*200);
    }
    return 0;
}