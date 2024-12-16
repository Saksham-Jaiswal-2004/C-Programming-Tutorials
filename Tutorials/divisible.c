#include<stdio.h>
#include<math.h>

int main(){
    int x;
    printf("Enter a Number to check for divisibility:");
    scanf("%d", &x);
    if (x%2==0)
    {
        printf("Number is divisible by 2.");
    }
    else
    {
        printf("Number is not divisible by 2.");
    }
}