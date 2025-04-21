#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for adjacency list
struct Node 
{
    int vertex;
    struct Node* next;
};

// Queue structure
struct Queue 
{
    int size;
    int front;
    int rear;
    int* arr;
};

bool isFull(struct Queue* q) 
{
    return q->rear == q->size - 1;
}

bool isEmpty(struct Queue* q) 
{
    return q->front == q->rear;
}

void enqueue(struct Queue* q, int val) 
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

int dequeue(struct Queue* q) 
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

// Create a node
struct Node* createNode(int v) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// BFS using adjacency list
void BFS(struct Node* adjList[], int nodes) 
{
    struct Queue q;
    q.size = nodes;
    q.front = q.rear = -1;
    q.arr = (int*) malloc(sizeof(int) * q.size);

    int visited[nodes];
    for (int i = 0; i < nodes; i++) visited[i] = 0;

    int i = 0;
    printf("BFS Traversal starting from node %d:\n", i);
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q)) 
    {
        int node = dequeue(&q);
        struct Node* temp = adjList[node];

        while (temp != NULL)
        {
            int adjNode = temp->vertex;
            if (!visited[adjNode]) 
            {
                printf("%d ", adjNode);
                visited[adjNode] = 1;
                enqueue(&q, adjNode);
            }
            temp = temp->next;
        }
    }

    free(q.arr);
}

int main() 
{
    int nodes = 7;

    // Initialize adjacency list
    struct Node* adjList[7];
    for (int i = 0; i < 7; i++)
    adjList[i] = NULL;

    // Define edges from your matrix
    int edges[][2] = 
    {
        {0,1}, {0,3},
        {1,2}, {1,3},
        {2,4},
        {3,4}, {3,5},
        {4,6},
        {5,6}
    };

    int edgeCount = sizeof(edges)/sizeof(edges[0]);

    // Build the adjacency list
    for (int i = 0; i < edgeCount; i++) 
    {
        int u = edges[i][0];
        int v = edges[i][1];

        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u); // since it's undirected
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    BFS(adjList, nodes);

    // Free memory
    for (int i = 0; i < nodes; i++) 
    {
        struct Node* temp = adjList[i];
        while (temp) 
        {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}