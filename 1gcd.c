#include<stdio.h>
void main()
{
    int count = 0,m1,n1,m2,n2,min,temp1 = 0,temp2 = 0;
    FILE *f1,*f2;
    printf("Enter two numbers to find gcd\n");
    scanf("%d%d",&m1,&n1);
    m2 = m1;
    n2 = n1;
//euclids modified algo based on subtraction
    while(m1 != n1)
    {
        count++;
        if(m1 > n1)
        {
            m1 = m1 - n1;
        }
        else
        {
            n1 = n1 - m1;
        }
    }
    f1=fopen("e1w.txt","a");
    fprintf(f1,"%d\n",count);
    fclose(f1);
    printf("euclids modified algo based on subtrction\ngcd is %d\noperational count is %d\n",m1,count);

    //euclids algo based on consecutive integer checking
    count = 0;
    if(m2 > n2)
    {
        min = n2;
    }
    else
    {
        min = m2;
    }
    while(min != 1)
    {
        temp1 = m2 % min;
        count++;
        if(temp1 == 0)
        {
            temp2 = n2 % min;
            count++;
            if(temp2 == 0)
            {
                break;
            }
        }
        min  = min - 1;
    }
    f2=fopen("e2w.txt","a");
    fprintf(f2,"%d\n",count);
    fclose(f2);
    printf("euclids algo based on consecutive integer checking\ngcd is %d\noperational count is %d",min,count);
}
