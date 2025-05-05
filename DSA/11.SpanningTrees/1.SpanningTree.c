#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph edge
typedef struct 
{
    int u, v, weight;
} Edge;

// Structure to represent a disjoint set (Union-Find)
typedef struct 
{
    int *parent, *rank;
    int n;
} DisjointSet;

// Function to create a disjoint set
DisjointSet* createSet(int n) 
{
    DisjointSet* set = (DisjointSet*)malloc(sizeof(DisjointSet));
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));
    set->n = n;

    for (int i = 0; i < n; i++) 
    {
        set->parent[i] = i; // Initially, each node is its own parent
        set->rank[i] = 0;   // Initially, each node has rank 0
    }

    return set;
}

// Find operation with path compression
int find(DisjointSet* set, int u) 
{
    if (set->parent[u] != u)
        set->parent[u] = find(set, set->parent[u]);
    return set->parent[u];
}

// Union operation with union by rank
void unionSet(DisjointSet* set, int u, int v) 
{
    int rootU = find(set, u);
    int rootV = find(set, v);

    if (rootU != rootV) 
    {
        if (set->rank[rootU] > set->rank[rootV]) 
        {
            set->parent[rootV] = rootU;
        } 
        else if (set->rank[rootU] < set->rank[rootV]) 
        {
            set->parent[rootU] = rootV;
        } 
        else 
        {
            set->parent[rootV] = rootU;
            set->rank[rootU]++;
        }
    }
}

// Comparison function for sorting edges
int compareEdges(const void *a, const void *b) 
{
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal's algorithm to find MST
void kruskal(Edge edges[], int E, int V) 
{
    qsort(edges, E, sizeof(Edge), compareEdges);

    DisjointSet* set = createSet(V);

    int mstWeight = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < E; i++) 
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // If u and v are in different sets, include this edge in the MST
        if (find(set, u) != find(set, v)) 
        {
            printf("%d - %d (Weight: %d)\n", u, v, weight);
            mstWeight += weight;
            unionSet(set, u, v);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);

    // Free the memory allocated for the disjoint set
    free(set->parent);
    free(set->rank);
    free(set);
}

int main() 
{
    int V = 9; // Number of vertices
    int E = 14; // Number of edges

    // Array of edges (u, v, weight)
    Edge edges[] = 
    {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };

    kruskal(edges, E, V);

    return 0;
}