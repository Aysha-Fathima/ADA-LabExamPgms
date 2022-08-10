#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct item
{
    int num,val,wt;
};
typedef struct item it;

void main()
{
    srand(time(NULL));
    int n,w,cnt = 0;
    for(n = 3;n <= 5;n++)
    {
        int s[10];
        cnt = 0;
        it knap[n+1];
        w = rand()%5+2;
        printf("\nweight = %d\n\n",w);
        for(int i = 1;i <= n;i++)
        {
            knap[i].num = i;
            knap[i].wt = (rand()%(w-1))+1; 
            knap[i].val = rand()%25;
        }
        for(int i = 1;i <= n;i++)
        {
            printf("%d\t%d\t%d\n",knap[i].num,knap[i].wt,knap[i].val);
        }
        int a[n+1][w+1];
        for(int i = 0;i <= n;i++)
        {
            for(int j = 0;j <= w;j++)
            {
                if(i == 0 || j == 0)
                {
                    a[i][j] = 0;
                }
                else
                {
                    cnt++;
                    if(j - knap[i].wt < 0)
                    {
                        a[i][j] = a[i-1][j];
                    }
                    else
                    {
                        a[i][j] = a[i-1][j] >= (knap[i].val + a[i-1][j-knap[i].wt]) ? a[i-1][j] : (knap[i].val + a[i-1][j-knap[i].wt]);
                    }
                }
            }
        }
        printf("\n\n");
        for(int i = 0;i <= n;i++)
        {
            for(int j = 0;j <= w;j++)
            {
                printf("%2d\t",a[i][j]);
            }
            printf("\n");
        }
        printf("\nbasic operation count = %d\n",cnt);
        int i = n, k = 0, j = w;
        while(j != 0 && i >= 1)
        {
            if(a[i][j] != a[i-1][j])
            {
                s[k] = i;
                k++;
                j = j - knap[i].wt;
            }
            i--;
        }
        printf("\ncomposition of items\n");
        for(i = 0;i < k;i++)
        {
            printf("%d\t",s[i]);
        }
        printf("\n\n");
    }
}