#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[300];
    int length = 0;
    while(scanf("%s", a) != EOF)
    {
        length = strlen(a);
        for(int i = 0;i < length;i++)
            a[i] = '0' + (a[i] - 'a' + 1);
        for(int i=0,j=length-1;i<j;i++,j--)
        {
            char temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        for(int i=0;i<floor(length/2.0);i++)
        {
            a[2*i] -= 1;
            a[2*i+1] = '9' - a[2*i+1] + '0' + 1;
        }
        if(length % 2 == 1)
            printf("-0.%s\n", a);
        else    
            printf("0.%s\n", a);
    }
    return 0;
}