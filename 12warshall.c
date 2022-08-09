#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int n,cnt = 0;
    srand(time(NULL));
    FILE *f1;
    system("del war_*.txt");
    for(n = 3;n <= 15;n++)
    {
    int a[n][n],i,j,k;
    f1 = fopen("war_data.txt","a");
    fprintf(f1,"\nThe adjacency matrix\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            a[i][j] = rand()%2;
            fprintf(f1,"%d\t",a[i][j]);
        }
        fprintf(f1,"\n");
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(k = 0;k < n;k++)
            {
                cnt++;
                if(a[i][j] == 0 && a[i][k] == 1 && a[k][j] == 1)
                {
                    a[i][j] = 1;
                }
            }
        }
    }
    fprintf(f1,"\nTransitive closure is\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            fprintf(f1,"%d\t",a[i][j]);
        }
        fprintf(f1,"\n");
    }
    fclose(f1);
    f1 = fopen("war_count.txt","a");
    fprintf(f1,"%d\t%d\n",n,cnt);
    fclose(f1);
   }
}