#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct
{
    int items[MAX];
    int front, rear;
} Queue;

void initialize(Queue* q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue* q)
{
    return q->rear == MAX-1;
}

int isEmpty(Queue* q)
{
    return q->front==-1 || q->front > q->rear;
}

void enqueue(Queue* q, int data)
{
    if(isFull(q))
    {
        printf("Queue is full! Cannot add elements.\n");
    }
    if(isEmpty(q))
    {
        q->front=0;
    }

    q->items[++q->rear] = data;
    printf("Data enqueued!\n");
}

void dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is already empty! Cannot delete elements.\n");
        return;
    }

    q->front++;

    if(q->front>q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }

    printf("Data dequeued!\n");
}

void peek(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("First Element: %d", q->items[q->front]);
}

void display(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }

    for(int i=q->front ; i<=q->rear ; i++)
    {
        printf("%d ",q->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    initialize(&q);

    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}