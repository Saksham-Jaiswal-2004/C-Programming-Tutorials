#include<stdio.h>

int main()
{
    int n, X, c=0, sum=0;

    printf("Enter limit of array (>3): ");
    scanf("%d", &n);

    if(n<3)
    {
        printf("Error: Array size must be at least 3!\n");
        return 1;
    }

    int data[n];

    printf("Enter number to be checked: ");
    scanf("%d", &X);

    for(int i=0 ; i<n ; i++)
    {
        printf("Enter Value %d of Array: ", i+1);
        scanf("%d", &data[i]);
    }

    printf("\nSearching for triplets that sum to %d...\n", X);
    int found = 0;

    for(int i=0 ; i<n-2 ; i++)
    {
        for(int j=i+1 ; j<n-1 ; j++)
        {
            for(int k=j+1 ; k<n ; k++)
            {
                sum = data[i] + data[j] + data[k];
                if(sum==X)
                {
                    printf("Triplet found: (%d, %d, %d)\n", data[i], data[j], data[k]);
                    found = 1;
                }
            }
        }
    }

    if(!found)
        printf("No triplets found that sum to %d\n", X);

    return 0;
}