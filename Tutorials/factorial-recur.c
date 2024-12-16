#include<stdio.h>

int fact(int n);

int main()
{
    int f;
    
    printf("Enter number of terms:");
    scanf("%d", &f);

    printf("Factorial of %d = %d\n", f, fact(f));

    return 0;
}

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }

    int factNm = fact(n-1);
    int factN = factNm*n;
    return factN;
}