#include<stdio.h>

int main(){
    int a,b,sum;

    printf("Enter a:");
    scanf("%d", &a);

    printf("Enter b:");
    scanf("%d", &b);

    sum = a + b;

    printf("Sum of a and b = %d \n", sum);
    printf("Sum of a and b = %d \n", a+b);
    printf("Difference of a and b = %d \n", a-b);
    printf("Product of a and b = %d \n", a*b);

    return 0;
}