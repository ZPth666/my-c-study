#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char number[21];
    int mark;
}grade;

int compare(const void*a,const void*b)
{
    grade *s1 = (grade *)a;
    grade *s2 = (grade *)b;
    if (s1->mark != s2->mark) //保证原有顺序
    {
        return s2->mark - s1->mark;  // 分数降序
    }
    return strcmp(s1->number, s2->number);     // 字典序升序
}


int main()
{
    int n=0;
    int m=0;
    int g=0;
    while (scanf("%d %d %d",&n,&m,&g)!=EOF)//多样例输入考生数，题目数，合格分数
    {
        if (n == 0)
        {
            break;
        }
        
        grade student[n];
        int title[10]={0};

        for (int i = 0; i < m; i++)//输入每题的分数
        {
            scanf("%d",&title[i]);
        }
        
        for (int i1= 0; i1< n; i1++)
        {
            int numofanswer;
            int mark1 = 0;
            scanf("%s %d",&student[i1].number,&numofanswer);//输入考生号至结构数组

            for (int i2 = 0; i2 < numofanswer; i2++)//计算考生得分
            {
                int numoftitle;
                scanf("%d",&numoftitle);

                for (int i3 = 1; i3 <= m; i3++)
                {
                    if (numoftitle == i3)
                    {
                        mark1 += title[i3-1];
                        break;
                    }
                    
                }
                
            }
            student[i1].mark=mark1;//输入考生得分至结构数组
        }
        
        int numofqualification = 0;
        for (int i4 = 0; i4 < n; i4++)
        {
            if (student[i4].mark >= g)
            {
                numofqualification++;
            }
            
        }
        printf("%d\n",numofqualification);

        
        qsort(student,n,sizeof(grade),compare);

        if (numofqualification != 0)
        {
            for (int i7 = 0; i7 < numofqualification; i7++)
            {
                printf("%s %d\n",student[i7].number,student[i7].mark);
            }
        }
    }
    return 0;
}