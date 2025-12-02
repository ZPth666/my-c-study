#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int l;
    int r;
}set;
int comp(void const*a,void const*b)
{
    set*s1 = (set*)a;
    set*s2 = (set*)b;
    return s1->l - s2->l;
}
int main()
{
    char s[100000] = " ";
    int zuo[50000] = {0};
    set match[50000];
    while(scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        int n = 0;
        int m = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i]=='(' && zuo[n]==0)
            {
                zuo[n++] = i+1;
            }
            if(s[i]==')')
            {
                match[m].l = zuo[n-1];
                match[m].r = i+1;
                zuo[n-1] = 0;
                n--;
                m++;
            }
        }
        
        qsort(match,m,sizeof(set),comp);
        
        for(int i = 0; i < m; i++)
        {
            printf("%d %d\n",match[i].l,match[i].r);
        }
        memset(s,0,sizeof(char));
        memset(match,0,sizeof(set));
        memset(zuo,0,sizeof(int));
    }
    return 0;
}