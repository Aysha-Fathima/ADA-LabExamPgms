#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void bubble(int a[],int n,char fn[])
{
    int i,j,c = 0,flag = 0,temp;
    for(i = 0;i < n-1;i++)
    {
        for(j = 0;j < n-1-i;j++)
        {
            c++;
            if(a[j] > a[j+1])
            {
                flag = 1;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag == 0)
        {
            FILE *f = fopen(fn,"a");
            fprintf(f,"%d\t%d\n",n,c);
            fclose(f);
            return;
        }
    }
    FILE *f = fopen(fn,"a");
    fprintf(f,"%d\t%d\n",n,c);
    fclose(f);
}

void main()
{
    int n,i;
    system("del -f bubble_*.txt");
    srand(time(NULL));
    for(n = x;n <= y;n += incre)
    {
        int a[n];
        for(i = 0;i < n;i++)
           a[i] = i+1;
        bubble(a,n,"bubble_best.txt");
        for(i = 0;i < n;i++)
           a[i] = rand()%100;
        bubble(a,n,"bubble_avg.txt");
        for(i = 0;i < n;i++)
           a[i] = n-i;
        bubble(a,n,"bubble_worst.txt");
    }
}