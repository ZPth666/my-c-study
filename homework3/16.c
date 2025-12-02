#include <stdio.h>
void paint(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i==0 || i==n-1)
        {
            for (int i1 = 0; i1 < n-1; i1++)
            {
                printf("-");
            }
            printf("\n");
            continue;
        }
        if (i==1)
        {
            printf("\\");
            for (int i2 = 0; i2 < (n-3); i2++)
            {
                printf(" ");
            }
            printf("/\n");
            continue;
        }
        if (i<=(n-2)/2 && i>1)
        {
            for (int i3 = 0; i3 < i-1; i3++)
            {
                printf(" ");
            }
            printf("\\");
            for (int i4 = 0; i4 < n-1-i*2; i4++)
            {
                printf("*");
            }
            printf("/\n");
            continue;
        }
        if (i>(n-2)/2 && i<n-1)
        {
            for (int i5 = 0; i5 < n-2-i; i5++)
            {
                printf(" ");
            }
            printf("/");
            for (int i6 = 0; i6 < (2*i-n)/2; i6++)
            {
                printf(" ");
            }
            printf("*");
            for (int i7 = 0; i7 < (2*i-n)/2; i7++)
            {
                printf(" ");
            }
            printf("\\\n");
            continue;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }
    for (int i1 = 0; i1 < n; i1++)
    {
        paint(num[i1]);
        printf("\n");
    }
    return 0;
}