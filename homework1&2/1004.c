#include <stdio.h>

void sort(int num[],int n)
{
    int flag=0;
    for (int i = 0; i < n ; i++)
    {
        for (int p = 0; p < n-1-i; p++)
        {
            if (num[p]>num[p+1])
            {
                int q=num [p];
                num[p]=num[p+1];
                num[p+1]=q;
            }
            
        }
        
    }
    for (int a = 0; a < n; a++)
            {
                if (num[a]>1e+06 || num[a]<-1e+06)
                {
                    flag=1;
                }
                if (flag==0)
                {
                    printf("%d",num[a]);
                    if (a!=n-1)
                    {
                        printf(" ");
                    }
                }
                
            }
    
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        
        
        if (n>0 && n<=100)
        {
            int number[n];

            for ( int i = 0; i < n; i++)
            {
                scanf("%d",&number[i]);
            }
        

            sort(number,n);
        
            printf("\n");
        }
    }
    
    return 0;
}