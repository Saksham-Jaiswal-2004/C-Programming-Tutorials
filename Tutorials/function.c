#include<stdio.h>

// Declaration/Prototype
void printHello();

int main(){
    // Function Call
    printHello();
    printHello();
    printHello();
    return 0;
}

// Function Definition
void printHello(){
    printf("Hello!\n");
    printf("Function Called!\n");
}