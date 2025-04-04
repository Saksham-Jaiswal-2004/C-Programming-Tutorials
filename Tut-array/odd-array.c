<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>

int countOdd(int arr[]);

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

    printf("\nNumber of Odd Elements in Array : %d", countOdd(arr));
}

int countOdd(int arr[])
{
    int count=0, len;

    len = sizeof(*arr);

    for(int i=0 ; i<=len ; i++)
    {
        if(arr[i]%2!=0)
        {
            count++;
        }
    }

    return count;
=======
#include<stdio.h>
#include<stdlib.h>

int countOdd(int arr[]);

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

    printf("\nNumber of Odd Elements in Array : %d", countOdd(arr));
}

int countOdd(int arr[])
{
    int count=0, len;

    len = sizeof(*arr);

    for(int i=0 ; i<=len ; i++)
    {
        if(arr[i]%2!=0)
        {
            count++;
        }
    }

    return count;
>>>>>>> c77f237 (C)
}