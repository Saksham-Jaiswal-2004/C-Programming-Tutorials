#include<stdio.h>

int main()
{
    int i=1,n=1;
    while(n<=i && i<=4)
    {
        printf("%d \t",n);
        n++;
        if((n-1)==i)
        {
            printf("\n");
            n=1;
            i++;
        }
    }
}