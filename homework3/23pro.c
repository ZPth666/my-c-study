#include <stdio.h>
#include <string.h>
#include <math.h>
int isprime(int x)
{
    int ret=1;
    int i;
    if (x==1 || (x%2==0 && x!=2))
    {
        ret=0;
    }
    else
    {
        for ( i = 3; i <= sqrt(x); i+=2)
        {
            if (x%i==0)
            {
                ret=0;
                break;
            }
        }
    }   
    return ret;
}
void turn(int *s0,char *s,int n, int num)
{
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int q = 0; q < num; q++)
        {
            if (s[l]=='\000')
            {
                break;
            }
           sum = sum*10 + (s[l++]-'0');
        }
        s0[i] = sum;
    }
}
int main()
{
    char s[10000]="";
    int num;
    while (scanf("%s %d",s,&num)!=EOF)
    {
        int s1[10000]={0}; 
        int s2[10000]={0}; 
        int s3[10000]={0}; 
        int s4[10000]={0};
        int s0[10000]={0};
        int len = strlen(s);
        int n = len/num;
        if (len%num != 0)
        n++;
        turn(s0,s,n,num); 
        int max = 0;
        int length = 0;
        //判断一类
        for (int i = 0; i < n; i++)
        {
            if (isprime(s0[i]))
            {
                s1[length++] = s0[i];
                s0[i] = 0;
            }
        }
        max = length;
        length = 0;
        //判断二类
        int nc = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int q = 0; q < num; q++)
            {
                if (s[nc]=='\000')
                {
                    break;
                }
                sum += s[nc++]-'0';
            }
            if (isprime(sum) && s0[i]!=0)
            {
                s2[length++] = s0[i];
                s0[i] = 0;
            }
        }
        if (length>max)
        {
            max = length;
        }
        length = 0;
        //判断三类
        int q;
        nc = 0;
        for ( int i = 0; i < n; i++)
        {
            int flag = 0;
            for ( q = 0; q < num; q++)
            {
                if (isprime(s[nc]-'0') && s0[i]!=0)
                {
                    s3[length++] = s0[i];
                    s0[i] = 0;
                    flag = 1;
                    break;
                }
                nc++;
            }
            if (flag)
            {
                nc += num-q;
            }
        }
        if (length>max)
        {
            max = length;
        }
        length = 0;
        //判断四类
        for (int i = 0; i < n; i++)
        {
            if (s0[i]!=0)
            {
                s4[length++] = s0[i];
            }
        }
        if (length>max)
        {
            max = length;
        }
        length = 0;
        //计算k值
        int k;
        for (int i2 = 1; i2 <= 100; i2++)
        {
            if (max <= i2*i2)
            {
                k= i2*2+1;
                break;
            }
        }
        //开始填充
        int form[k][k];//填充*
        for ( int i = 0; i < k; i++)
        {
            form[i][i] = -1;
            form[i][k-1-i] = -1;
        }
        int mid = (k+1)/2;
        int row = 0;
        //填充上三角
        while (row<mid)
        {
            for (int i = 0; i < k-2-2*row; i++)
            {
                form[row][row+i+1] = s1[length++];
            }
            row++;
        }
        length = 0;
        row = 0;
        //填充左三角
        int u = mid-1;
        for (int i = 1; i < k-1; i++)
        {
            if(i<mid)
            {
                for (int q = 0; q < i; q++)
                {
                    form[i][q] = s2[length++];
                }
            }
            else
            {
                for (int p = 0; p < u-1; p++)
                {
                    form[i][p] = s2[length++];
                }
                u--;
            }
        }
        length = 0;
        //填充右三角
        u = mid-1;
        int u1 = 0;
        for (int i = 1; i < k-1; i++)
        {
            if(i<mid)
            {
                for (int q = 0; q < i; q++)
                {
                    form[i][k-i+q] = s3[length++];
                }
            }
            else
            {
                for (int p = 0; p < u-1; p++)
                {
                    form[i][mid+1+p+u1] = s3[length++];
                }
                u--;
                u1++;
            }
        }
        length = 0;
        //填充下三角
        for (int i = 0; i < mid-1; i++)
        {
            for (int q = 0; q < 1+2*i; q++)
            {
                form[mid+i][mid-1-i+q] = s4[length++];
            }
        }
        //输出
        for (int i = 0; i < k; i++)
        {
            for (int i1 = 0; i1 < k; i1++)
            {
                if (form[i][i1]==-1)
                {
                    printf("    *");
                }
                else
                {
                    printf("%5d",form[i][i1]);
                }
            }
            printf("\n");
        }
        printf("\n");
        memset(s,0,sizeof(s));
    }
    return 0;
}