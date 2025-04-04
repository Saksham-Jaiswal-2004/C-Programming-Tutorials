<<<<<<< HEAD
#include<stdio.h>

char len(char arr[]);

int main()
{
    char arr[100];
    printf("Enter your Full Name: \n");
    fgets(arr, 100, stdin);

    int l = len(arr);

    printf("Length of entered string: %d\n", l);
}

char len(char arr[])
{
    int length=0;
    for(int i=0 ; arr[i]!='\0' ; i++ )
    {
        length++;
        printf("%c : %d\t",arr[i],length);
    }

    return length-1;
=======
#include<stdio.h>

char len(char arr[]);

int main()
{
    char arr[100];
    printf("Enter your Full Name: \n");
    fgets(arr, 100, stdin);

    int l = len(arr);

    printf("Length of entered string: %d\n", l);
}

char len(char arr[])
{
    int length=0;
    for(int i=0 ; arr[i]!='\0' ; i++ )
    {
        length++;
        printf("%c : %d\t",arr[i],length);
    }

    return length-1;
>>>>>>> c77f237 (C)
}