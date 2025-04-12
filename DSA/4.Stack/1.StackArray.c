#include<stdio.h>
#include<stdlib.h>

// Implementation of Stack using Array
// Here we are creating a basic structure for a stack
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

int main()
{
    // AAM ZINDAGI
    // struct stack s;
    // s.size = 4;
    // s.top = -1;
    // s.arr = (int*) malloc(s.size * sizeof(int));

    // MENTOS ZINDAGI
    // struct stack* s;
    struct stack* s = (struct stack*) malloc(sizeof(struct stack));
    s->size = 4;
    s->top = -1;
    s->arr = (int*) malloc(s->size * sizeof(int)); // Making Array of stack of size 4 (in this case)

    printf("Stack Empty? %d\n", isEmpty(s));
    printf("Stack Full? %d\n", isFull(s));

    for(int i=0 ; i<s->size ; i++)
    {
        s->arr[++s->top] = 7+i;
    }

    printf("Stack Empty? %d\n", isEmpty(s));
    printf("Stack Full? %d\n", isFull(s));

    free(s->arr);
    free(s);

    return 0;
}