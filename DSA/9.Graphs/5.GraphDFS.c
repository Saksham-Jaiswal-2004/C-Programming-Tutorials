#include <stdio.h>
#include <stdlib.h>

void DFS(int adj[][7], int visited[], int i, int size)
{
    printf("%d ", i);
    visited[i] = 1;

    for (int j = 0; j < size; j++)
    {
        if (adj[i][j] == 1 && !visited[j])
        {
            DFS(adj, visited, j, size);
        }
    }
}

void performDFS(int adj[][7], int startNode, int size)
{
    int visited[7] = {0};
    DFS(adj, visited, startNode, size);
}

int main()
{
    int adj[7][7] = {
        // 0  1  2  3  4  5  6
        {0, 1, 0, 1, 0, 0, 0}, // 0
        {1, 0, 1, 1, 0, 0, 0}, // 1
        {0, 1, 0, 0, 1, 0, 0}, // 2
        {1, 1, 0, 0, 1, 1, 0}, // 3
        {0, 0, 1, 1, 0, 0, 1}, // 4
        {0, 0, 0, 1, 0, 0, 1}, // 5
        {0, 0, 0, 0, 1, 1, 0}  // 6
    };

    printf("DFS traversal from node 0:\n");
    performDFS(adj, 0, 7);

    return 0;
}
