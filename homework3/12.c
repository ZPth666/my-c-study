#include <stdio.h>
#include <stdlib.h>
int compare(const void*a,const void*b)
{
    return (*(int*)a-*(int*)b);
}
int judge(int *all,int *ji,int *ou,int n)
{
   int n1 =0;
   int n2 =0;
   for (int i = 0; i < n; i++)
   {
        if (all[i]%2==0)
        {
            ou[n2]=all[i];
            n2++;
        }
        else
        {
            ji[n1]=all[i];
            n1++;
        }
   }
   return n2;
}
void print(int *s,int nn)
{
    for (int i = 0; i < nn; i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    int n1=0;
    int n2=0;
    while (scanf("%d",&n)!=EOF)
    {
        int all[n];
        int ji[n];
        int ou[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&all[i]);
        }
        n1=n-judge(all,ji,ou,n);
        n2=judge(all,ji,ou,n);
        qsort(ou,n2,sizeof(int),compare);
        qsort(ji,n1,sizeof(int),compare);
        print(ji,n1);
        print(ou,n2);
        printf("\n");
    }
    return 0;
}