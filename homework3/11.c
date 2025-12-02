#include <stdio.h>
#include <stdlib.h>
int *isprime(int m)
{
    const int n = 300;
    int prime[n];
    int *prime1 = (int*)malloc(m*sizeof(int));
    int i1=0;

    for ( int i = 0; i < n; i++)
    {
        prime[i]=1;
    }
    for ( int x = 2; x < n; x++)
    {
        if (prime[x])
        {
            for ( int a = 2; a*x < n; a++)
            {
                prime[a*x]=0;
            }
        }
    }
    for (int b = 2; b < n; b++)
    {
        if (prime[b])
        {
            prime1[i1]=b;
            i1++;
            if (i1>=m)
            {
                break;
            }
        }
    }
    return prime1;
}

void paint(int m)
{
    int canva[600][600]={0};
    int x=299;
    int y=299;

    //规定方向，运动的循环周期是右，上，左，下
    int lx[]={1,0,-1,0};
    int ly[]={0,-1,0,1};
    int d=0;

    int max_x=299;
    int min_x=299;
    int max_y=299;
    int min_y=299;

    int *prime=isprime(m);

    for (int i = 0; i < m; i++)
    {
        int len =prime[i];
        for (int i1 = 0; i1 < len; i1++)
        {
            x+=lx[d];
            y+=ly[d];
            //更新边界
            if (x<min_x) min_x=x;
            if (x>max_x) max_x=x;
            if (y<min_y) min_y=y;
            if (y>max_y) max_y=y;
            
            if (d%2 == 0) canva[y][x] = 1;
            if (d%2 != 0) canva[y][x] = 2;
            
        }
        d = (d+1)%4;
    }

    free(prime);

    int row = max_y-min_y+1;
    int col = max_x-min_x+1;
    if (m<3)
    {
        col-=1;
        min_x+=1;   
    }
    for (int i2 = 0; i2 < row; i2++)
    {
        for (int i3 = 0; i3 < col; i3++)
        {   
            printf("%d",canva[min_y+i2][min_x+i3]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int m;
    while (scanf("%d",&m)!=EOF)
    {
        if (m<1 || m>50)
        {
            continue;
        }
        paint(m);
    }
    return 0;
}