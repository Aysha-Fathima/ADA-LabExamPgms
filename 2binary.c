#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
#define incre 10

int binary(int a[],int key,int n)
{
    int mid,high = n-1,low = 0,c = 0,i;
    while(low <= high)
    {
        mid = (low + high) / 2;
        c++;
        if(a[mid] == key)
        {
            return c;
        }
        else if(a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid -1;
        }
    }
    return c;
}

void main()
{
    int n,*a,c,key,i;
    FILE *f1,*f2,*f3;
    system("del bb.txt");
    system("del ba.txt");
    system("del bw.txt");
    for(n = x;n <= y;n += incre)
    {
        a = (int*)malloc(n*sizeof(int));
        for(i = 0;i < n;i++)
        {
            a[i] = i + 10;
        }
        key = a[(n-1)/2];
        f1 = fopen("bb.txt","a");
        c = binary(a,key,n);
        fprintf(f1,"%d\t%d\n",n,c);
        fclose(f1);

        key = a[(n-3)/2]; //generate any random number from array
        f2 = fopen("ba.txt","a");
        c = binary(a,key,n);
        fprintf(f2,"%d\t%d\n",n,c);
        fclose(f2);

        key = a[0];
        f3 = fopen("bw.txt","a");
        c = binary(a,key,n);
        fprintf(f3,"%d\t%d\n",n,c);
        fclose(f3);
    }
}