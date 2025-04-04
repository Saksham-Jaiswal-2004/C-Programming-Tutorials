#include<stdio.h>

int main()
{
    int age = 22;
    int *ptr = &age;
    int _age = *ptr;

    printf("%d \n", age);
    printf("%d \n", *ptr);
    printf("%d \n", ptr);
    printf("%d \n", _age);

    printf("Address of 'age': %p\n", &age);
    printf("Address of 'age': %p\n", ptr);
    printf("Address of 'age': %u\n", &age);
    printf("Address of 'ptr': %u\n", &ptr);

    return 0;
}