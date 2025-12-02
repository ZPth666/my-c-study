#include <stdio.h>
#include <math.h>
int isprime2(int x,int knownprimes[],int number);
int isprime(int x)
{
    int ret=1;
    int i;
    if (x==1)
    {
        ret=0;
    }
    
    for ( i = 0; i < x; i++)
    {
        if (x%i==0)
        {
            ret=0;
            break;
        }
        
    }
    return ret;
    
}

int isprime1(int x)
{
    int ret=1;
    int i;
    if (x==1 || (x%2==0 && x!=2))
    {
        ret=0;
    }
    for ( i = 0; i < sqrt(x); i+=2)
    {
        if (x%i==0)
        {
            ret=0;
            break;
        }
        
    }
    return ret;
}

int isprime2(int x,int knownprimes[],int number)
{
    int ret=1;
    int i;
    for ( i = 0; i < number; i++)
    {
        if (x%knownprimes[i]==0)
        {
            ret =0;
            break;
        }
        
    }
    return ret;
}

int main()
{
    const int num=100;
    int prime[num];
    prime[0]=2;
    int count =1;
    int i=3;
    
    while (count<num)
    {
        if (isprime2(i,prime,count))
        {
            prime[count++]=i;
        }
        i++;
    }
    
    for ( int a = 0; a < num; a++)
    {
        printf("%d",prime[a]);
        if ((i+1)%5)
        {
            printf("\t");
        }
        else printf("\n");
    }
    return 0;
}