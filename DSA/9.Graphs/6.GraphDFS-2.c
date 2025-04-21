#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node 
{
    int vertex;
    struct Node* next;
};

// DFS helper function
void DFS(struct Node* adjList[], int visited[], int i) 
{
    printf("%d ", i);
    visited[i] = 1;

    struct Node* temp = adjList[i];
    while (temp != NULL) 
    {
        if (!visited[temp->vertex]) 
        {
            DFS(adjList, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

// Function to create a new node
struct Node* createNode(int v) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Modular function to perform DFS traversal
void performDFS(int edges[][2], int edgeCount, int nodes, int startNode) 
{
    struct Node* adjList[nodes];
    for (int i = 0; i < nodes; i++)
        adjList[i] = NULL;

    // Create adjacency list
    for (int i = 0; i < edgeCount; i++) 
    {
        int u = edges[i][0];
        int v = edges[i][1];

        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    int visited[nodes];
    for (int i = 0; i < nodes; i++)
        visited[i] = 0;

    DFS(adjList, visited, startNode);

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
}

int main() 
{
    int nodes = 7;
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

    printf("DFS traversal from node 0:\n");
    performDFS(edges, edgeCount, nodes, 0);

    return 0;
}
