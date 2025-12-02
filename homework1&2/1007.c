#include <stdio.h>
int main()
{
    int n;
    
    while (scanf("%d",&n)!=EOF)
    {
        if (n>=1 && n<=26)
        {
            for (int i = 0; i < n; i++)
            {
                for (int a = 0; a < i+1; a++)
                {
                    printf("%c",65+i);
                }
                printf("\n");
            }
        
        }
    }
    
    return 0;
}