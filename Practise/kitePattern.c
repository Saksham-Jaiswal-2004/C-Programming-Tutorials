#include<stdio.h>

void space(int lim);

int main()
{
    int n=3, m=7, o=3;

    printf("\n");

    for(int i=0 ; i<10 ; i++)
    {
        if(i<4)
        {
            space(3-i);
            for(int j=n ; j>0 ; j--)
            {
                printf("*\t");
            }
            n += 2;
            printf("\n");
        }
        if(i>=4 && i<8)
        {
            space(i-3);
            for(int j=m ; j>=1 ; j--)
            {
                printf("*\t");
            }
            m -= 2;
            printf("\n");
        }
        if(i>=8)
        {
            space(11-i);
            for(int j=o ; j>0 ; j--)
            {
                printf("*\t");
            }
            o += 2;
            printf("\n");
        }
    }

    return 0;
}

void space(int lim)
{
    for(int i=0 ; i<lim ; i++)
    {
        printf("\t");
    }
}