#include<stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("records.txt", "w+");
    
    if(fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // File operations can be added here
    
    fclose(fptr);
    return 0;
}