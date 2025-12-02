#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    int s = 0;
    int n = 0;
    char sentence[1000]=" ";
    int interval[100]={0};
    while ((a = getchar())!=EOF)
    {
        if (a == ' ')//记录间隔位置
        {
            interval[n++] = s;
        }
        sentence[s++] = a;//输入字符数组
        if (a=='.'||a=='?'||a=='!')//判断终止位置
        {
            if (interval[0]==0) 
            {
                printf("%s",sentence);
                break;
            }
        
            for (int q = interval[n-1]+1; q < s-1; q++)//输出尾单词
            {
                printf("%c",sentence[q]);
            }
            printf(" ");
            for (int i = n-1; i > 0; i--)//输出中间单词
            {
                for (int p = interval[i-1]+1; p <= interval[i]; p++)
                {
                    printf("%c",sentence[p]);
                }
            }
            for (int u = 0; u < interval[0]; u++)//输出首单词
            {
                printf("%c",sentence[u]);
            }
            printf("%c",sentence[s-1]);
            break;
        }
        
    }
    return 0;
}