#include <stdio.h>
int root(int n)
{
    int sq = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((n/i) < i)
        {
            sq = i;
            if (n==(i-1)*(i-1))
            {
                sq--;
            }
            break;
        }
    }
    return sq;
}
int fbnq(int x)
{
    int m =1;
    int n =1;
    int mid;
    int y =1;
    for (int i = 0; i < 30; i++)
    {
        if (n>=x)
        {
            //printf("%d\n",y);
            break;
        }
        mid = n;
        n = m+n;
        m =mid;
        y++;
    }
    return y;
}
int main()
{
    int x;
    int n;
    int num;
    while (scanf("%d",&x)!=EOF)
    {
        //printf("%d\n",fbnq(x));
        if (x==1)
        {
            printf("  *\n");
            printf(" / \\\n");
            printf("*---*\n");
            continue;
        }
        
        n = fbnq(x);
        num = root(n);
        for (int i = 0; i < num; i++)
        {
            for (int i2 = 0; i2 < (num-i)*2; i2++)
            {
                printf(" ");
            }
            for (int a = 0; a < i; a++)
            {
                printf("*---");
            }
            printf("*\n");

            if (i<num-1)
            {   
                for (int i5 = 0; i5 < (num-i)*2-1; i5++)
                {
                    printf(" ");
                }
                
                for (int i1 = 0; i1 <=i; i1++)
                {
                    printf("/ \\");
                    if (i1<i)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        int rest = n-(num-1)*(num-1);
        int l = (rest+1)/2;
        int flag = rest%2;
        for (int i3 = 0; i3 < l; i3++)
        {
            printf(" / \\");
        }
        if (flag==0)
        {
            printf(" /");
        }
        printf("\n");
        for (int i4 = 0; i4 < l; i4++)
        {
            printf("*---");
        }
        printf("*\n");
    }
    return 0;
}
