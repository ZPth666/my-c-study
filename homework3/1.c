#include <stdio.h>
int main()
{
    int mon = 0;
    while(scanf("%d",&mon)!=EOF)
    {
        int sum = 0;
        int tax[6] = {36000*0.03,108000*0.1,156000*0.2,120000*0.25,240000*0.3,300000*0.35};

        if (0<=mon && mon<=36000)
        {
            sum = mon*0.03;
        }
        else if (mon<0)
        {
            continue;
        }
        else if (36000<mon && mon<=144000)
        {
            sum = tax[0]+(mon-36000)*0.1;
        }
        else if (144000<mon && mon<=300000)
        {
            sum = tax[0]+tax[1]+(mon-144000)*0.2;
        }
        else if (300000<mon && mon<=420000)
        {
            sum = tax[0]+tax[1]+tax[2]+(mon-300000)*0.25;
        }
        else if (420000<mon && mon<=660000)
        {
            sum = tax[0]+tax[1]+tax[2]+tax[3]+(mon-420000)*0.3;
        }
        else if (660000<mon && mon<=960000)
        {
            sum = tax[0]+tax[1]+tax[2]+tax[3]+tax[4]+(mon-660000)*0.35;
        }
        else if (960000<mon)
        {
            sum = tax[0]+tax[1]+tax[2]+tax[3]+tax[4]+tax[5]+(mon-300000)*0.45;
        }
        printf("%d\n",sum);
    }
    return 0;
}