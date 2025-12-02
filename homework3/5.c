/*设计了一个平面魔方。平面魔方是一个n×n(2≤n≤ 10)的矩阵，最开始用数据1~n2填充。魔方的操作指令集如下：

（1）指令1：“L x y”表示矩阵的第x行循环左移y次；

（2）指令2：“R x y”表示矩阵的第x行循环右移y次；

（3）指令3：“U x y”表示矩阵的第x列循环上移y次；

（4）指令4：“D x y”表示矩阵的第x列循环下移y次；

其中矩阵的行号和列号x从1开始编号，满足1≤x≤n；移动次数y满足1≤y≤n−1。

说明：5个数据a1,a2,a3,a4,a5循环左移1次会变成a2,a3,a4,a5,a1。

要求：对给定的初始魔方，经过若干次操作后形成新的魔方，按行将新魔方的所有数字输出在一行上，数字之间用一个空格分开，行首和行末无空格。

输入描述
多个样例。每个样例输入包含1+m行：

第1行输入两个整数n(2≤n≤10)和m(1≤m≤100)，分别表示矩阵的大小和指令的条数。

接下来的m行是m条指令，输入格式为“C x y”，字母C(L或R或U或D)代表移动的方向，整数x(1≤x≤n)代表移动的行或列号，y(1≤y≤n−1)代表移动次数。

输出描述
对于每个样例，按行输出新魔方的所有数字。每个样例结果输出占一行。

输入样例
3 1
L 1 1
3 1
R 1 1
3 1
U 1 1
3 1
D 1 1
4 3
L 3 1
U 2 2
R 4 3
输出样例
2 3 1 4 5 6 7 8 9
3 1 2 4 5 6 7 8 9
4 2 3 7 5 6 1 8 9
7 2 3 1 5 6 4 8 9
1 11 3 4 5 14 7 8 10 2 12 9 6 15 16 13
*/
#include <stdio.h>
void turnh(int m,int mofang[m][m],int h,int num)
{
    for (int i = 0; i < num; i++)
    {
        int mid = mofang[h-1][0];
        for (int u = 0; u < m-1; u++)
        {
            mofang[h-1][u]=mofang[h-1][u+1];
        }
        mofang[h-1][m-1] = mid;
    }
}

void turnl(int m,int mofang[m][m],int l,int num)
{
    for (int i = 0; i < num; i++)
    {
        int mid = mofang[0][l-1];
        for (int u = 0; u < m-1; u++)
        {
            mofang[u][l-1]=mofang[u+1][l-1];
        }
        mofang[m-1][l-1] = mid;
    }
}

int main()
{
    int m;
    int n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        int mofang[m][m];
        for (int i = 0; i < m; i++)
        {
            for(int o = 0; o < m; o++)
            {
                mofang[i][o]= i*m +1+o;
            }
        }
        for (int p = 0; p < n; p++)
        {
            char turn;
            int x;
            int y;
            scanf("\n%c %d %d",&turn,&x,&y);
            if (turn == 'L')
            {
                turnh(m,mofang,x,y);
            }
            else if (turn == 'R')
            {
                turnh(m,mofang,x,m-(y%m));
            }
            else if (turn == 'U')
            {
                turnl(m,mofang,x,y);
            }
            else if (turn == 'D')
            {
                turnl(m,mofang,x,m-(y%m));
            }
        }
        for (int e = 0; e < m; e++)
        {
            for (int w = 0; w < m; w++)
            {
                printf("%d ",mofang[e][w]);
            }
        }
        printf("\n");
    }
    return 0;
}