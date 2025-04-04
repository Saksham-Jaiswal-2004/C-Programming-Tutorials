#include<stdio.h>

void permutation(int a, int counter);

int main()
{
    int n;

    printf("Enter a three digit number:");
    scanf("%d", &n);
    
    if(n>99 && n<1000)
    {
        printf("All possible permutations of %d are:\n",n);
        permutation(n, 3);
    }
    else
    {
        printf("Invalid Input!");
    }

    return 0;
}

void permutation(int a, int counter)
{
    int copy, b=0, c=0, n=1;
    while(counter>0 && n>0)
    {
        copy = a;
        for(int i=0 ; i<3 ; i++)
        {
            b = (b*10) + (copy%10);
            copy /=10;
        }
        printf("%d\n", a);
        printf("%d\n", b);

        copy=a;
    
        c = copy%10;
        copy /= 10;
        c = (c*100) + copy;
    
        n--;
        counter--;
        permutation(c, counter);
    }
    return;
}