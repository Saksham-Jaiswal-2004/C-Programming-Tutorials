<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<stdio.h>

void printString(char arr[]);

int main()
{
    // char name[] = {'S','A','K','S','H','A','M','\0'};
    // char name1[] = "Jaiswal";
    // printString(name);
    // printf("\n");
    // printString(name1);
    // printf("\n");
    // printf("%s",name);
    // printf("\n");
    // printf("%s",name1);

    char str[100];
    char str1[100];
    
    printf("Enter your Full Name: \n");
    gets(str);
    puts(str);

    printf("Enter your abcd Full Name: \n");
    fgets(str1, 100, stdin);
    puts(str1);

    return 0;
}

void printString(char arr[])
{
    for(int i=0 ; arr[i]!='\0' ; i++)
    {
        printf("%c",arr[i]);
    }
=======
>>>>>>> recovered-work
#include<stdio.h>

void printString(char arr[]);

int main()
{
    // char name[] = {'S','A','K','S','H','A','M','\0'};
    // char name1[] = "Jaiswal";
    // printString(name);
    // printf("\n");
    // printString(name1);
    // printf("\n");
    // printf("%s",name);
    // printf("\n");
    // printf("%s",name1);

    char str[100];
    char str1[100];
    
    printf("Enter your Full Name: \n");
    gets(str);
    puts(str);

    printf("Enter your abcd Full Name: \n");
    fgets(str1, 100, stdin);
    puts(str1);

    return 0;
}

void printString(char arr[])
{
    for(int i=0 ; arr[i]!='\0' ; i++)
    {
        printf("%c",arr[i]);
    }
<<<<<<< HEAD
=======
>>>>>>> c77f237 (C)
>>>>>>> recovered-work
}