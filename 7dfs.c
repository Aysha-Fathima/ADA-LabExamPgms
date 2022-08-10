#include<stdio.h>
#include<stdlib.h>
#define max 50
int count = 0,order = 0,cyclic = 0,n,visited[max] = {0},a[max][max];

void dfs(int v)
{
    count++;
    visited[v] = 1;
    printf("-> %d ",v);
    for(int i = 0;i < n;i++)
    {
        order++;
        if(visited[i] && a[v][i])
        {
            cyclic = 1;
        }
        if(a[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
}
void main()
{
    int i,j,start;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //printf("enter the starting node\n");
    //scanf("%d",&start);
    dfs(0);
    if(count == n)
    printf("\ngraph is connected\n");
    else
    {
        printf("\ngraph is not connected\n");
        start = 0;
        while(count != n)
        {
            if(visited[start] != 1)
            {
                printf("\nstarting node %d\n",start);
                dfs(start);
            }
            start++;
        }
    }
    if(cyclic == 0)
    {
        printf("\ngraph is acyclic\n");
    }
    else
    {
        printf("\ngraph is cyclic\n");
    }
    printf("\norder of count is %d\n",order);
}