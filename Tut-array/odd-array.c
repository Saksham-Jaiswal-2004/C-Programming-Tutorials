#include<stdio.h>
#include<stdlib.h>

int countOdd(int arr[], int size); // Add size parameter

int main()
{
    int n;
    printf("Enter Size: \n");
    scanf("%d", &n);

    int arr[n];

    printf("Original Array : \t");

    for(int i=0 ; i<n ; i++)
    {
        arr[i] = rand()%10;
        printf("%d\t", arr[i]);
    }

    printf("\nNumber of Odd Elements in Array : %d", countOdd(arr, n)); // Pass size parameter
    return 0;  // Added missing return statement
}

int countOdd(int arr[], int size) // Add size parameter
{
    int count=0;
    for(int i=0; i<size; i++)
    {
        if(arr[i]%2!=0)
        {
            count++;
        }
    }
    return count;
}