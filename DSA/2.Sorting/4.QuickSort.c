#include<stdio.h>

void swap(int* a, int* b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low+1 ; j <= high ; j++) 
    {
        if (arr[j] < pivot) 
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[low], &arr[i-1]);
    return (i-1);
}

int partition2(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    do
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while(i<j);

    swap(&arr[low], &arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int partitionIndex = partition2(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
