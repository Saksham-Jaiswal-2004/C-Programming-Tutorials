//Tic Tac Toe version-4
// Adding feature to display a dashboard before game to ask user to either play or display history.
// Improving end of game procedure
// Added menu driven feature to traverse through the game
// Improved dashboard menu code
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>

int dashboard();
void reset(char arr[]);
void displayGame(char arr[], int a);
void playGame(char arr[], int player);
bool drawGame(char arr[]);
bool winGame(char arr[]);
void saveData(char p1[100], char p2[100], int res);
void displayData();

static char data[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main()
{
    int choice, option;
    bool game=true, flag=true, counter;

    option = dashboard();

    switch (option) 
    {
        case 0: // Exit
            game=false;
            printf("Exiting the game. Goodbye!\n");
            Sleep(2000);
            system("cls");
            exit(0);
            break;
        case 1: // Pass and Play
            game=true;
            break;
        case 2: // Play with Computer (Placeholder)
            system("cls");
            game=false;
            printf("Play with Computer Mode is Under Maintenance. Returning to Dashboard...\n");
            Sleep(2000);
            main();
            break;
        case 3: // View History
            game=false;
            displayData();
            break;
        default:
            printf("Invalid option! Try again.\n");
        }



    while(game)
    {
        counter=true;
        reset(data);

        playGame(data, 1);

        printf("\n0.Exit\n");
        printf("1.Play Again\n");
        printf("2.Menu\n");

        while(counter)
        {
            scanf("%d", &choice);
            if(choice==1)
            {
                game=true;
                counter=false;
            }
            else if(choice==0)
            {
                printf("Game Finish!");
                game=false;
                counter=false;
            }
            else if(choice==2)
            {
                game=false;
                counter=false;
                main();
            }
            else
            {
                printf("Invalid Input!\n");
                printf("Enter your choice again:");
                counter=true;
            }
        }
    }
}

int dashboard()
{
    int choice;
    bool flag=true;
    system("cls");
    printf("********  Welcome to our Tic Tac Toe Game  ********");
    printf("\n\n\n\n");
    printf("0.Exit\n");
    printf("1.Pass and Play\n");
    printf("2.Play with Computer\n");
    printf("3.History of Games\n");
    printf("\n\n\n");
    printf("Enter your Choice:");
    while(flag)
    {
        scanf("%d", &choice);
        if(choice<0 || choice>3)
        {
            printf("Invalid Input!\n");
            printf("Enter Again:\n");
        }
        else
        {
            flag=false;
        }
    }

    return choice;
}

void reset(char arr[])
{
    for(int i=0 ; i<9 ; i++)
    {
        arr[i] = '1'+i;
    }
}

void displayGame(char arr[], int a)
{
    printf("****************    Tic Tac Toe    ****************\n\n");
    printf("\t%c\t|\t%c\t|\t%c\n",arr[0],arr[1],arr[2]);
    printf("----------------+---------------+------------------\n");
    printf("\t%c\t|\t%c\t|\t%c\n",arr[3],arr[4],arr[5]);
    printf("----------------+---------------+------------------\n");
    printf("\t%c\t|\t%c\t|\t%c\n",arr[6],arr[7],arr[8]);

    printf("\n");

    if(a==1)
    {
        printf("Place already occupied!\n");
    }
    if(a==2)
    {
        printf("Invalid Input!\n");
    }
}

void playGame(char arr[], int player)
{
    int choice, text=0;
    bool flag = true;
    char c[] = {'X', 'O'};
    char p1[100], p2[100];

    system("cls");
    printf("Enter Player 1's Name: ");
    scanf(" %[^\n]",&p1);
    printf("\nEnter Player 2's Name: ");
    scanf(" %[^\n]",&p2);
    
    while(flag)
    {
        system("cls");
        displayGame(data, text);
        printf("\n\n");
        if(player==1)
        {
            printf("%s enter your choice (1-9):",p1);
        }
        else
        {
            printf("%s enter your choice (1-9):",p2);
        }
        scanf("%d", &choice);

        if(choice>9 || choice<1)
        {
            text=2;
            continue;
        }
        else if(arr[choice-1]=='X' || arr[choice-1]=='O')
        {
            text=1;
            continue;
        }
        else
        {
            arr[choice-1] = c[player-1];

            if(drawGame(arr))
            {
                system("cls");
                displayGame(arr, text);
                printf("\n\n");
                printf("Game Draw!\n");
                saveData(p1,p2,3);
                flag=false;
                break;
            }
            else if(winGame(arr))
            {
                system("cls");
                displayGame(arr, text);
                printf("\n\n");
                if(player==1)
                {
                    printf("%s wins the game!",p1);
                    saveData(p1,p2,1);
                }
                else
                {
                    printf("%s wins the game!",p2);
                    saveData(p1,p2,2);
                }
                flag=false;
                break;
            }
            else
            {
                if(player==1)
                player=2;
                else
                player=1;
            }
        }
    }
    printf("\n");
}

bool drawGame(char arr[])
{
    int counter=0;
    for(int i=0 ; i<9 ; i++)
    {
        if(arr[i]=='X' || arr[i]=='O')
        {
            counter++;
        }
    }

    if(counter==9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool winGame(char arr[])
{
    if((arr[0]==arr[1] && arr[1]==arr[2]) || (arr[3]==arr[4] && arr[4]==arr[5]) || (arr[6]==arr[7] && arr[7]==arr[8]) || (arr[0]==arr[3] && arr[3]==arr[6]) || (arr[1]==arr[4] && arr[4]==arr[7]) || (arr[2]==arr[5] && arr[5]==arr[8]) || (arr[0]==arr[4] && arr[4]==arr[8]) || (arr[2]==arr[4] && arr[4]==arr[6]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void saveData(char p1[100], char p2[100], int res)
{
    time_t Time;
    time(&Time);
    struct tm *local_time = localtime(&Time);

    FILE *fptr;

    fptr = fopen("Game-Data.txt", "a");

    fprintf(fptr, "Date: %02d-%02d-%04d\n",local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
    fprintf(fptr, "Time: %02d:%02d\n",local_time->tm_hour, local_time->tm_min);
    fprintf(fptr, "Player-1: %s\n",p1);
    fprintf(fptr, "Player-2: %s\n",p2);
    if(res==1)
    {
        fprintf(fptr, "Result: %s Wins!\n\n",p1);
    }
    else if(res==2)
    {
        fprintf(fptr, "Result: %s Wins!\n\n",p2);
    }
    else
    {
        fprintf(fptr, "Result: Game Draw!\n\n");
    }

    fclose(fptr);
}

void displayData()
{
    bool flag=true;
    int choice;
    system("cls");
    char ch;
    FILE *fptr;
    fptr = fopen("Game-Data.txt", "r");
    while ((ch = fgetc(fptr)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fptr);

    printf("\n\n\n\n");
    printf("0.Exit\n");
    printf("1.Menu\n");
    printf("\n\n\n");
    printf("Enter your Choice:");
    while(flag)
    {
        scanf("%d", &choice);
        if(choice<0 || choice>1)
        {
            printf("Invalid Input!\n");
            printf("Enter Again:\n");
        }
        else
        {
            flag=false;
        }
    }

    if(choice==0)
    {
        system("cls");
        exit(0);
    }
    else
    {
        main();
    }
}