#include<stdio.h>

void printArray(int arr[], int size)
{
    for(int i=0 ; i<size ; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionsort(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int main()
{
    int data[] = {34, 76, 23, 9, 46, 71, 29};
    int size = sizeof(data)/sizeof(data[0]);

    printArray(data, size);
    insertionsort(data, size);
    printArray(data, size);
    
    return 0;
}