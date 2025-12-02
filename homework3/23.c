#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{   int type;
    int num;
    char str;
}note;
int len1=0;
int len2=0;
int len3=0;
int len4=0;
int max(int n1,int n2)
{
    int max;;
    if (n1>n2)
    {
        max = n1;
    }
    else
    max = n2;
    return max;
}
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
void isprime1_2(int *s_int,int len,int *sign,int kind)
{
    for (int i = 0; i < len; i++)
    {
        if (isprime(s_int[i]) && sign[i]==0)
        {
            sign[i]=kind;
        }
    }
}
void isprime3(int *s_int,int len,int *sign,int num)
{
    for (int i = 0; i < len; i++)
    {
        int n = s_int[i];
        for (int i1 = 0; i1 < num; i1++)
        {
            if (isprime(n/(int)pow(10,num-1-i1)) && sign[i]==0)
            {
                sign[i]=3;
            }
            n%=(int)pow(10,num-1-i1);
        }
    }
}
void turn(char *s,int num,int n_int,int *s_int)
{
    int n_char = 0;
    for (int i = 0; i < n_int; i++)
    {
        s_int[i]=0;
        for (int i1 = 0; i1 < num; i1++)
        {
            s_int[i]+=(int)pow(10,num-1-i1)*(s[n_char]-48);
            n_char++;
        }
    }
}
int *turn1(int *s,int len)
{
    int *s_int1 = (int*)malloc(len*sizeof(int));
    for (int i = 0; i < len; i++)
    {
        s_int1[i] = s[i]/10 + s[i]%10;
    }
    return s_int1;
}
void sort(int *sign,int len,int *ints,int*s1,int*s2,int*s3,int*s4)
{
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    for (int i = 0; i < len; i++)
    {
        if (sign[i]==0)
        {
            s4[n4]=ints[i];
            n4++;
            len4++;
        }
        else if (sign[i]==1)
        {
            s1[n1]=ints[i];
            n1++;
            len1++;
        }
        else if (sign[i]==2)
        {
            s2[n2]=ints[i];
            n2++;
            len2++;
        }
        else if (sign[i]==3)
        {
            s3[n3]=ints[i];
            n3++;
            len3++;
        }
    }
}
int main()
{
    char s[10000]="";
    int num;
    while (scanf("%s %d",s,&num)!=EOF)
    {
        len1=0;
        len2=0;
        len3=0;
        len4=0;
        int s1[10000]={0}; 
        int s2[10000]={0}; 
        int s3[10000]={0}; 
        int s4[10000]={0}; 
        int len = strlen(s)/num;
        int *sign = (int*)malloc(len*sizeof(int));
        for (int i = 0; i < len; i++)
        sign[i]=0;
        int *s_int = (int*)malloc(len*sizeof(int));
        turn(s,num,len,s_int);
        isprime1_2(s_int,len,sign,1);
        isprime1_2(turn1(s_int,len),len,sign,2);
        isprime3(s_int,len,sign,num);
        sort(sign,len,s_int,s1,s2,s3,s4);
        //求出k
        int max_len = max(len1,max(len2,max(len3,len4)));
        int k;
        for (int i2 = 1; i2 <= 100; i2++)
        {
            if (max_len <= i2*i2)
            {
                k= i2*2+1;
                break;
            }
        }
        //初始化二维数组表格
        note form[k][k];
        for (int i = 0; i < k; i++)
        {
            for (int i1 = 0; i1 < k; i1++)
            {
                form[i][i1].type=0;
                form[i][i1].num=0;
            }
        }
        for (int i3 = 0; i3 < k; i3++)
        {
            form[i3][i3].str='*';
            form[i3][i3].type=1;
            form[i3][k-1-i3].str='*';
            form[i3][k-1-i3].type=1;
        }

        int n1 = 0;
        int n2 = 0;
        int n3 = 0;
        int n4 = 0;
        int flag;
        //填入1
        flag=0;
        for (int i4 = 0; i4 < (k-1)/2; i4++)
        {
            for (int i5 = 0; i5 < k-2-i4*2; i5++)
            {
                form[i4][i4+1+i5].num=s1[n1];
                n1++;
                if (n1>=len1)
                {
                    flag =1;
                    break;
                }
            }
            if (flag) break;
        }
        //填入2
        flag=0;
        for (int i4 = 0; i4 < k-2; i4++)
        {
            if(i4<=k/2)
            {
                for (int i5 = 0; i5 < i4+1; i5++)
                {
                    form[i4+1][i5].num=s2[n2];
                    n2++;
                    if (n2>=len2)
                    {
                        flag =1;
                        break;
                    }
                }
                if (flag) break;
            }    
            else
            {
                for (int i6 = 0; i6 < (k/2)+2-i4; i6++)
                {
                    form[i4+(k/2)+1][i6].num=s2[n2];
                    n2++;
                    if (n2>=len2)
                    {
                        flag =1;
                        break;
                    }
                }
                if (flag) break;
            }
        }
        //填入3
        flag=0;
        for (int i4 = 0; i4 < k-2; i4++)
        {
            if(i4<=k/2)
            {
                for (int i5 = 0; i5 < i4+1; i5++)
                {
                    form[i4+1][k-i4-1+i5].num = s3[n3];
                    n3++;
                    if (n3>=len3)
                    {
                        flag =1;
                        break;
                    }
                }
            }
            else
            {
               for (int i6= 0; i6 < (k/2)+2-i4; i6++)
                {
                    form[i4+(k/2)+1][k-1-i6].num = s3[n3];
                    n3++;
                    if (n3>=len3)
                    {
                        flag =1;
                        break;
                    }
                }
            }
        }
        //填入4
        flag=0;
        for (int i4 = 0; i4 < (k-1)/2; i4++)
        {
            for (int i5 = 0; i5 < k-4+i4*2; i5++)
            {
                form[(k/2)+1+i4][(k/2)-i4+i5].num = s4[n4];
                n4++;
                if (n4>=len1)
                {
                    flag =1;
                    break;
                }
            }
            if (flag) break;
        }
        //打印
        for (int i = 0; i < k; i++)
        {
            for (int i1 = 0; i1 < k; i1++)
            {
                if (form[i][i1].type==0)
                {
                    printf("%5d",form[i][i1].num);
                }
                else printf("%5c",form[i][i1].str);
            }
            printf("\n");
        }
        printf("\n");
        free(sign);
        free(s_int);
    }
    return 0;
}
    