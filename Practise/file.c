#include<stdio.h>
#include<time.h>
#include<windows.h>

int main()
{
    int i=1;
    char ch;

    // Declare a time_t variable to store the current time
    time_t current_time;
    
    // Get the current time
    time(&current_time);

    // Convert to local time format
    struct tm *local_time = localtime(&current_time);

    FILE *fptr;

    // Open a file in writing mode
    fptr = fopen("Test-File.txt", "a");
    
    // Write some text to the file
    // fprintf(fptr, "\n\nMatch Number - %d\n",i);
    system("cls");
    fprintf(fptr, "\n\nDate: %02d-%02d-%04d\n",local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
    fprintf(fptr, "Time: %02d:%02d\n",local_time->tm_hour, local_time->tm_min);
    fprintf(fptr, "Player-1: Saksham\n");
    fprintf(fptr, "Player-2: Sarbajit\n");
    fprintf(fptr, "Result: Saksham Wins!\n");
    i++;

    fptr = fopen("Test-File.txt", "r");
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c",ch);
    }
    
    // Close the file
    fclose(fptr);
    return 0;
}