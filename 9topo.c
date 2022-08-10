#include<stdio.h>
#include<stdlib.h>
int c = 0,a[50][50],n,vis[50] = {0},topo[50] = {0};

void dfs(int v)
{
    vis[v] = 1;
    for(int i = 0;i < n;i++)
    {
        if(a[v][i] && !vis[i])
        {
            dfs(i);
        }
    }
    c++;
    vis[v] = c;
    topo[c-1] = v+1;
}
void DFS()
{
    c = 0;
    for(int i = 0;i < n;i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
        }
    }
}
void main()
{
    int i,j,flag = 0;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    int in[n];
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
            in[i] += a[j][i];
        }
    }
    for(i = 0;i < n;i++)
    {
        if(in[i] == 0)
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("It is not a DAG\n");
        exit(0);
    }
    DFS();
    printf("the topological sorting is \n");
    for(i = n-1;i >= 0;i--)
    {
        printf("%d\t",topo[i]);
    }
    printf("\n");
}