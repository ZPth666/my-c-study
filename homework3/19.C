#include <stdio.h>
#include <string.h>
int main()
{
    char alp[1005]="";
    while (scanf("%s",alp)!=EOF)
    {
        int length = strlen(alp);
        for (int i = 0; i < length; i++)
        {
            if (alp[i]=='T')
            {
                alp[i]='U';
            }
            printf("%c",alp[i]);
        }
        printf("\n");
    }
    return 0;
}