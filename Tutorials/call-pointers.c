<<<<<<< HEAD
#include<stdio.h>

void square(int n);
void _square(int* n);

int main()
{
    int number = 4;

    square(number);
    printf("Number = %d\n",number);

    _square(&number);
    printf("Number = %d\n",number);

    printf("New value of number = %d\n", number);

    return 0;
}

void square(int n)
{
    n = n * n;
    printf("Square = %d\n", n);
}

void _square(int* n)
{
    *n = (*n) * (*n);
    printf("Square = %d\n", *n);
=======
#include<stdio.h>

void square(int n);
void _square(int* n);

int main()
{
    int number = 4;

    square(number);
    printf("Number = %d\n",number);

    _square(&number);
    printf("Number = %d\n",number);

    printf("New value of number = %d\n", number);

    return 0;
}

void square(int n)
{
    n = n * n;
    printf("Square = %d\n", n);
}

void _square(int* n)
{
    *n = (*n) * (*n);
    printf("Square = %d\n", *n);
>>>>>>> c77f237 (C)
}