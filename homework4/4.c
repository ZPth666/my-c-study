#include <stdio.h>
#include <string.h>
int main()
{
    char s[100000] = " ";
    scanf("%s",s);
    int len = strlen(s);
    int flag = 0;
    int f3 = 0;
    int f8 = 0;
    int f11 = 0;
    int f5 = 0;
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < len; i++)
    {
        sum+= s[i] - '0';
    }
    for (int i = 0; i < len;)
    {
        sum1+= s[i] - '0';
        i+=2;
    }
    for (int i = 1; i < len;)
    {
        sum2+= s[i] - '0';
        i+=2;
    }
    
    if (sum%3==0)
    {
        flag = 1;
        f3 = 1;
    }
    if ((sum1-sum2)%11==0)
    {
        flag = 1;
        f11 = 1;
    }
    if (s[len-1]=='0' || s[len-1]=='5')
    {
        flag = 1;
        f5 = 1;
    }
    if (len>3)
    {
        int m = s[len-3]-'0';
        for (int i = 2; i > 0 ; i--)
        {
            m = m*10+(s[len-i]-'0');
        }
        if (m%8==0)
        {
            flag = 1;
            f8 = 1;
        }
    }
    else
    {
        int m = s[0]-'0';
        for (int i = 0; i < len-1; i++)
        {
            m = m*10+(s[i+1]-'0');
        }
        if (m%8==0)
        {
            flag = 1;
            f8 = 1;
        }
    }
    
    if (flag)
    {
        printf("Yes\n");
        if (f3)
        {
            printf("3 ");
        }
        if (f5)
        {
            printf("5 ");
        }
        if (f8)
        {
            printf("8 ");
        }
        if (f11)
        {
            printf("11 ");
        }
    }
    else
    printf("No");
    
    return 0;
}