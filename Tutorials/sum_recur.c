#include<stdio.h>

int sum(int n);

int main()
{
    int a;
    printf("Enter Number:");
    scanf("%d",&a);
    // sum(n);
    printf("Sum of n natural numbers till %d = %d\n", a, sum(a));
    return 0;
}

int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    int s = sum(n-1);
    int stot = s+n;
    return stot;
}