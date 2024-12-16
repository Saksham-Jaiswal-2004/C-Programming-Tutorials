//Tic Tac Toe version-3
// Adding feature to add data like date, time, player names, and result of game to a file
#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>

void reset(char arr[]);
void displayGame(char arr[], int a);
void playGame(char arr[], int player);
bool drawGame(char arr[]);
bool winGame(char arr[]);
void saveData(char p1[100], char p2[100], int res);

static char data[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main()
{
    int choice;
    bool game=true;

    while(game)
    {
        reset(data);

        playGame(data, 1);

        printf("\nEnter 1 to play again or Enter any other character to exit.\n");
        scanf("%d", &choice);

        if(choice==1)
        game=true;
        else
        game=false;
    }
    printf("Game Finish!");
}

void reset(char arr[])
{
    for(int i=49 ; i<58 ; i++)
    {
        arr[i-49] = (char)i;
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
    // fgets(p1, 100, stdin);
    printf("\nEnter Player 2's Name: ");
    scanf(" %[^\n]",&p2);
    // fgets(p2, 100, stdin);
    
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