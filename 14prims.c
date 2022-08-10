#include<stdio.h>
#include<stdlib.h>
#define infinity 999
void main()
{
    int i,j,n,edge = 0;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    int vis[n],a[n][n];
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
        vis[i] = 0;
    }
    printf("minimum cost spanning tree is\n");
    int min_cost = 0;
    vis[0] = 1;
    while(edge < n-1)
    {
        int x = 0,y = 0,min = infinity;
        for(i = 0;i < n;i++)
        {
            if(vis[i] == 1)
            {
                for(j = 0;j < n;j++)
                {
                    if((vis[j] == 0) && (a[i][j] != 0))
                    {
                        if(min > a[i][j])
                        {
                            min = a[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            } 
        }
        printf("%d to %d min cost = %d\n",x+1,y+1,min);
        vis[y] = 1;
        min_cost += min;
        edge++; 
    }
    printf("\nminimum cost = %d\n",min_cost);
}