#include<stdio.h>

int main(){
    int age;
    printf("Enter your age:");
    scanf("%d", &age);

    if(age>=18){
        printf("You are an Adult!");
    }
    else if (age<18 && age>13)
    {
        printf("You are a Teenager!");
    }
    
    else{
        printf("You are not a Child!");
    }
}