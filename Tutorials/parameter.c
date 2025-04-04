<<<<<<< HEAD
#include<stdio.h>

int add(int a, int b);

int main(){
    int n1,n2,sum;

    printf("Enter First Number: ");
    scanf("%d", &n1);

    printf("Enter Second Number: ");
    scanf("%d", &n2);

    sum = add(n1,n2);

    printf("Sum of %d and %d = %d",n1,n2,sum);

    return 0;
}

int add(int a, int b){
    int f = a+b;
    return f;
=======
#include<stdio.h>

int add(int a, int b);

int main(){
    int n1,n2,sum;

    printf("Enter First Number: ");
    scanf("%d", &n1);

    printf("Enter Second Number: ");
    scanf("%d", &n2);

    sum = add(n1,n2);

    printf("Sum of %d and %d = %d",n1,n2,sum);

    return 0;
}

int add(int a, int b){
    int f = a+b;
    return f;
>>>>>>> c77f237 (C)
}