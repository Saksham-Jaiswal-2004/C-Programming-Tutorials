#include<stdio.h>

int main()
{
    int n;
    printf("Enter Height of Star (Odd Inputs Only): \n");
    scanf("%d", &n); //Taking Input from user
    
    if(n%2 != 0) //Checking condition to print X pattern
    {
        // First pattern
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(j==i || j==(n-i-1))
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("INVALID INPUT!\n");
        printf("Enter odd numbers only!\n");
    }

    printf("\n\n");

    if(n%2 != 0)
    {
        // Second pattern
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(j==((n-1)/2) || j==i || j==(n-i-1))
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    printf("\n\n");

    // Third pattern
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(n%2==0)
            {
                if(i==j || j==(n-1-i))
                {
                    printf("***");
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                if(i==((n-1)/2) && (i==j || j==(n-1-i)))
                {
                    printf("*****");
                }
                else if(i==j || j==(n-1-i))
                {
                    printf("***");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}//End of main