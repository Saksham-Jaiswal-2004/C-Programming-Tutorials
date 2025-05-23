<<<<<<< HEAD
=======
<<<<<<< HEAD
//Tic Tac Toe version-2
// Feature added - to Take and display player names
#include<stdio.h>
#include<stdbool.h>
#include<windows.h>

void reset(char arr[]);
void displayGame(char arr[], int a);
void playGame(char arr[], int player);
bool drawGame(char arr[]);
bool winGame(char arr[]);

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
    scanf(" %s",&p1);
    printf("\nEnter Player 2's Name: ");
    scanf(" %s",&p2);
    
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
                }
                else
                {
                    printf("%s wins the game!",p2);
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
=======
>>>>>>> recovered-work
//Tic Tac Toe version-2
// Feature added - to Take and display player names
#include<stdio.h>
#include<stdbool.h>
#include<windows.h>

void reset(char arr[]);
void displayGame(char arr[], int a);
void playGame(char arr[], int player);
bool drawGame(char arr[]);
bool winGame(char arr[]);

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
    scanf(" %s",&p1);
    printf("\nEnter Player 2's Name: ");
    scanf(" %s",&p2);
    
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
                }
                else
                {
                    printf("%s wins the game!",p2);
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
<<<<<<< HEAD
=======
>>>>>>> c77f237 (C)
>>>>>>> recovered-work
}