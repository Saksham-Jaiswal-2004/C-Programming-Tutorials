#include<stdio.h>

void space(int len);

int main()
{
    int n=17, m=7, o=1;

    for(int i=0 ; i<8 ; i++)
    {
        space(i);
        for(int j=0 ; j<n ; j++)
        {
            if(i>=1 && i<4)
            {
                for(int k=0 ; k<m ; k++)
                {
                    printf("* ");
                    j++;
                }
                space(o);
                j += o;
                for(int k=0 ; k<m ; k++)
                {
                    printf("* ");
                    j++;
                }

                m -= 2;
                o += 2;
            }
            else
            {
                printf("* ");
            }
        }
        n -= 2;
        printf("\n");
    }

    return 0;
}

void space(int len)
{
    for(int i=0 ; i<len ; i++)
    {
        printf("  ");
    }
}