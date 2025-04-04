#include<stdio.h>
#include<stdlib.h>

int main()
{
    int adhaar[10];

    int *ptr = &adhaar[0];
    for(int i=0 ; i<10 ; i++)
    {
        // printf("%d Index: ",i+1);
        int val = rand();
        val = val%10;
        // scanf("%d", val);
        adhaar[i] = val;
    }

    for(int i=0 ; i<10 ; i++)
    {
        printf("%d", *(ptr+i));
    }

    return 0;
}