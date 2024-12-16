#include<stdio.h>

int main()
{
    struct student{
        char name[100];
        int roll;
        float cgpa;
    };

    struct student s1;

    printf("Enter Name of Student: \n");
    fgets(s1.name, 100, stdin);
    printf("Enter Roll-No of Student: \n");
    scanf("%d", &s1.roll);
    printf("Enter CGPA of Student: \n");
    scanf("%f", &s1.cgpa);

    printf("\nDetails of Student:\n");
    printf("Name: %s", s1.name);
    printf("Roll-No: %d\n", s1.roll);
    printf("CGPA: %f\n", s1.cgpa);
}