#include <stdio.h>
#include <math.h>
int main()
{
    int s[1000] = {0};
    for(int i = 1; i <= 1000; i++)//构造AB类表
    {
        int na;
        int n1 = 0;
        int flag = 0;
        int rest = i;
        for(int p = 9; p >= 0; p--)
        {
            if(rest/(int)pow(2,p)==1 && flag==0)
            {
                na = p+1;
                flag = 1;
            }
            if(rest/(int)pow(2,p)>0)
            {
                n1++;
                rest %= (int)pow(2,p);
            }
        }
        if(n1>na/2) s[i-1] = 1;
    }
    
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int numa = 0;
        int numb = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (s[i]==1) numa++;
            if (s[i]==0) numb++;
        }
        
        printf("%d %d\n",numa,numb);
    }
    return 0;
}