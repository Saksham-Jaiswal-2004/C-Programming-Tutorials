#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
    int size;
} Queue;

void initialize(Queue* q)
{
    q->front = q->rear = NULL;
    q->size = 0;
}

int isEmpty(Queue* q)
{
    if(q->size == 0)
    return 1;
    else
    return 0;
}

int isFull(Queue* q)
{
    if(q->size == MAX)
    return 1;
    else
    return 0;
}

void insertChar(Queue *q, char ch)
{
    if(isFull(q))
    {
        printf("Queue is Full!\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = ch;
    newNode->next = NULL;

    if (isEmpty(q)) 
    {
        q->front = q->rear = newNode;
    } else 
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

void deleteChar(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is already empty!\n");
        return;
    }

    Node *temp = q->front, *prev = NULL;

    q->front = q->front->next;

    if (q->front == NULL) 
    {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
}

void display(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty!");
        return;
    }

    Node* temp = q->front;

    while(temp)
    {
        printf("%c ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Queue q;
    char temp;

    initialize(&q);

    for(int i=0 ; i<10 ; i++)
    {
        insertChar(&q, (char)(65+i));
    }

    printf("Initial Queue: ");
    display(&q);

    deleteChar(&q);
    deleteChar(&q);
    deleteChar(&q);

    printf("Queue after deletion of Element: ");
    display(&q);

    printf("Enter character to be inserted: ");
    scanf("%c", &temp);

    insertChar(&q, temp);

    printf("Queue after insertion of Element: ");
    display(&q);
    return 0;
}