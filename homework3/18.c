#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int direction =1000;
        char d;
        for (int i = 0; i < n; i++)
        {
            scanf("\n%c",&d);
            if (d=='L')
            {
                direction++;
            }
            if (d=='R')
            {
                direction--;
            }
        }
        if (direction%4==0)
        {
            printf("N\n");
        }
        else if (direction%4==1)
        {
            printf("W\n");
        }
        else if (direction%4==2)
        {
            printf("S\n");
        }
        else if (direction%4==3)
        {
            printf("E\n");
        }
        
    }
    return 0;
}