<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<stdio.h>

int main()
{
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    for(int i=0 ; i<9 ; i++)
    {
        printf("%c\n", arr[i]);
    }

    for(int i=49 ; i<58 ; i++)
    {
        arr[i-49] = (char)i;
    }

    for(int i=0 ; i<9 ; i++)
    {
        printf("%c\n", arr[i]);
    }
    return 0;
=======
>>>>>>> recovered-work
#include<stdio.h>

int main()
{
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    for(int i=0 ; i<9 ; i++)
    {
        printf("%c\n", arr[i]);
    }

    for(int i=49 ; i<58 ; i++)
    {
        arr[i-49] = (char)i;
    }

    for(int i=0 ; i<9 ; i++)
    {
        printf("%c\n", arr[i]);
    }
    return 0;
<<<<<<< HEAD
=======
>>>>>>> c77f237 (C)
>>>>>>> recovered-work
}