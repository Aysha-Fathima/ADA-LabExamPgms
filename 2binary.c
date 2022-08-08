#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10
int c = 0;
int binary(int a[],int key,int low,int high)
{
    int mid,i;
        mid = (low + high) / 2;
        c++;
        if(high < low)
        {
            return -1;
        }
        else if(a[mid] == key)
        {
            return mid;
        }
        else if(a[mid] < key)
        {
            binary(a,key,mid+1,high);
        }
        else
        {
            binary(a,key,low,mid-1);
        }
}

void bs(int a[],int n,int key,char fn[])
{
    c = 0;
    FILE *fp = fopen(fn,"a");
    binary(a,key,0,n-1);
    fprintf(fp,"%d\t%d\n",n,c);
}

void main()
{
    system("del -f b*.txt");
    srand(time(NULL));
    for(int n = x;n <= y;n+=incre)
    {
        int a[n];
        for(int i = 0;i < n;i++)
        {
            a[i] = i+1;
        }
        bs(a,n,a[(n-1)/2],"bb.txt");
        bs(a,n,a[rand()%n],"ba.txt");
        bs(a,n,999,"bw.txt");
    }

}