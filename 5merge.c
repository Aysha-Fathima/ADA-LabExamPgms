#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void arrange(int a[],int n)
{
    if(n == 1 || n == 2)
    {
        return;
    }
    int i,temp;
    for(i = 1;i < n-1;i++)
    {
        temp = a[i];
        a[i] = a[n-i];
        a[n-i] = temp;
    }
}
void merge(int a[],int b[],int c[],int m1,int m2,int *cnt)
{
    int i = 0,j = 0,k = 0;
    while(i < m1 && j < m2)
    {
        *cnt += 1;
        if(b[i] <= c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    if(i == m1)
    {
        while(j < m2)
        {
            a[k] = c[j];
            j++;k++;
        }
    }
    else
    {
        while(i < m1)
        {
            a[k] = b[i];
            i++;k++;
        }
    }
}
void mergesort(int a[],int n,int *cnt)
{
    if(n > 1)
    {
        int m1,m2,i;
        m1 = n/2;m2 = n - m1;
        int b[m1],c[m2];
        for(i = 0;i < m1;i++)
        {
            b[i] = a[i];
        }
        for(i = 0;i < m2;i++)
        {
            c[i] = a[i+m1];
        }
        mergesort(b,m1,cnt);
        mergesort(c,m2,cnt);
        merge(a,b,c,m1,m2,cnt);
    }
}
void main()
{
    system("del -f merge_*.txt");
    int n,i,cnt = 0;
    srand(time(NULL));
    FILE *f1,*f2,*f3;
    for(n = x;n <= y;n += 10)
    {
        int a1[n],a2[n],a3[n];
        for(i = 0;i < n;i++)
        {
            a1[i] = i+n+1;
            a2[i] = rand() % 1000;
        }
        int e = 2,o = 1,b[n/2];
        for(i = 0;i < n/2;i++)
        {
            a3[i] = e;
            e += 2;
            b[i] = o;
            o += 2;
        }
        arrange(a3,n/2);
        arrange(b,n/2);
        for(i = 0;i < n/2;i++)
        {
            a3[i+(n/2)] = b[i]; 
        }
        f1 = fopen("merge_best.txt","a");
        cnt = 0;
        mergesort(a1,n,&cnt);
        fprintf(f1,"%d\t%d\n",n,cnt);
        fclose(f1);

        f2 = fopen("merge_avg.txt","a");
        cnt = 0;
        mergesort(a2,n,&cnt);
        fprintf(f2,"%d\t%d\n",n,cnt);
        fclose(f2);

        f3 = fopen("merge_worst.txt","a");
        cnt = 0;
        mergesort(a3,n,&cnt);
        fprintf(f3,"%d\t%d\n",n,cnt);
        fclose(f3);
    }
}