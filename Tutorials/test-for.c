#include<stdio.h>

int main()
{
    int n=1,k=1;
    for(int i=1 ; i<=10 ; i++)
    {
        printf("%d \t",n);
        n++;
        if((n-1)==k)
        {
            printf("\n");
            n=1;
            k++;
        }
    }
}