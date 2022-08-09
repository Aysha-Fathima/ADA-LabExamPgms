#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void swap(int a[],int i,int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int quick(int a[],int l,int r)
{
    int ans1,ans2,count = 0;
    if(l >= r)
    {
        return count;
    }
    int p = a[l],i,j;
    i = l + 1;
    j = r;
    while(i <= j)
    {
        while(a[i] < p)
        {
            count++;
            i++;
        }
        count++;
        while(a[j] > p)
        {
            count++;
            j--;
        }
        count++;
        if(i < j)
        {
            swap(a,i,j);
            i++;j--;
        }
        else
        {
            break;
        }
    }
    if(i >= j)
    {
        swap(a,j,l);
        ans1 = quick(a,l,j-1);
        ans2 = quick(a,j+1,r);
    }
    return ans1+ans2+count;
}
void main()
{
    system("del -f quick_*.txt");
    srand(time(NULL));
    int n,i,c;
    FILE *f;
    for(n = x;n <= y;n += incre)
    {
        int a[n];
        int num = rand()%100;
        for(i = 0;i < n-1;i++)
            a[i] = num;
        c = quick(a,0,n-2);
        f = fopen("quick_best.txt","a");
        fprintf(f,"%d\t%d\n",n-1,c);
        fclose(f);

        for(i = 0;i < n;i++)
            a[i] = rand()%100;
        c = quick(a,0,n-1);
        f = fopen("quick_avg.txt","a");
        fprintf(f,"%d\t%d\n",n,c);
        fclose(f);

        for(i = 0;i < n;i++)
            a[i] = i+1;
        c = quick(a,0,n-1);
        f = fopen("quick_worst.txt","a");
        fprintf(f,"%d\t%d\n",n,c);
        fclose(f);
    }
}