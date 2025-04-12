<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr, n;
    
    printf("Enter n: \n");
    scanf("%d", &n);

    ptr = (int*) calloc(n, sizeof(int));

    for(int i=0 ; i<n ; i++)
    {
        printf("%d\n", ptr[i]);
    }

    free(ptr);
    
    printf("After Freeing memory!\n");

    ptr = (int*) calloc(2, sizeof(int));

    for(int i=0 ; i<2 ; i++)
    {
        printf("%d\n", ptr[i]);
    }

    return 0;
=======
>>>>>>> recovered-work
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr, n;
    
    printf("Enter n: \n");
    scanf("%d", &n);

    ptr = (int*) calloc(n, sizeof(int));

    for(int i=0 ; i<n ; i++)
    {
        printf("%d\n", ptr[i]);
    }

    free(ptr);
    
    printf("After Freeing memory!\n");

    ptr = (int*) calloc(2, sizeof(int));

    for(int i=0 ; i<2 ; i++)
    {
        printf("%d\n", ptr[i]);
    }

    return 0;
<<<<<<< HEAD
=======
>>>>>>> c77f237 (C)
>>>>>>> recovered-work
}