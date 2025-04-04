<<<<<<< HEAD
#include<stdio.h>

int fib(int n);

int main()
{
    int num;
    printf("Enter Number of terms:");
    scanf("%d", &num);
    // fib(num);
    printf("%d", fib(num));
    return 0;
}

int fib(int n)
{
    if(n==0 || n==1)
    {
        if(n==0)
        {
            return 0;
        }

        if(n==1)
        {
            return 1;
        }
    }

    int fibN1 = fib(n-1);
    int fibN2 = fib(n-2);
    int fibN = fibN1 + fibN2;

    printf("Fibonacci of %d term is : %d\n", n, fibN);

    return fibN;
=======
#include<stdio.h>

int fib(int n);

int main()
{
    int num;
    printf("Enter Number of terms:");
    scanf("%d", &num);
    // fib(num);
    printf("%d", fib(num));
    return 0;
}

int fib(int n)
{
    if(n==0 || n==1)
    {
        if(n==0)
        {
            return 0;
        }

        if(n==1)
        {
            return 1;
        }
    }

    int fibN1 = fib(n-1);
    int fibN2 = fib(n-2);
    int fibN = fibN1 + fibN2;

    printf("Fibonacci of %d term is : %d\n", n, fibN);

    return fibN;
>>>>>>> c77f237 (C)
}