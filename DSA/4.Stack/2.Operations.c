#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

// Function to check if Stack is empty or not
int isEmpty(struct stack* p)
{
    if(p->top == -1)
    return 1;

    return 0;
}

// Function to check is Stack is full or not
int isFull(struct stack* p)
{
    if(p->top == (p->size-1))
    return 1;

    return 0;
}

// Function to add an element in the Stack
void push(struct stack* p, int data)
{
    if(isFull(p))
    {
        printf("Stack Overflow.\n");
        return;
    }
    
    p->arr[++p->top] = data;
}

// Function to remove an element from the Stack
int pop(struct stack* p)
{
    if(isEmpty(p))
    {
        printf("Stack Empty.\n");
        return -1;
    }
    else
    {
        return p->arr[p->top--];
    }
}

int peek(struct stack* p, int i)
{
    if(isEmpty(p))
    return -1;
    else if((p->top - i +1) < 0)
    {
        printf("Not a Valid Position.\n");
        return -1;
    }
    else
    return p->arr[p->top - i + 1];
}

int main()
{
    struct stack* sp = (struct stack*) malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int*) malloc(sp->size * sizeof(int));

    printf("Before Pushing:\n");
    printf("Full: %d\n", isFull(sp));
    printf("Empty: %d\n", isEmpty(sp));

    push(sp, 45);
    push(sp, 65);
    push(sp, 24);
    push(sp, 17);
    push(sp, 78);

    printf("\nAfter Pushing:\n");
    printf("Full: %d\n", isFull(sp));
    printf("Empty: %d\n", isEmpty(sp));

    printf("\n");

    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);

    // printf("\nAfter Poping:\n");
    // printf("Full: %d\n", isFull(sp));
    // printf("Empty: %d\n\n", isEmpty(sp));

    for(int i=1 ; i<=sp->top+1 ; i++)
    printf("Element at %d in Stack is: %d\n", i, peek(sp, i));

    return 0;
}