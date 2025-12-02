#include <stdio.h>
#include <string.h>
int num(char*csu,char al)
{
    int n=0;
    for (int i = 0; i < strlen(csu); i++)
    {
        if (csu[i] == al)
        {
            n++;
        }
    }
    return n;
}
int main()
{
    int a,b,c;
    int min=0;
    char csu[1005]="";
    while (scanf("%s",csu)!=EOF)
    {
        a=num(csu,'C');
        b=num(csu,'S');
        c=num(csu,'U');
        if (a<b)
        {
            if (a<c)
            {
                min=a;
            }
            else
            min=c;
        }
        else
        {
            if (b<c)
            {
                min=b;
            }
            else
            min=c;
        }
        printf("%d\n",min);
    }
    return 0;
}