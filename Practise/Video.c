<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[100];
    char genre[50];
    float runtime;
    char mainChar[100];
} Video;

void findVideo(Video *videos, int count, char genre[50]);
Video createVideo(char *name, char *genre, float runtime, char *mainChar);

int main(int argc, char *argv[])
{   
    if (argc < 2)
    {
        printf("Error: Please provide a genre as a command-line argument.\n");
        return 1;
    }

    char *genre = argv[1];
    int n=20;

    Video *videos = (Video *) malloc(n * sizeof(Video));

    videos[0] = createVideo("Avengers: Endgame", "Action", 181.0f, "Iron Man");
    videos[1] = createVideo("Frozen", "Animation", 102.0f, "Elsa");
    videos[2] = createVideo("The Dark Knight", "Action", 152.0f, "Batman");
    videos[3] = createVideo("Inception", "Science Fiction", 148.0f, "Cobb");
    videos[4] = createVideo("Finding Nemo", "Animation", 100.0f, "Marlin");
    videos[5] = createVideo("The Godfather", "Drama", 175.0f, "Michael Corleone");
    videos[6] = createVideo("Mad Max: Fury Road", "Action", 120.0f, "Furiosa");
    videos[7] = createVideo("Toy Story", "Animation", 81.0f, "Woody");
    videos[8] = createVideo("John Wick", "Action", 101.0f, "John Wick");
    videos[9] = createVideo("The Lion King", "Animation", 88.0f, "Simba");
    videos[10] = createVideo("Interstellar", "Science Fiction", 169.0f, "Cooper");
    videos[11] = createVideo("Pulp Fiction", "Drama", 154.0f, "Vincent Vega");
    videos[12] = createVideo("Guardians of the Galaxy", "Action", 121.0f, "Star-Lord");
    videos[13] = createVideo("Shrek", "Animation", 90.0f, "Shrek");
    videos[14] = createVideo("The Matrix", "Science Fiction", 136.0f, "Neo");
    videos[15] = createVideo("Spider-Man: No Way Home", "Action", 148.0f, "Spider-Man");
    videos[16] = createVideo("Coco", "Animation", 105.0f, "Miguel");
    videos[17] = createVideo("Titanic", "Drama", 195.0f, "Jack Dawson");
    videos[18] = createVideo("Black Panther", "Action", 134.0f, "T'Challa");
    videos[19] = createVideo("The Incredibles", "Animation", 115.0f, "Mr. Incredible");

    findVideo(videos, n, genre);

    free(videos);
    return 0;
}

void findVideo(Video *videos, int count, char genre[50])
{
    int flag=0;
    printf("Videos in the %s genre:\n",genre);

    for(int i=0 ; i<count ; i++)
    {
        if (strcmp(videos[i].genre, genre) == 0) 
        {
            printf("Name: %s, Runtime: %f mins, Principal Character: %s\n",videos[i].name, videos[i].runtime, videos[i].mainChar);
            flag = 1;
        }
    }

    if(!flag)
    {
        printf("Sorry, no videos in this genre found!");
    }
}

Video createVideo(char *name, char *genre, float runtime, char *mainChar)
{
    Video v;
    strncpy(v.name, name, sizeof(v.name) - 1);
    v.name[sizeof(v.name) - 1] = '\0';
    strncpy(v.genre, genre, sizeof(v.genre) - 1);
    v.genre[sizeof(v.genre) - 1] = '\0';
    v.runtime = runtime;
    strncpy(v.mainChar, mainChar, sizeof(v.mainChar) - 1);
    v.mainChar[sizeof(v.mainChar) - 1] = '\0';
    return v;
=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[100];
    char genre[50];
    float runtime;
    char mainChar[100];
} Video;

void findVideo(Video *videos, int count, char genre[50]);
Video createVideo(char *name, char *genre, float runtime, char *mainChar);

int main(int argc, char *argv[])
{   
    if (argc < 2)
    {
        printf("Error: Please provide a genre as a command-line argument.\n");
        return 1;
    }

    char *genre = argv[1];
    int n=20;

    Video *videos = (Video *) malloc(n * sizeof(Video));

    videos[0] = createVideo("Avengers: Endgame", "Action", 181.0f, "Iron Man");
    videos[1] = createVideo("Frozen", "Animation", 102.0f, "Elsa");
    videos[2] = createVideo("The Dark Knight", "Action", 152.0f, "Batman");
    videos[3] = createVideo("Inception", "Science Fiction", 148.0f, "Cobb");
    videos[4] = createVideo("Finding Nemo", "Animation", 100.0f, "Marlin");
    videos[5] = createVideo("The Godfather", "Drama", 175.0f, "Michael Corleone");
    videos[6] = createVideo("Mad Max: Fury Road", "Action", 120.0f, "Furiosa");
    videos[7] = createVideo("Toy Story", "Animation", 81.0f, "Woody");
    videos[8] = createVideo("John Wick", "Action", 101.0f, "John Wick");
    videos[9] = createVideo("The Lion King", "Animation", 88.0f, "Simba");
    videos[10] = createVideo("Interstellar", "Science Fiction", 169.0f, "Cooper");
    videos[11] = createVideo("Pulp Fiction", "Drama", 154.0f, "Vincent Vega");
    videos[12] = createVideo("Guardians of the Galaxy", "Action", 121.0f, "Star-Lord");
    videos[13] = createVideo("Shrek", "Animation", 90.0f, "Shrek");
    videos[14] = createVideo("The Matrix", "Science Fiction", 136.0f, "Neo");
    videos[15] = createVideo("Spider-Man: No Way Home", "Action", 148.0f, "Spider-Man");
    videos[16] = createVideo("Coco", "Animation", 105.0f, "Miguel");
    videos[17] = createVideo("Titanic", "Drama", 195.0f, "Jack Dawson");
    videos[18] = createVideo("Black Panther", "Action", 134.0f, "T'Challa");
    videos[19] = createVideo("The Incredibles", "Animation", 115.0f, "Mr. Incredible");

    findVideo(videos, n, genre);

    free(videos);
    return 0;
}

void findVideo(Video *videos, int count, char genre[50])
{
    int flag=0;
    printf("Videos in the %s genre:\n",genre);

    for(int i=0 ; i<count ; i++)
    {
        if (strcmp(videos[i].genre, genre) == 0) 
        {
            printf("Name: %s, Runtime: %f mins, Principal Character: %s\n",videos[i].name, videos[i].runtime, videos[i].mainChar);
            flag = 1;
        }
    }

    if(!flag)
    {
        printf("Sorry, no videos in this genre found!");
    }
}

Video createVideo(char *name, char *genre, float runtime, char *mainChar)
{
    Video v;
    strncpy(v.name, name, sizeof(v.name) - 1);
    v.name[sizeof(v.name) - 1] = '\0';
    strncpy(v.genre, genre, sizeof(v.genre) - 1);
    v.genre[sizeof(v.genre) - 1] = '\0';
    v.runtime = runtime;
    strncpy(v.mainChar, mainChar, sizeof(v.mainChar) - 1);
    v.mainChar[sizeof(v.mainChar) - 1] = '\0';
    return v;
>>>>>>> c77f237 (C)
}