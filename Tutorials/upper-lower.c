#include<stdio.h>

int main(){
    char ch;
    printf("Enter any character: ");
    scanf("%c", &ch);

    if((int)ch<=90 && (int)ch>=65)
    {
        printf("You have entered an Uppercase Character!");
    }
    else if((int)ch<=122 && (int)ch>=97)
    {
        printf("You have entered a Lowercase Character!");
    }
    else
    {
        printf("Wrong Input!");
    }
}