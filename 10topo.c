#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,k,n,flag = 0;
    printf("enter number of vertices\n");
    scanf("%d",&n);
    int *in,a[n][n],vis[n];
    in = (int *)calloc(sizeof(int), n);
    in[0] = 0;
    printf("enter adjacency matrix\n");
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
            in[i] += a[j][i];
        }
    }
    for(i = 0;i < n;i++)
    {
        if(in[i] == 0)
        {
            flag = 1;
        }
        vis[i] = 0;
    }
    if(flag == 0)
    {
        printf("it is not a DAG\n");
        exit(0);
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(!vis[j] && !in[j])
            {
                vis[j] = 1;
                printf("%d -> ",j);
                for(k = 0;k < n;k++)
                {
                    if(a[j][k])
                    {
                       a[j][k] = 0;
                       in[k]--;
                    }
                 }
            }
        }
    }
}
