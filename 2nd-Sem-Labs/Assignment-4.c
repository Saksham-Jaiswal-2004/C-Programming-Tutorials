// Tower Of Hanoi
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// Structure to implement stack to solve Tower of Hanoi
struct Stack 
{
    int top;
    int array[10];
};

// Initialize stack
void initialize(struct Stack* s) 
{
    s->top = -1;
}

// Check if stack is empty
bool isEmpty(struct Stack* s) 
{
    return s->top == -1;
}

// Push data to stack
void push(struct Stack* s, int data) 
{
    s->top++;
    s->array[s->top] = data;
}

// Pop data from stack
int pop(struct Stack* s) 
{
    if (isEmpty(s))
        return -1;
    return s->array[s->top--];
}

// Print stack content
void printStack(struct Stack* s, char name) 
{
    int i;
    printf("%c: ", name);
    if (isEmpty(s)) 
    {
        printf("(Empty)");
    } 
    else 
    {
        for (i = 0; i <= s->top; i++) 
        {
            printf("%d ", s->array[i]);
        }
    }
    printf("\n");
}

// Print all stacks
void printStacks(struct Stack* Source, struct Stack* Auxiliary, struct Stack* Destination, char s, char a, char d) 
{
    printf("Current state of stacks:\n");
    printStack(Source, s);
    printStack(Auxiliary, a);
    printStack(Destination, d);
    printf("--------------------------\n");
}

// Move disk between two stacks
void moveDisk(struct Stack* source, struct Stack* destination, char s, char d) 
{
    int disk1 = pop(source);
    int disk2 = pop(destination);

    if (disk1 == -1) 
    {
        push(source, disk2);
        printf("Moved disk %d from %c to %c\n", disk2, d, s);
    } 
    else if (disk2 == -1) 
    {
        push(destination, disk1);
        printf("Moved disk %d from %c to %c\n", disk1, s, d);
    } 
    else if (disk1 > disk2) 
    {
        push(source, disk1);
        push(source, disk2);
        printf("Moved disk %d from %c to %c\n", disk2, d, s);
    } 
    else 
    {
        push(destination, disk2);
        push(destination, disk1);
        printf("Moved disk %d from %c to %c\n", disk1, s, d);
    }
}

// Tower of Hanoi using stack
void towerOfHanoi(int n, int rep) 
{
    int i;
    int moves = (int)pow(2, n) - 1;
    printf("Total moves required to solve Tower of Hanoi: %d\n", moves);

    struct Stack Source, Auxiliary, Destination;
    char s = 'A', a = 'B', d = 'C';

    initialize(&Source);
    initialize(&Auxiliary);
    initialize(&Destination);

    for (i = n; i >= 1; i--) 
    {
        push(&Source, i);
    }

    if (n % 2 == 0) 
    {
        char temp = d;
        d = a;
        a = temp;
    }

    if (rep) 
    {
        if (n % 2 == 0)
            printStacks(&Source, &Destination, &Auxiliary, s, d, a);
        else
            printStacks(&Source, &Auxiliary, &Destination, s, a, d);
    }

    for (i = 1; i <= moves; i++) 
    {
        if (i % 3 == 1)
            moveDisk(&Source, &Destination, s, d);
        else if (i % 3 == 2)
            moveDisk(&Source, &Auxiliary, s, a);
        else if (i % 3 == 0)
            moveDisk(&Auxiliary, &Destination, a, d);

        if (rep) 
        {
            if (n % 2 == 0)
                printStacks(&Source, &Destination, &Auxiliary, s, d, a);
            else
                printStacks(&Source, &Auxiliary, &Destination, s, a, d);
        }
    }
}

int main() 
{
    int disks, counter;

    printf("Enter number of disks: ");
    scanf("%d", &disks);

    printf("Do you want representation of each step as well? (1 = YES): ");
    scanf("%d", &counter);

    if (counter == 1)
        towerOfHanoi(disks, 1);
    else
        towerOfHanoi(disks, 0);

    return 0;
}
