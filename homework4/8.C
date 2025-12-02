/*
题目描述
数轴原点（坐标为0）有一个蠢蠢机器人，该机器人将执行一系列指令，你的任务是预测所有指令执行完毕之后它的位置。
（1）LEFT：往左移动一个单位
（2）RIGHT: 往右移动一个单位
（2）SAME AS i: 和第i 条执行相同的动作。输入保证i 是一个正整数，且不超过之前执行指令数。
输入描述
每一个测试文件包含多组测试数据，测试数据的组数由输入的第一行n（1≤n≤100）确定。每组测试数据的第一行为整数m（1≤m≤100）(1<=n<=100)，表示指令条数。接下来的m行，每行一条指令，指令按照输入顺序编号为1~m。
输出描述
对于每组测试数据，输出一个整数表示机器人的最终位置，每个结果占一行。每处理完一组数据，机器人应复位到数轴原点。
输入样例
2
3
LEFT
RIGHT
SAME AS 2
5
LEFT
SAME AS 1
SAME AS 2
SAME AS 1
SAME AS 4
输出样例
1
-5
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        int n1;
        scanf("%d",&n1);
        getchar();
        char s[20] = " ";
        int num[100] = {0};

        for (int p = 0; p < n1; p++)
        {
            fgets(s,20,stdin);
            if (s[0]=='L') num[p] = -1;
            if (s[0]=='R') num[p] = 1;
            if (s[0]== 'S')
            {
                int q;
                sscanf(s,"SAME AS %d",&q);
                num[p] = num[q-1];
            }
        }
        int sum = 0;
        for (int o = 0; o < n1; o++)
        {
            sum+=num[o];
        }
        printf("%d\n",sum);
    }
    return 0;
}
