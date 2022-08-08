#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

int sequential(int a[],int key,int n)
{
    int i,c = 0;
    for(i = 0;i < n;i++)
    {
        c++;
        if(a[i] == key)
        {
            return c;
        }
    }
    return c;
}

void main()
{
    FILE *f1,*f2,*f3;
    int i,n,c = 0,key,*a;
    system("del sb.txt");
    system("del sa.txt");
    system("del sw.txt");
    srand(time(NULL));
    for(i = x;i <= y;i += incre)
    {
        a = (int*)malloc(i*sizeof(int));
        for(int j = 0;j < i;j++)
        {
            a[j] = rand() % 100;
            //printf("%d\t",a[i]);
        }
    
        key = a[0];
        f1 = fopen("sb.txt","a");
        c = sequential(a,key,i);
        fprintf(f1,"%d\t%d\n",i,c);
        fclose(f1);

        key = a[i/2];
        f2 = fopen("sa.txt","a");
        c = sequential(a,key,i);
        fprintf(f2,"%d\t%d\n",i,c);
        fclose(f2);

        key = 9999;
        f3 = fopen("sw.txt","a");
        c = sequential(a,key,i);
        fprintf(f3,"%d\t%d\n",i,c);
        fclose(f3);
    }
}