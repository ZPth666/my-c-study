/*题目描述
计算下面函数的值

y=cos(x+3.0) 当0<=x<10;

y=(cos(x+7.5))2 当10<=x<20;

y=(cos(x+4.0))4 当20<=x<30;

如果x<0或者x>=30，输出“Not define”，否则输出y的值，保留5位小数。

输入描述
多组样例，每组样例输入一个整数x。

输出描述
对于每个样例，输出相应的结果。每个样例输出结果占一行。

输入样例
40
12
输出样例
Not define
0.63332
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int x = 0;
    int m = 0;
    while (scanf("%d",&x)!=EOF)
    {
        if (x<0 || x>=30)
        {
            printf("Not define\n");
            continue;
        }
        else if (0<=x && x<10)
        {
            m=1;
        }
        else if (10<=x && x<20)
        {
            m=2;
        }
        else if (20<=x && x<30)
        {
            m=3;
        }
        
        double y;
        switch (m)
        {
        case 1:
            y=cos(x+3.0);
            break;
        case 2:
            y=pow((cos(x+7.5)),2);
            break;
        case 3:
            y=pow((cos(x+4.0)),4);
            break;
        default:
            break;
        }

        printf("%.5f\n",y);
    }
    
}