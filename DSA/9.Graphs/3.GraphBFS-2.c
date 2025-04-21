#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue 
{
    int size;
    int front;
    int rear;
    int *arr;
};

bool isFull(struct Queue *q) 
{
    return q->rear == q->size - 1;
}

bool isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

void enqueue(struct Queue *q, int val) 
{
    if (isFull(q)) 
    {
        printf("Queue Overflow!\n");
    } 
    else 
    {
        q->arr[++q->rear] = val;
    }
}

int dequeue(struct Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue Underflow!\n");
        return -1;
    } 
    else 
    {
        return q->arr[++q->front];
    }
}

void BFS(int **adj, int nodes) 
{
    struct Queue q;
    q.size = nodes + 1;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(sizeof(int) * q.size);

    int visited[nodes];

    for (int i = 0; i < nodes; i++) 
    visited[i] = 0;

    int i = 0;
    printf("BFS Traversal starting from node %d:\n", i);
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q)) 
    {
        int node = dequeue(&q);
        for (int j = 0; j < nodes; j++) 
        {
            if (adj[node][j] == 1 && visited[j] == 0) 
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    free(q.arr);
}

int main() 
{
    int nodes;
    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    // Dynamic allocation for 2D array
    int **adj = (int **)malloc(nodes * sizeof(int *));
    for (int i = 0; i < nodes; i++) 
    {
        adj[i] = (int *)malloc(nodes * sizeof(int));
    }

    printf("Enter the adjacency matrix (%d x %d):\n", nodes, nodes);
    for (int i = 0; i < nodes; i++) 
    {
        for (int j = 0; j < nodes; j++) 
        {
            scanf("%d", &adj[i][j]);
        }
    }

    BFS(adj, nodes);

    // Free the adjacency matrix
    for (int i = 0; i < nodes; i++) 
    {
        free(adj[i]);
    }
    free(adj);

    return 0;
}
