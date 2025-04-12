#include<stdio.h>
#include<time.h>
#include<windows.h>

int main()
{
    int i=1;
    char ch;
    time_t current_time;
    FILE *fptr;
    
    time(&current_time);
    struct tm *local_time = localtime(&current_time);

    // Open file for appending
    if ((fptr = fopen("Test-File.txt", "a")) == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    system("cls");
    fprintf(fptr, "\n\nDate: %02d-%02d-%04d\n", local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
    fprintf(fptr, "Time: %02d:%02d\n", local_time->tm_hour, local_time->tm_min);
    fprintf(fptr, "Player-1: Saksham\n");
    fprintf(fptr, "Player-2: Sarbajit\n");
    fprintf(fptr, "Result: Saksham Wins!\n");
    fclose(fptr);

    // Reopen for reading
    if ((fptr = fopen("Test-File.txt", "r")) == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(fptr);
    return 0;
}