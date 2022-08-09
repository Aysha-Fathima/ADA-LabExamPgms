#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,j;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    int a[n][n];
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
            for(int k = 0;k < n;k++)
            {
                a[i][j] = a[i][j] < (a[i][k] + a[k][j]) ? a[i][j] : (a[i][k] + a[k][j]);
            }
        }
    }
    printf("Weight closure is\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}