#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #define Sleep(x) usleep((x) * 1000)

    int kbhit(void) {
        struct termios oldt, newt;
        int ch;
        int oldf;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        if (ch != EOF) {
            ungetc(ch, stdin);
            return 1;
        }
        return 0;
    }

    char getch() {
        char buf = 0;
        struct termios old = {0};
        fflush(stdout);
        if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0) perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
        return buf;
    }
#endif

#define WIDTH 30
#define HEIGHT 20
#define GAME_DATA_FILE "game_data.txt"
#define HIGH_SCORE_FILE "highscore.txt"
#define FOOD_SOUND "assets/food.wav"
#define GAME_OVER_SOUND "assets/gameover.wav"

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node *head = NULL, *tail = NULL;
int food = 0, foodX, foodY, poisonX = -1, poisonY = -1, goldenFoodX = -1, goldenFoodY = -1;
int score = 0, highScore = 0, gameOver = 0, paused = 0;
char direction = 'R';

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void playSound(const char *filename) {
    char command[200];
#ifdef _WIN32
    sprintf(command, "powershell -c \"(New-Object Media.SoundPlayer '%s').PlaySync();\"", filename);
#elif __APPLE__
    sprintf(command, "afplay \"%s\" &", filename);
#else
    sprintf(command, "aplay \"%s\" >/dev/null 2>&1 &", filename);
#endif
    system(command);
}

void generateFood() {
    foodX = rand() % (WIDTH - 2) + 1;
    foodY = rand() % (HEIGHT - 2) + 1;
}

void generateGoldenFood() {
    goldenFoodX = rand() % (WIDTH - 2) + 1;
    goldenFoodY = rand() % (HEIGHT - 2) + 1;
}

void generatePoison() {
    poisonX = rand() % (WIDTH - 2) + 1;
    poisonY = rand() % (HEIGHT - 2) + 1;
}

void initSnake() {
    head = malloc(sizeof(Node));
    head->x = WIDTH / 2;
    head->y = HEIGHT / 2;
    head->next = NULL;
    tail = head;
}

void loadHighScore() {
    FILE *file = fopen(HIGH_SCORE_FILE, "r");
    if (file) {
        fscanf(file, "%d", &highScore);
        fclose(file);
    }
}

void saveHighScore() {
    if (score > highScore) {
        FILE *file = fopen(HIGH_SCORE_FILE, "w");
        fprintf(file, "%d", score);
        fclose(file);
    }
}

void saveGameData() {
    FILE *file = fopen(GAME_DATA_FILE, "w");
    fprintf(file, "%d", score);
    fclose(file);
}

void draw() {
    clearScreen();
    for (int i = 0; i < WIDTH + 2; i++) printf(RED "█" RESET);
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH + 2; j++) {
            if (j == 0 || j == WIDTH + 1)
                printf(RED "█" RESET);
            else if (i == poisonY && j == poisonX)
                printf(RED "P" RESET);
            else if (i == goldenFoodY && j == goldenFoodX)
                printf(GREEN "$" RESET);
            else if (i == foodY && j == foodX)
                printf(YELLOW "@" RESET);
            else {
                int isBody = 0;
                for (Node* temp = head; temp; temp = temp->next) {
                    if (temp->x == j && temp->y == i) {
                        if (temp == head)
                            printf(CYAN "O" RESET);
                        else
                            printf(GREEN "o" RESET);
                        isBody = 1;
                        break;
                    }
                }
                if (!isBody) printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf(RED "█" RESET);
    printf("\n" YELLOW "Score: %d | High Score: %d\n" RESET, score, highScore);

    if (paused)
        printf(RED "\nGame Paused. Press 'p' to resume.\n" RESET);
}

void moveSnake() {
    if (paused) return;

    int newX = head->x, newY = head->y;
    if (direction == 'U') newY--;
    else if (direction == 'D') newY++;
    else if (direction == 'L') newX--;
    else if (direction == 'R') newX++;

    if (newX == 0 || newX == WIDTH + 1 || newY < 0 || newY >= HEIGHT) {
        gameOver = 1;
        return;
    }

    for (Node* temp = head; temp; temp = temp->next) {
        if (temp->x == newX && temp->y == newY) {
            gameOver = 1;
            return;
        }
    }

    Node* newHead = malloc(sizeof(Node));
    newHead->x = newX;
    newHead->y = newY;
    newHead->next = head;
    head = newHead;

    if (newX == foodX && newY == foodY) {
        score += 10;
        food++;
        generateFood();
        playSound(FOOD_SOUND);
    } else if (newX == poisonX && newY == poisonY) {
        score -= 10;
        generatePoison();
    } else if (newX == goldenFoodX && newY == goldenFoodY) {
        score += 30;
        generateGoldenFood();
    } else {
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        free(temp->next);
        temp->next = NULL;
        tail = temp;
    }
}

void input() {
    if (kbhit()) {
        char key = getch();
        if (key == 'w' && direction != 'D') direction = 'U';
        else if (key == 's' && direction != 'U') direction = 'D';
        else if (key == 'a' && direction != 'R') direction = 'L';
        else if (key == 'd' && direction != 'L') direction = 'R';
        else if (key == 'x') gameOver = 1;
        else if (key == 'p') paused = !paused;
    }
}

void gameLoop() {
    generateFood();
    generateGoldenFood();
    generatePoison();
    initSnake();
    loadHighScore();

    while (!gameOver) {
        draw();
        input();
        moveSnake();
        Sleep(100);
    }

    saveGameData();
    saveHighScore();
    playSound(GAME_OVER_SOUND);
    printf(RED "\nGame Over! Your final score: %d\n" RESET, score);
}

int main() {
    srand(time(NULL));
    clearScreen();
    printf(YELLOW "Welcome to Snake Game!\nPress any key to start..." RESET);
    getch();
    gameLoop();
    return 0;
}
