#include<stdio.h>

int fact(int num);
void space(int lim);

int main()
{
    int n,r;
    printf("Enter Range: ");
    scanf("%d", &n);

    r = n + (n-1);

    for(int i=0 ; i<=(r/2) ; i++)
    {
        space(n - (i+1));
        for(int j=0 ; j<r ; j++)
        {
            if(j<=(i+1))
            {
                int c = fact(i)/(fact(j-i)*fact(j));
                printf("%d\t*\t",c);
                j++;
            }
            if(j>i)
            {
                printf("*\t");
                continue;
            }
        }
        printf("\n");
    }
}

int fact(int num)
{
    int i=1, pro=1;
    while(i<=num)
    {
        pro *= i;
        i++;
    }
    return pro;
}

void space(int lim)
{
    for(int i=0 ; i<lim ; i++)
    {
        printf("*\t");
    }
}