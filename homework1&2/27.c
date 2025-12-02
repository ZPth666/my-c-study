#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    int b=0;

    while (scanf("%d",&a)!=EOF)
    {
        for (int i = 6; i >=0; i--)
        {
            if ((a /(int)pow(2,i)) == 1)
            {
                b=i;
            }
            a = a%((int)pow(2,i));
        }
        printf("%d\n",(int)pow(2,b));
    }
    return 0;
}