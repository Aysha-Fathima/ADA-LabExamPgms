#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
#define incre 10

void string(int T[],int P[],int n,int m,char fn[])
{
    int i,j,c = 0;
    for(i = 0;i < n-m+1;i++)
    {
        j = 0;
        while(j != m && P[j] == T[i+j])
        {
            c++;
            j++;
        }
        if(j == m)
        {
            FILE *f = fopen(fn,"a");
            fprintf(f,"%d\t%d\n",m,c);
            fclose(f);
            return;
        }
        c++;
    }
    FILE *f = fopen(fn,"a");
    fprintf(f,"%d\t%d\n",m,c);
    fclose(f);
}

void main()
{
    int n,i,T[100];
    system("del -f str_*.txt");
    for(i = 0;i < y;i++)
    {
        T[i] = 0;
    }
    for(n = x;n <= y;n += 10)
    {
        int P[n];
        for(i = 0;i < n;i++)
          P[i] = 0;
        string(T,P,100,n,"str_best.txt");
        for(i = 0;i < n;i++)
          if(i%2 == 0) P[i] = 0;
          else P[i] = 1;
        string(T,P,100,n,"str_avg.txt");
        for(i = 0;i < n-1;i++)
           P[i] = 0;
        P[i] = 1;
        string(T,P,100,n,"str_worst.txt");
    }
}