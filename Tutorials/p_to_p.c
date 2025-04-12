<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<stdio.h>

int main()
{
    float price = 100.0;
    float *ptr = &price; //Stores address of variable price
    float **pptr = &ptr; //Stores adddress of pointer ptr

    printf("Adress of ptr: %u\n", &ptr);
    printf("Adress of ptr: %u\n", pptr);

    printf("Value of price: %f\n", *(*pptr));

    return 0;
=======
>>>>>>> recovered-work
#include<stdio.h>

int main()
{
    float price = 100.0;
    float *ptr = &price; //Stores address of variable price
    float **pptr = &ptr; //Stores adddress of pointer ptr

    printf("Adress of ptr: %u\n", &ptr);
    printf("Adress of ptr: %u\n", pptr);

    printf("Value of price: %f\n", *(*pptr));

    return 0;
<<<<<<< HEAD
=======
>>>>>>> c77f237 (C)
>>>>>>> recovered-work
}