<<<<<<< HEAD
#include<stdio.h>

int main()
{
    int flag1=0, flag2=0;

    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[5] = {1,3,8,5,2};
    int arr3[5] = {1,11,85,15,2};

    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            if(arr1[i]==arr2[j])
            {
                flag1++;
            }
            if(arr1[i]==arr3[j])
            {
                flag2++;
            }
        }
    }

    if(flag1==5)
    {
        printf("arr2[] is a subset of arr1[]!\n");
    }
    else
    {
        printf("arr2[] is not a subset of arr1[]!\n");
    }
    if(flag2==5)
    {
        printf("arr3[] is a subset of arr1[]!\n");
    }
    else
    {
        printf("arr3[] is not a subset of arr1[]!\n");
    }

    return 0;
=======
#include<stdio.h>

int main()
{
    int flag1=0, flag2=0;

    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[5] = {1,3,8,5,2};
    int arr3[5] = {1,11,85,15,2};

    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            if(arr1[i]==arr2[j])
            {
                flag1++;
            }
            if(arr1[i]==arr3[j])
            {
                flag2++;
            }
        }
    }

    if(flag1==5)
    {
        printf("arr2[] is a subset of arr1[]!\n");
    }
    else
    {
        printf("arr2[] is not a subset of arr1[]!\n");
    }
    if(flag2==5)
    {
        printf("arr3[] is a subset of arr1[]!\n");
    }
    else
    {
        printf("arr3[] is not a subset of arr1[]!\n");
    }

    return 0;
>>>>>>> c77f237 (C)
}