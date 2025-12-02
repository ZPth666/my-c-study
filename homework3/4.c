/*就是统计两个整数x和y在相加时需要多少次进位，其中x和y满足0≤x,y≤ 109，你能帮他完成任务吗？

输入描述
多个样例。 每个样例输入1行，包括2个整数x和y(0≤x,y≤ 109)。

输出描述

每个样例输出一个整数，代表所需要的进位数。每个样例输出结果占一行。


输入样例
8 7
9 0
154 246
555 5555
123 594
输出样例
1
0
2
3
1
*/
#include <stdio.h>
void num(int *m,int n)
{
    for (int i = 0; i < 10; i++)
    {
        int c = 1;
        for (int a = 0; a < 9-i; a++)
        {
            c*=10;
        }
        m[i]=n/c;
        n=n%c;
    }
    
}

int compare(int *j,int *k)
{
    int sum=0;
    int flag=0;
    for ( int i = 9; i >= 0; i--)
    {
        if (j[i]+k[i]>=10)
        {
            sum++;
            flag=1;
            continue;
        }
        if (j[i]+k[i]==9 && flag==1)
        {
            sum++;
            flag=1;
            continue;
        }
        flag=0;
    }
    return sum;
}
int main()
{
    int p;
    int q;
    int s1[10];
    int s2[10];
    while (scanf("%d %d",&p,&q)!=EOF)
    {
        num(s1,p);
        num(s2,q);
        printf("%d\n",compare(s1,s2));
    }
    return 0;
}