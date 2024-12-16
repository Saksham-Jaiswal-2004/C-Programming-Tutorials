#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

// Function prototypes
void displayBoard();
int checkWinner();
void userMove(char player);
void computerMove();
int isValidMove(int move);

// Global variables
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Main function
int main() {
    int mode, winner = 0, moveCount = 0;
    char playAgain;

    do {
        // Initialize the board
        for (int i = 0; i < 9; i++) {
            board[i] = '1' + i;
        }

        system("cls");
        
        printf("Welcome to Tic Tac Toe!\n");
        printf("Choose game mode:\n");
        printf("1. Multiplayer (User vs User)\n");
        printf("2. Computer vs User\n");
        printf("Enter your choice: ");
        scanf("%d", &mode);

        system("cls");
        displayBoard();

        // Game loop
        while (winner == 0 && moveCount < 9) {
            if (mode == 1) {
                // Multiplayer mode
                printf("Player %d's turn:\n", (moveCount % 2 == 0) ? 1 : 2);
                userMove((moveCount % 2 == 0) ? 'X' : 'O');
            } else {
                // Computer vs User mode
                if (moveCount % 2 == 0) {
                    printf("Your turn:\n");
                    userMove('X');
                } else {
                    printf("Computer's turn:\n");
                    computerMove();
                }
            }

            system("cls");
            displayBoard();
            winner = checkWinner();
            moveCount++;
        }

        // Check the result
        if (winner == 1) {
            printf("Player X wins!\n");
        } else if (winner == 2) {
            printf("Player O wins!\n");
        } else {
            printf("It's a draw!\n");
        }

        // Ask for replay
        printf("Do you want to play again? (Y/N): ");
        getchar(); // Consume leftover newline
        scanf("%c", &playAgain);

        winner = 0;  // Reset the winner
        moveCount = 0; // Reset the move count
    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 9; i += 3) {
        printf(" %c | %c | %c\n", board[i], board[i + 1], board[i + 2]);
        if (i < 6) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check for a winner
int checkWinner() {
    // Winning combinations
    int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[winCombos[i][0]] == board[winCombos[i][1]] &&
            board[winCombos[i][1]] == board[winCombos[i][2]]) {
            return (board[winCombos[i][0]] == 'X') ? 1 : 2;
        }
    }
    return 0; // No winner yet
}

// Function for user move
void userMove(char player) {
    int move;
    do {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        move--; // Adjust for 0-based indexing
    } while (!isValidMove(move));
    board[move] = player;
}

// Function for computer move
void computerMove() {
    int move;
    srand(time(0));
    do {
        move = rand() % 9;
    } while (!isValidMove(move));
    board[move] = 'O';
}

// Function to check if a move is valid
int isValidMove(int move) {
    return (move >= 0 && move < 9 && board[move] != 'X' && board[move] != 'O');
}
