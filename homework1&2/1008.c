#include <stdio.h>
int main()
{
    int n;

    while (scanf("%d",&n)!=EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int a = 0; a < n; a++)
            {
                if (n>0 && n<=26)
                {
                    printf("%c",65+i);
                }
            }
            printf("\n");
        }
        
    }
    
    return 0;
}