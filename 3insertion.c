#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void insertion(int a[],int n,char fn[])
{
    int i,j,temp,c = 0;
    for(i = 1;i <= n-1;i++)
    {
        temp = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
            c++;
        }
        if(j == -1)
        {
            continue;
        }
        c++;
        a[j+1] = temp;
    }
    FILE *f = fopen(fn,"a");
    fprintf(f,"%d\t%d\n",n,c);
    fclose(f);
}

void main()
{
    int i,n;
    srand(time(NULL));
    system("del -f insertion_*.txt");
    for(n = x;n <= y;n += incre)
    {
        int a[n];
        for(i = 0;i < n;i++)
           a[i] = i+1;
        insertion(a,n,"insertion_best.txt");
        for(i = 0;i < n;i++)
           a[i] = rand()%100;
        insertion(a,n,"insertion_avg.txt");
        for(i = 0;i < n;i++)
           a[i] = n - i;
        insertion(a,n,"insertion_worst.txt");
    }
}