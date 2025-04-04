<<<<<<< HEAD
#include<stdio.h>
#include<time.h>

void delay(int number_of_seconds);

int main()
{
    int marks[5] = {56, 78, 65, 98, 85};
    char name[5] = {'A', 'B', 'C', 'D', 'E'};

    for(int i=0 ; i<5 ; i++)
    {
        printf("Name: %c\t", name[i]);
        printf("Marks: %d\n", marks[i]);
        printf("\n");
        delay(1);
    }
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
=======
#include<stdio.h>
#include<time.h>

void delay(int number_of_seconds);

int main()
{
    int marks[5] = {56, 78, 65, 98, 85};
    char name[5] = {'A', 'B', 'C', 'D', 'E'};

    for(int i=0 ; i<5 ; i++)
    {
        printf("Name: %c\t", name[i]);
        printf("Marks: %d\n", marks[i]);
        printf("\n");
        delay(1);
    }
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
>>>>>>> c77f237 (C)
}