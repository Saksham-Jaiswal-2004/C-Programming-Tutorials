#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};

int isEmpty(struct node* top)
{
    if(top == NULL)
    return 1;

    return 0;
}

int isFull(struct node* top)
{
    struct node* p = (struct node*) malloc(sizeof(struct node));

    if(p == NULL)
    return 1;

    return 0;
}

struct node* push(struct node* top, int data)
{
    if(isFull(top))
    {
        printf("Stack Overflow!\n");
        return NULL;
    }
    else
    {
        struct node* n = (struct node*) malloc(sizeof(struct node));
        n->val = data;
        n->next = top;
        top = n;
        return n;
    }
}

void printStack(struct node* top)
{
    while(top != NULL)
    {
        printf("%d ", top->val);
        top = top->next;
    }
}

int main()
{
    struct node* top = NULL;
    top = push(top, 65);
    top = push(top, 7);
    top = push(top, 42);

    printStack(top);
    return 0;
}