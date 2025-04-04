#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is an article
int isArticle(const char *word) {
    return (strcmp(word, "a") == 0 || strcmp(word, "an") == 0 || strcmp(word, "the") == 0);
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char filename[100];
    FILE *file;
    char word[50];
    int articleCount = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s.\n", filename);
        return 1;
    }

    // Read words from the file and check for articles
    while (fscanf(file, "%49s", word) == 1) {
        // Remove punctuation and convert to lowercase
        char cleanWord[50];
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isalnum(word[i])) {
                cleanWord[j++] = word[i];
            }
        }
        cleanWord[j] = '\0';
        toLowerCase(cleanWord);

        if (isArticle(cleanWord)) {
            printf("%s\n", cleanWord);
            articleCount++;
        }
    }

    fclose(file);

    printf("The number of articles in the file is: %d\n", articleCount);

    return 0;
}
