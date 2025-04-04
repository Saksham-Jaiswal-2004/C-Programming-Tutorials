#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    ptr = (int *) calloc(5, sizeof(int));

    ptr[0] = 6;
    ptr[1] = 2;
    ptr[2] = 9;

    for(int i=0 ; i<5 ; i++)
    {
        printf("%d\t", ptr[i]);
    }

    printf("\n");

    ptr = realloc(ptr, 8);

    for(int i=0 ; i<8 ; i++)
    {
        printf("%d\t", ptr[i]);
    }

    return 0;
}