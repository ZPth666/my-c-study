#include <stdio.h>
#include <string.h>
void cal(char *sum,char *n1,char *n2,int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        sum[i]+=n1[i]+n2[i]-48;
        if (i==0 && sum[i]>'9')
        {
            sum[i]-=10;
            sum[n]=1;
        }
        if (i>0 && sum[i]>'9')
        {
            sum[i]-=10;
            sum[i-1]++;
        }
    }
}
void store(int n,char *n1,char *n2)
{
    for (int i = 0; i < n; i++)
    {
        n2[i]=n1[n-i-1];
    }
}
int main()
{
    char n1[1005]="";
    while (scanf("%s",n1)!=EOF)
    {
        char n2[1005]="";
        char sum[1005]="";
        int flag=1;
        int len=strlen(n1);
        if (n1[0]=='-')
        {
            len--;
            for (int i1 = 0; i1 < len; i1++)
            {
                n1[i1]=n1[i1+1];
            }
            flag=0;
        }

        store(len,n1,n2);
        cal(sum,n1,n2,len);
        if (flag==0)
        {
            printf("-");
        }
        if (sum[len]==1)
        {
            printf("1");
        }
        for (int i = 0; i < len; i++)
        {
            printf("%c",sum[i]);
        }
        printf("\n");
    }
    return 0;
}