/*题目描述
给定一个字符串 s，判断该串是否为回文串。

对于字符串 s[0, 1, …… , n-1]，它被视为回文串当且仅当满足如下条件：对于任意的 i ∈ {0, 1, …… , n-1}，s[i] == s[n-i-1] 均成立。

输入描述
多组数据。

每组输入一行，包含一个字符串 s，s中只包含小写字母与大写字母。(1 ≤ len(s) ≤ 10^4）

文件以EOF结束。

输出描述
每组输出一行，若 s 是回文串，则输出"Yes!"，否则输出"No!"。

输入样例
EOFOE
AzXxzA
输出样例
Yes!
No!*/
#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000]=" ";
    while (scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        int flag = 1;
        if (len%2==0)
        {
            for (int i = 0; i < len/2; i++)
            {
                if (s[i]!=s[len-1-i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < (len-1)/2; i++)
            {
                if (s[i]!=s[len-1-i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag==1) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}