<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    ptr = (int*) malloc(5*sizeof(int));

    ptr[0] = 12;
    ptr[1] = 37;
    ptr[2] = 85;
    ptr[3] = 25;
    ptr[4] = 50;

    for(int i=0 ; i<5 ; i++)
    {
        printf("%d\n", ptr[i]);
    }

    return 0;
=======
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    ptr = (int*) malloc(5*sizeof(int));

    ptr[0] = 12;
    ptr[1] = 37;
    ptr[2] = 85;
    ptr[3] = 25;
    ptr[4] = 50;

    for(int i=0 ; i<5 ; i++)
    {
        printf("%d\n", ptr[i]);
    }

    return 0;
>>>>>>> c77f237 (C)
}