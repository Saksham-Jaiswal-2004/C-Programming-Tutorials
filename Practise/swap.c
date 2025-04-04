#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter First Number: \n");
    scanf("%d", &a);
    printf("Enter Second Number: \n");
    scanf("%d", &b);

    int *p = &a;
    int *q = &b;

    printf("Numbers before swapping: \n");
    printf("First Number: %d \n",*p);
    printf("Second Number: %d \n",*q);

    int var = *p;
    *p = *q;
    *q = var;

    printf("Numbers after swapping: \n");
    printf("First Number: %d \n",a);
    printf("Second Number: %d \n",b);
}