<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<stdio.h>

void printHW(int count);

int main()
{
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    printHW(n);
    return 0;
}

void printHW(int count)
{
    if(count==0)
    {
        return;
    }
    printf("Hello World!\n");
    printHW(count-1);
=======
>>>>>>> recovered-work
#include<stdio.h>

void printHW(int count);

int main()
{
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    printHW(n);
    return 0;
}

void printHW(int count)
{
    if(count==0)
    {
        return;
    }
    printf("Hello World!\n");
    printHW(count-1);
<<<<<<< HEAD
=======
>>>>>>> c77f237 (C)
>>>>>>> recovered-work
}