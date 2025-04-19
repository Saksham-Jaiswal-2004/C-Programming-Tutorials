#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

bool isFull(struct Queue* q)
{
    if((q->rear+1)%q->size == q->front || q->rear == q->size-1)
    return true;
    else
    return false;
}

bool isEmpty(struct Queue* q)
{
    if(q->front == q->rear)
    return true;
    else
    return false;
}

void enqueue(struct Queue* q, int val)
{
    if(isFull(q))
    printf("Queue Overflow!\n");
    else
    {
        q->arr[(++q->rear)%q->size] = val;
    }
}

void dequeue(struct Queue* q)
{
    if(isEmpty(q))
    printf("Queue Underflow!\n");
    else
    {
        q->front = (++q->front)%q->size;
    }
}

void printQueue(struct Queue* q)
{
    for(int i=q->front+1 ; i<=q->rear ; i++)
    {
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    q.size = 4;
    q.front = q.rear = -1;
    q.arr = (int*) malloc(sizeof(int) * q.size);

    enqueue(&q, 54);
    enqueue(&q, 38);
    enqueue(&q, 71);
    enqueue(&q, 43);
    enqueue(&q, 439);

    printQueue(&q);
    printf("\n");

    dequeue(&q);
    dequeue(&q);

    printQueue(&q);
    printf("\n");

    return 0;
}