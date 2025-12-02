/*题目描述
编写程序找出m个实数中最大那个数。

输入描述
多样例。样例的个数由第一行输入的正整数n决定。

接下来的n行，每行输入的第一个整数m ( 1 ≤ m ≤ 100 )，表示要比较的实数个数。然后后面是m个用空格分开的实数。

输出描述
输出n行。每个样例输出m个实数中最大的那个数，并且保留两位小数。

输入样例
2
3 170.00 165.00 180.00
4 165.00 182.00 172.00 160.00
输出样例
180.00
182.00
*/
#include <stdio.h>
int sort(int m,double s[])
{
    for (int i = 1; i < m; i++)
    {
        if (s[0]<s[i])
        {
            s[0]=s[i];
        }
    }
    return s[0];
}

int main()
{
    double s[100];
    int n;
    int m;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&m);
        for (int p = 0; p < m; p++)
        {
            scanf("%lf",&s[p]);
        }
        printf("%.2f\n",sort(m,s));
    }
    return 0;
}