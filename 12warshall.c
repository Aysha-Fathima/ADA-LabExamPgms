#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,cnt = 0;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    int a[n][n],i,j,k;
    printf("enter the adjacency matrix\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(k = 0;k < n;k++)
            {
                if(a[i][j] == 0 && a[i][k] == 1 && a[k][j] == 1)
                {
                    a[i][j] = 1;
                }
            }
        }
    }
    printf("\nTransitive closure is\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}