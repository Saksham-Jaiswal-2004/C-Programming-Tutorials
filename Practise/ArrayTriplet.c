#include<stdio.h>

int main()
{
    int n, X, c=0, sum=0;

    printf("Enter limit of array (>3): \n");
    scanf("%d", &n);

    if(n<3)
    {
        return 0;
    }

    int data[n];

    printf("Enter number to be checked: \n");
    scanf("%d", &X);

    for(int i=0 ; i<n ; i++)
    {
        printf("Enter Value %d of Array: ",i+1);
        scanf("%d", &data[i]);
    }

    printf("\n");

    for(int i=0 ; i<n-2 ; i++)
    {
        for(int j=i+1 ; j<n-1 ; j++)
        {
            for(int k=j+1 ; k<n ; k++)
            {
                sum = data[i] + data[j] + data[k];
                if(sum==X)
                {
                    printf("Triplet whose sum is %d : (%d , %d , %d)\n", X, data[i], data[j], data[k]);
                }
            }
        }
    }

    return 0;
}