#include <stdio.h>
int main()
{
    int i;
    int n = 0;
    int m = 0;
    while (scanf("%d",&n)!=EOF)
    {
        if (n<1 || n>1000000)
        {
            break;
        }
        
        for ( i = 6; i <= 4285716; i++)
        {
            int a = i%10;
            int b = (i/10)%10;
            int c = (i/100)%10;
            if (i%6==0 || a==6 || b==6 || c==6)
            {
                m++;
                if (m==n)
                {
                    printf("%d\n",i);
                    m=0;
                    break;
                }
            
            }
        }
    }
    return 0;
}