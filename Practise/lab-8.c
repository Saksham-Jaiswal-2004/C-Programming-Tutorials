#include <stdio.h>

// Function prototypes
int and(int x, int y);
int or(int x, int y);
int not(int x);
int nand(int x, int y);
int nor(int x, int y);
int xor(int x, int y);
int xnor(int x, int y);

int main()
{
    int m,n;

    printf("Enter first number: ");
    scanf("%d", &m);
    printf("\nEnter second number: ");
    scanf("%d", &n);

    printf("\n");

    printf("AND(%d, %d) = %d\n", m, n, and(m, n));
    printf("OR(%d, %d) = %d\n", m, n, or(m, n));
    printf("NOT(%d) = %d\n", m, not(m));
    printf("NAND(%d, %d) = %d\n", m, n, nand(m, n));
    printf("NOR(%d, %d) = %d\n", m, n, nor(m, n));
    printf("XOR(%d, %d) = %d\n", m, n, xor(m, n));
    printf("XNOR(%d, %d) = %d\n", m, n, xnor(m, n));

    return 0;
}

// Function implementations
int and(int x, int y)
{
    return x && y;
}

int or(int x, int y)
{
    return x || y;
}

int not(int x)
{
    return !x;
}

int nand(int x, int y)
{
    return !(x && y);
}

int nor(int x, int y)
{
    return !(x || y);
}

int xor(int x, int y)
{
    return (x || y) && !(x && y);
}

int xnor(int x, int y)
{
    return !(xor(x, y));
}