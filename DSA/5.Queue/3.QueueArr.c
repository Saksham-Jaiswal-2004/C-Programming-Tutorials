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
    if(q->rear == q->size-1)
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
        printf("%d Enqueued\n", val);
        q->arr[++q->rear] = val;
    }
}

void dequeue(struct Queue* q)
{
    if(isEmpty(q))
    printf("Queue Underflow!\n");
    else
    {
        q->front++;
        printf("%d Dequeued\n", q->arr[q->front]);
    }
}

int main()
{
    struct Queue q;
    q.size = 4;
    q.front = q.rear = -1;
    q.arr = (int*) malloc(sizeof(int) * q.size);

    printf("Before Enqueue and Dequeue:\n");
    if(isFull(&q))
    printf("Queue is Full.\n");
    else
    printf("Queue is not Full.\n");
    if(isEmpty(&q))
    printf("Queue is Empty.\n");
    else
    printf("Queue is not Empty.\n");

    enqueue(&q, 54);
    enqueue(&q, 38);
    enqueue(&q, 71);
    enqueue(&q, 43);
    enqueue(&q, 91);

    dequeue(&q);
    dequeue(&q);

    printf("After Enqueue and Dequeue:\n");
    if(isFull(&q))
    printf("Queue is Full.\n");
    else
    printf("Queue is not Full.\n");
    if(isEmpty(&q))
    printf("Queue is Empty.\n");
    else
    printf("Queue is not Empty.\n");

    return 0;
}