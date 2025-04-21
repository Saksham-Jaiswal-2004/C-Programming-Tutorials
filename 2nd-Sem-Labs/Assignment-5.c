#include<stdio.h>
#include<stdlib.h>

struct node
{
    char val;
    struct node* next;
};

struct Queue
{
    struct node* front;
    struct node* rear;
};

struct node* createNode(char data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->val = data;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = createNode('a'); 

    for(int i=0 ; i<10 ; i++)
    {
        q->rear->next = createNode((char)(i+98));
        q->rear = q->rear->next;
    }

    struct node* temp = q->front;

    for(int i=0 ; i<10 ; i++)
    {
        printf("%c ", temp->val);
        temp = temp->next;
    }
    return 0;
}