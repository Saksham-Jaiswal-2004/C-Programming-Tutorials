#include<stdio.h>

int main()
{
    int i,j,n,k=0,l=0;
    printf("Enter Range(1-1000) : ");
    scanf("%d", &n);

    int side = n + (n-1);

    for(i=1 ; i<=side ; i++)
    {
        for(j=1 ; j<=side ; j++)
        {
            if(i==(1+k) || i==(side-k) || j==(1+l) || j==(side-l))
            // if(i==(1+k) || i==(side-k))
            {
                printf("%d", (n-k));
            }
            else
            {
                printf("%c", "*");
            }
        }
        k++;
        printf("\n");
    }
    return 0;
}