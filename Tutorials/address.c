#include<stdio.h>

void printAdd(int m);

int main()
{
    int n=10;

    printf("%p\n", n);

    printAdd(n);

    return 0;
}

void printAdd(int m)
{
    printf("%p\n", &m);
}