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
        // printf("%d Enqueued\n", val);
        q->arr[++q->rear] = val;
    }
}

int dequeue(struct Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return -1;
    }
    else
    {
        q->front++;
        // printf("%d Dequeued\n", q->arr[q->front]);
        return q->arr[q->front];
    }
}

void BFS(int adj[][7])
{
    struct Queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int*) malloc(sizeof(int) * q.size);

    int node, i=0;
    int visited[7] = {0};
    int size = sizeof(adj[0])/sizeof(adj[0][0]);

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);

    while(!isEmpty(&q))
    {
        int node = dequeue(&q);

        for(int j=0 ; j<size ; j++)
        {
            if(adj[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}

int main()
{
    int adj[7][7] = {
        // 0  1  2  3  4  5  6
        { 0, 1, 0, 1, 0, 0, 0 }, // 0
        { 1, 0, 1, 1, 0, 0, 0 }, // 1
        { 0, 1, 0, 0, 1, 0, 0 }, // 2
        { 1, 1, 0, 0, 1, 1, 0 }, // 3
        { 0, 0, 1, 1, 0, 0, 1 }, // 4
        { 0, 0, 0, 1, 0, 0, 1 }, // 5
        { 0, 0, 0, 0, 1, 1, 0 }  // 6
    };

    BFS(adj);

    return 0;
}