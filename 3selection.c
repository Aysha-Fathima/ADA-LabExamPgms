#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void selection(int a[],int n,char fn[])
{
    int i,j,small,c;
    c = 0;
    for(i = 0;i < n-1;i++)
    {
        small = i;
        for(j = i+1;j < n;j++)
        {
            c++;
            if(a[j] < a[small])
            {
                small = j;
            }
        }
            int temp = a[j];
            a[j] = a[small];
            a[small] = temp;
    }
    printf("%d\t",c);
    FILE *f ;
    f = fopen(fn,"a");
    fprintf(f,"%d\t%d\n",n,c);
    fclose(f);
}

void main()
{
    int n,i;
    srand(time(NULL));
    system("del -f sel*.txt");
    for(n = x;n <= y;n+=incre)
    {
        int a[n];
        for(i = 0;i < n;i++);
        {
            a[i] = i+1;
        }
        selection(a,n,"selbest.txt");
        for(i = 0;i < n;i++);
        {
            a[i] = rand()%n;
        }
        selection(a,n,"selavg.txt");
        for(i = 0;i < n;i++);
        {
            a[i] = n-i;
        }
        selection(a,n,"selworst.txt");
    }
}
