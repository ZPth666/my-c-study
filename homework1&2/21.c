/*小南还想让你判断 ASCII 值的奇偶性：任意输入一个字符，判断其 ASCII 值是否是奇数，若是，输出YES，否则，输出NO。

例如，字符'A'的 ASCII 值是 65，则输出YES，字符'B'的 ASCII 值是 66，则输出NO。

输入描述
多样例，每个样例输入一个字符。

输出描述
对于每个样例输入，如果其 ASCII 值为奇数，则输出YES；否则，输出NO。

输入样例
A
B
输出样例
YES
NO
提示*/
#include <stdio.h>
int main()
{
    char n;
    while (scanf("%c",&n)!=EOF)
    {
        if (n=='\n')
        {
            continue;
        }
        if (n%2==0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}