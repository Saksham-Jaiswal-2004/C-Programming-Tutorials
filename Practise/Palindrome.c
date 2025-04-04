#include<stdio.h>
#include<math.h>

int main()
{
    int n, len, new=0;

    printf("Enter number of digits:",n);
    scanf("%d", &len);
    printf("Enter a %d-digits number number:",len);
    scanf("%d", &n);

    int min = pow(10, len - 1);   // Smallest n-digit number
    int max = pow(10, len) - 1;   // Largest n-digit number
    if (n < min || n > max) 
    {
        printf("Error: The number is not %d digits long.\n", len);
        return 1;
    }

    int copy=n;

    while(copy>0)
    {
        new = (new*10) + (copy%10);
        copy /= 10;
    }

    if(new==n)
    printf("Palindrome Number!");
    else
    printf("Not a Palindrome Number!");

    return 0;
}