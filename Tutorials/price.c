<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<stdio.h>
#include<conio.h>

void calculatePrice(float value);

int main()
{
    float value=100.0;
    calculatePrice(value);
    printf("Value is: %f",value);
    return 0;
}

void calculatePrice(float value){
    value = value + (0.18*value);
    printf("Final price with GST: %f\n",value);
=======
>>>>>>> recovered-work
#include<stdio.h>
#include<conio.h>

void calculatePrice(float value);

int main()
{
    float value=100.0;
    calculatePrice(value);
    printf("Value is: %f",value);
    return 0;
}

void calculatePrice(float value){
    value = value + (0.18*value);
    printf("Final price with GST: %f\n",value);
<<<<<<< HEAD
=======
>>>>>>> c77f237 (C)
>>>>>>> recovered-work
}