#include <stdio.h>
#include <string.h>
int main()
{
    char s1[100000]={0};
    int len1;
    int flag=1;
    int m=0;
    int i;

    scanf("%s",s1);//输入字符串
    len1=strlen(s1);


    while (flag==1)//进行反复操作的条件判定
    {
        for (i = 0; i < len1; i++)
        {
            if (s1[i]==s1[i+1])
            {
                i++;
                continue;
            }
            s1[m++]=s1[i];
            //printf("%c\n",s2[m]);
        }
        len1=m;

        if (m==1)
        {
            break;
        }
        else
        { 
            for (int c = 0; c < m-1; c++)//遍历新字符串，检查是否仍需要循环
            {
                if (s1[c]==s1[c+1])
                {
                    flag=1;//若需要继续循环，则初始化数据
                    m=0;
                    break;
                }
                flag=0;
            }  
        }
    }
    
    for (int a = 0; a < len1; a++)//输出重新排序的字母
    {
        printf("%c",s1[a]);
    }
    
    
    return 0;
}