#include<stdio.h>

int main()
{
    int n;
    printf("Enter Height of Star (Odd Inputs Only): \n");
    scanf("%d", &n); //Taking Input from user
    
    if(n%2 != 0) //Checking condition to print X pattern
    {
        for(int i=0 ; i<n ; i++) //Running first loop to control different lines
        {
            for(int j=0 ; j<n ; j++) //Running second loop to control every element in each line
            {
                if(j==i || j==(n-i-1)) //Checking condition to print '*' for X pattern
                {
                    //printf("*"); //Printing '*'
                    printf("*");
                }
                else
                {
                    printf(" "); //Printing spaces where X pattern is not present
                }
            }
            printf("\n"); //Changing line
        }
    }
    else //Warning statements to be printed when wrong input is given by user
    {
        printf("INVALID INPUT!\n");
        printf("Enter odd numbers only!\n");
    }

    printf("\n\n");

    if(n%2 != 0) //Checking condition to print X pattern
    {
        for(int i=0 ; i<n ; i++) //Running first loop to control different lines
        {
            for(int j=0 ; j<n ; j++) //Running second loop to control every element in each line
            {
                if(j==((n-1)/2)) //Checking condition to print '*' for X pattern
                {
                    //printf("*"); //Printing '*'
                    printf("*");
                }
                else if(j==i || j==(n-i-1))
                {
                    printf("*");
                }
                else
                {
                    printf(" "); //Printing spaces where X pattern is not present
                }
            }
            printf("\n"); //Changing line
        }
    }
    else //Warning statements to be printed when wrong input is given by user
    {
        printf("INVALID INPUT!\n");
        printf("Enter odd numbers only!\n");
    }

    printf("\n\n");

    for(int i=0 ; i<n ; i++) //Running first loop to control different lines
        {
            for(int j=0 ; j<n ; j++) //Running second loop to control every element in each line
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
            printf("\n"); //Changing line
        }
    
    return 0;
}//End of main