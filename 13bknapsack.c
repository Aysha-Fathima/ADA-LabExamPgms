#include<stdio.h>
#include<stdlib.h>

struct item
{
    int num,wt,val;
};
typedef struct item it;
int c = 0;
int max(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int mfk(int i,int j,it knap[],int a[50][50])
{
    c++;
    if(a[i][j] == -1)
    {
        if((j - knap[i].wt) < 0)
        {
            a[i][j] = mfk(i-1,j,knap,a);
        }
        else
        {
            a[i][j] = max(mfk(i-1,j,knap,a),(knap[i].val+mfk(i-1,j-knap[i].wt,knap,a)));
        }
    }
    return a[i][j];
}
void main()
{
    int n,i,j,k,w;
    printf("enter the numer of items\n");
    scanf("%d",&n);
    it knap[n+1];
    for(i = 1;i <= n;i++)
    {
        printf("item %d: enter weight and value\n",i);
        scanf("%d%d",&knap[i].wt,&knap[i].val);
        knap[i].num = i;
    }
    printf("enter weight\n");
    scanf("%d",&w);
    printf("\nitem\tweight\tvalue\n");
    for(i = 1;i <= n;i++)
    {
        printf("%d\t%d\t%d\n",knap[i].num,knap[i].wt,knap[i].val);
    }
    int s[10],a[50][50];
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= w;j++)
        {
            if(i == 0 || j == 0)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = -1;
            }
        }
    }
    int sol;
    sol = mfk(n,w,knap,a);
    printf("\n");
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= w;j++)
        {
            printf("%2d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("optimal value is %d\noperational count is %d\n",sol,c);
    i = n;k = 0;j = w;
    while(j != 0 && i >= 1)
    {
        if(a[i][j] != a[i-1][j])
        {
            s[k] = i;
            k++;
            j = j-knap[i].wt;
        }
        i--;
    }
    printf("the composition of items is\n");
    for(i = 0;i < k;i++)
    {
        printf("%d\t",s[i]);
    }
}