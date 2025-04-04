<<<<<<< HEAD
#include<stdio.h>
#include<string.h>

struct student{
    char name[100];
    int roll;
    float cgpa;
};

int main()
{
    struct student ECE[100];
    struct student CSE[100];

    strcpy(ECE[0].name, "Mohit Negi");
    ECE[0].roll = 24060;
    ECE[0].cgpa = 8.8;

    strcpy(CSE[0].name, "Saksham Jaiswal");
    CSE[0].roll = 24083;
    CSE[0].cgpa = 8.2;

    // printf("ECE student 1: \n");
    // printf("Name: %s\n", ECE[0].name);
    // printf("Roll-No: %d\n", ECE[0].roll);
    // printf("Name: %f\n", ECE[0].cgpa);

    // printf("\n");

    // printf("CSE student 1: \n");
    // printf("Name: %s\n", CSE[0].name);
    // printf("Roll-No: %d\n", CSE[0].roll);
    // printf("Name: %f\n", CSE[0].cgpa);

    struct student *ptr1 = &ECE[0];
    struct student *ptr2 = &CSE[0];

    printf("ECE student 1: \n");
    printf("Name: %s\n", ptr1 -> name);
    printf("Roll-No: %d\n", ptr1 -> roll);
    printf("Name: %f\n", ptr1 -> cgpa);

    printf("\n");

    printf("CSE student 1: \n");
    printf("Name: %s\n", ptr2 -> name);
    printf("Roll-No: %d\n", ptr2 -> roll);
    printf("Name: %f\n", ptr2 -> cgpa);
=======
#include<stdio.h>
#include<string.h>

struct student{
    char name[100];
    int roll;
    float cgpa;
};

int main()
{
    struct student ECE[100];
    struct student CSE[100];

    strcpy(ECE[0].name, "Mohit Negi");
    ECE[0].roll = 24060;
    ECE[0].cgpa = 8.8;

    strcpy(CSE[0].name, "Saksham Jaiswal");
    CSE[0].roll = 24083;
    CSE[0].cgpa = 8.2;

    // printf("ECE student 1: \n");
    // printf("Name: %s\n", ECE[0].name);
    // printf("Roll-No: %d\n", ECE[0].roll);
    // printf("Name: %f\n", ECE[0].cgpa);

    // printf("\n");

    // printf("CSE student 1: \n");
    // printf("Name: %s\n", CSE[0].name);
    // printf("Roll-No: %d\n", CSE[0].roll);
    // printf("Name: %f\n", CSE[0].cgpa);

    struct student *ptr1 = &ECE[0];
    struct student *ptr2 = &CSE[0];

    printf("ECE student 1: \n");
    printf("Name: %s\n", ptr1 -> name);
    printf("Roll-No: %d\n", ptr1 -> roll);
    printf("Name: %f\n", ptr1 -> cgpa);

    printf("\n");

    printf("CSE student 1: \n");
    printf("Name: %s\n", ptr2 -> name);
    printf("Roll-No: %d\n", ptr2 -> roll);
    printf("Name: %f\n", ptr2 -> cgpa);
>>>>>>> c77f237 (C)
}