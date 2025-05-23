#include<stdio.h>

void printArray(int arr[], int size)
{
    for(int i=0 ; i<size ; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubblesort(int *arr, int size)
{
    for(int i=0 ; i<size-1 ; i++)
    {
        for(int j=0 ; j<size-1-i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int data[] = {34, 76, 23, 9, 46, 71, 29};
    int size = sizeof(data)/sizeof(data[0]);

    printArray(data, size);
    bubblesort(data, size);
    printArray(data, size);
    return 0;
}