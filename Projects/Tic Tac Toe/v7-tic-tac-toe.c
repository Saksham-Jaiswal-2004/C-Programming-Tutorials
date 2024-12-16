//Tic Tac Toe version-7 → Final Version of Our Game compatible with linux OS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>

int dashboard(); //Display main menu of game
int computerOption(); //Display different levels for play with computer option
void reset(char arr[]); //Resets playing board for each new game
void displayGame(char arr[], int a); //Updates and displays game board
void playGame(char arr[], int player); //Let two players play with each other
void playComputer(char arr[], int player, int level); //Let a player with computer
int computerTurnL1(char arr[]); //Plays from computer side with begginer level difficulty
int computerTurnL2(char arr[]); //Plays from computer side with advance level difficulty
int canWin(char arr[], char player); //Checks if the next move can be a winning move or not
bool drawGame(char arr[]); //Checks if the game is draw or not
bool winGame(char arr[]); //Checks if either of the player has won or not
void saveData(char p1[100], char p2[100], int res); //Saves data of each game after completion
void displayData(); //Displays history of past games

static char data[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //Array to store game board data
int main()
{
    srand(time(NULL)); //Seed for random number generator
    int choice, option, gameType; //Variables for game type and choice given by user
    bool game=true, flag=true, counter; //Variables to start game and take necessary inputs

    option = dashboard(); //Variable taking input of choice given by user

    switch (option) //Switch case to proceed with the game according to user input
    {
        case 0: // Exit from game
            game=false;
            printf("Exiting the game. Goodbye!\n");
            usleep(2000000); //Gives a delay of 2 seconds
            system("clear"); //Clears screen
            exit(0);
            break;
        case 1: // Pass and Play
            game=true; //Sets game variable to true to start game
            gameType=1; //Setting game type to play among two players
            break;
        case 2: // Play with Computer
            system("clear");
            game=true;
            gameType=computerOption()+1; //Setting game type to play with computer with desired difficulty
            break;
        case 3: // View History
            game=false;
            displayData(); //To display data of past games
            break;
        default:
            printf("Invalid option! Try again.\n"); //To Handle other input cases
    }



    while(game) //While loop to operate game till condition is true
    {
        counter=true;
        reset(data); //Resetting Game Board

        if(gameType==1) //Checking type of game
        {
            playGame(data, 1); //Calling function to start two player game
        }
        if(gameType==2)
        {
            playComputer(data, 1, 1); //Calling function to start player vs computer game with beginner difficulty
        }
        if(gameType==3)
        {
            playComputer(data, 1, 2); //Calling function to start player vs computer game with advanced difficulty
        }

        // Displaying end of game menu
        printf("\n0.Exit\n");
        printf("1.Play Again\n");
        printf("2.Menu\n");

        while(counter) //While loop to keep taking input until valid input is given by user
        {
            scanf("%d", &choice);
            if(choice==1)
            {
                game=true; //Setting condition to again execute game
                counter=false;
            }
            else if(choice==0)
            {
                printf("Game Finish!\n");
                usleep(1000000);
                printf("Exiting Game...\n");
                usleep(1000000);
                game=false; //Setting condition end game
                counter=false;
                system("clear");
                exit(0); //Stop the execution of program
            }
            else if(choice==2)
            {
                game=false;
                counter=false;
                main(); //Calling the main function
            }
            else //Handling other invalid inputs
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
    system("clear");
    // Printing main game dashboard
    printf("********  Welcome to our Tic Tac Toe Game  ********");
    printf("\n\n\n\n");
    printf("0.Exit\n");
    printf("1.Pass and Play\n");
    printf("2.Play with Computer\n");
    printf("3.History of Games\n");
    printf("\n\n\n");
    printf("Enter your Choice:");
    while(flag) //While loop to keeing input until valid input is given by user
    {
        scanf("%d", &choice);
        if(choice<0 || choice>3) //Handling invalid inputs
        {
            printf("Invalid Input!\n");
            printf("Enter Again:\n");
        }
        else
        {
            flag=false; //Making loop condtion false after getting a valid user input
        }
    }

    return choice; //Returning choice given by user
}

int computerOption()
{
    int choice;
    bool flag=true;
    system("clear");
    // Printing play with computer menu
    printf("********  Play With Computer  ********");
    printf("\n\n\n\n");
    printf("1.Level - Beginner\n");
    printf("2.Level - Advanced\n");
    printf("\n\n\n");
    printf("Enter your Choice:");
    while(flag) //While loop to keeing input until valid input is given by user
    {
        scanf("%d", &choice); //To take and store user input
        if(choice<1 || choice>2)
        {
            printf("Invalid Input!\n");
            printf("Enter Again:\n");
        }
        else
        {
            flag=false;
        }
    }

    return choice; //Return valid user input
}

//Funtion to rest Game Board
void reset(char arr[])
{
    for(int i=0 ; i<9 ; i++) //Restting Game Board
    {
        arr[i] = '1'+i;
    }
}

//Function to display game board
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
    bool flag=true;
    char c[] = {'X', 'O'};
    char p1[100], p2[100];

    system("clear");
    printf("Enter Player 1's Name: ");
    scanf(" %[^\n]",&p1);
    printf("\nEnter Player 2's Name: ");
    scanf(" %[^\n]",&p2);
    
    while(flag)
    {
        system("clear");
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

            if(winGame(arr))
            {
                system("clear");
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
            else if(drawGame(arr))
            {
                system("clear");
                displayGame(arr, text);
                printf("\n\n");
                printf("Game Draw!\n");
                saveData(p1,p2,3);
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

void playComputer(char arr[], int player, int level)
{
    int choice, text=0;
    bool flag=true;
    char c[] = {'X', 'O'};
    char p1[100], p2[100]="Computer";

    system("clear");
    printf("Enter Player 1's Name: ");
    scanf(" %[^\n]",&p1);
    usleep(1000000);
    printf("\nPlayer 2: %s",p2);
    usleep(1000000);
    
    while(flag)
    {
        system("clear");
        displayGame(data, text);
        printf("\n\n");
        if(player==1)
        {
            printf("%s enter your choice (1-9):",p1);
            scanf("%d", &choice);
        }
        else
        {
            printf("%s's Turn\n",p2); 
            if(level==1)
            {
                choice = computerTurnL1(arr);
            }
            else
            {
                choice = computerTurnL2(arr);
            }
            usleep(1000000);
            printf("Computer's Choice: %d\n", choice);
            usleep(1000000);
        }

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

            if(winGame(arr))
            {
                system("clear");
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
            else if(drawGame(arr))
            {
                system("clear");
                displayGame(arr, text);
                printf("\n\n");
                printf("Game Draw!\n");
                saveData(p1,p2,3);
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

int computerTurnL1(char arr[])
{
    bool flag=true;
    int turn;
    while(flag)
    {
        turn = rand()%9+1;
        if(arr[turn-1]=='X' || arr[turn-1]=='O')
        {
            continue;
        }
        else
        {
            flag=false;
        }
    }

    return turn;
}

int computerTurnL2(char arr[])
{
    int randomChance = rand() % 100; // Generate a random number between 0 and 99
    int turn;

    if (randomChance < 100) 
    {  // 70% chance to play strategically
        int winMove = canWin(arr, 'O');  // Check if the computer can win
        int blockMove = canWin(arr, 'X'); // Check if the player can win

        if (winMove != -1) 
        {
            return winMove+1;  // Play the winning move
        } 
        else if (blockMove != -1) 
        {
            return blockMove+1;  // Block the player's winning move
        }
    }

    // 50% chance to play randomly or if no strategic moves are found
    bool flag = true;
    while (flag) 
    {
        turn = rand() % 9;  // Generate a number between 0 and 8
        if (arr[turn] != 'X' && arr[turn] != 'O') // Check if the spot is empty
        {  
            flag = false;  // Valid move found
        }
    }
    return turn + 1;  // Return the position as 1-9
}

int canWin(char arr[], char player) {
    // Check for rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (arr[i * 3] == player && arr[i * 3 + 1] == player && arr[i * 3 + 2] != 'X' && arr[i * 3 + 2] != 'O') {
            return i * 3 + 2; // Return the empty spot in the row
        }
        if (arr[i * 3] == player && arr[i * 3 + 2] == player && arr[i * 3 + 1] != 'X' && arr[i * 3 + 1] != 'O') {
            return i * 3 + 1; // Return the empty spot in the row
        }
        if (arr[i * 3 + 1] == player && arr[i * 3 + 2] == player && arr[i * 3] != 'X' && arr[i * 3] != 'O') {
            return i * 3; // Return the empty spot in the row
        }
        
        // Check columns
        if (arr[i] == player && arr[i + 3] == player && arr[i + 6] != 'X' && arr[i + 6] != 'O') {
            return i + 6; // Return the empty spot in the column
        }
        if (arr[i] == player && arr[i + 6] == player && arr[i + 3] != 'X' && arr[i + 3] != 'O') {
            return i + 3; // Return the empty spot in the column
        }
        if (arr[i + 3] == player && arr[i + 6] == player && arr[i] != 'X' && arr[i] != 'O') {
            return i; // Return the empty spot in the column
        }
    }

    // Check diagonals
    if (arr[0] == player && arr[4] == player && arr[8] != 'X' && arr[8] != 'O') {
        return 8; // Return the empty spot in the diagonal
    }
    if (arr[0] == player && arr[8] == player && arr[4] != 'X' && arr[4] != 'O') {
        return 4; // Return the empty spot in the diagonal
    }
    if (arr[4] == player && arr[8] == player && arr[0] != 'X' && arr[0] != 'O') {
        return 0; // Return the empty spot in the diagonal
    }

    if (arr[2] == player && arr[4] == player && arr[6] != 'X' && arr[6] != 'O') {
        return 6; // Return the empty spot in the diagonal
    }
    if (arr[2] == player && arr[6] == player && arr[4] != 'X' && arr[4] != 'O') {
        return 4; // Return the empty spot in the diagonal
    }
    if (arr[4] == player && arr[6] == player && arr[2] != 'X' && arr[2] != 'O') {
        return 2; // Return the empty spot in the diagonal
    }

    return -1; // No winning move
}

bool drawGame(char arr[])
{
    for (int i = 0; i < 9; i++) {
        if (arr[i] != 'X' && arr[i] != 'O') {
            return false;
        }
    }
    return true;
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
    system("clear");
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
        system("clear");
        exit(0);
    }
    else
    {
        main();
    }
}