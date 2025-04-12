#include<stdio.h>
#include<math.h>

int main()
{
    int n, len, new=0;

    printf("Enter number of digits: ");
    scanf("%d", &len);
    printf("Enter a %d-digits number: ", len);
    scanf("%d", &n);

    int min = pow(10, len - 1);
    int max = pow(10, len) - 1;
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
        printf("%d is a Palindrome Number!\n", n);
    else
        printf("%d is not a Palindrome Number!\n", n);

    return 0;
}