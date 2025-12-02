/*
题目描述
统计每个元音字母在字符串中出现的次数。

输入描述
输入数据首先包括一个整数n，表示测试实例的个数，然后是n行长度不超过100的字符串。

输出描述
对于每个测试实例输出5行，格式如下： a:num1 e:num2 i:num3 o:num4 u:num5 多个测试实例之间由一个空行隔开。 请特别注意：最后一块输出后面没有空行：）

输入样例
2
aeiou
my name is ignatius
输出样例
a:1
e:1
i:1
o:1
u:1

a:2
e:1
i:3
o:0
u:1*/
#include <stdio.h>
#include <string.h>
void judge(char s,char alp,int *m)
{
    if (s==alp)
    *m+=1;
}
void print(char alp,int *m)
{
    printf("%c:%d\n",alp,*m);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i2 = 0; i2 < n; i2++)
    {
        char s[1000]=" ";
        int a = 0;
        int e = 0;
        int i = 0;
        int o = 0;
        int u = 0;
        if (i2==0); getchar();
        fgets(s,1000,stdin);
        int len = strlen(s);
        for (int i1 = 0; i1 < len; i1++)
        {
            judge(s[i1],'a',&a);
            judge(s[i1],'e',&e);
            judge(s[i1],'i',&i);
            judge(s[i1],'o',&o);
            judge(s[i1],'u',&u);
        }
        print('a',&a);
        print('e',&e);
        print('i',&i);
        print('o',&o);
        if (i2!=n-1) 
        {
            print('u',&u);
            printf("\n");
        }
        else printf("u:%d",u);
    }
    
}