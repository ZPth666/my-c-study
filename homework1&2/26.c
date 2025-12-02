#include <stdio.h>
int main()
{
    int m;
    int d;
    int date [12]={31,28,31,30,31,30,31,31,30,31,30,31};
    while (scanf("%d %d",&m,&d)!=EOF)
    {
        int sum=0;
        for (int i = 0; i < m-1; i++)
        {
            sum+=date[i];
        }
        if((sum+d+4)%7 == 0)
        {
            printf("7\n");
        }
        else
        printf("%d\n",(sum+d+4)%7);
    }
    return 0;
}