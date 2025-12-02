#include <stdio.h>
int main()
{
    int year=0;

    while (scanf("%d",&year)!=EOF)
    {
        if (year>0 && year<3000)
        {
            if (year%4==0)
        {
                if (year%100==0 && year%400!=0)
                {
                    printf("N");
                }   
                else
                {
                    printf("Y");
                }
        }
        else
        {
            printf("N");
        }
        }
        else
        break;
    }
    return 0;
}