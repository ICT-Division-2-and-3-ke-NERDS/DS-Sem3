#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src;
    int dest;
    int weight;
};

int parent[20];

int findParent(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent[i]);
}

void unionSet(int a, int b)
{
    int rootA = findParent(a);
    int rootB = findParent(b);
    if (rootA != rootB)
        parent[rootB] = rootA;
}

int compare(const void *a, const void *b)
{
    struct Edge *edgeA = (struct Edge *)a;
    struct Edge *edgeB = (struct Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void makeSet(int V)
{
    for (int i = 0; i < V; i++)
        parent[i] = i;
}

void kruskalMST(struct Edge edges[], int V, int E)
{
    qsort(edges, E, sizeof(struct Edge), compare);
    makeSet(V);

    struct Edge result[V - 1];
    int edgeCount = 0;
    int totalCost = 0;

    for (int i = 0; i < E && edgeCount < V - 1; i++)
    {
        int srcRoot = findParent(edges[i].src);
        int destRoot = findParent(edges[i].dest);

        if (srcRoot != destRoot)
        {
            result[edgeCount++] = edges[i];
            unionSet(srcRoot, destRoot);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < edgeCount; i++)
    {
        printf("%d -- %d (Weight: %d)\n", result[i].src, result[i].dest, result[i].weight);
        totalCost += result[i].weight;
    }

    printf("Total Minimum Cost: %d\n", totalCost);
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    int V = 7;
    int E = 9;

    struct Edge edges[9] = {
        {0, 1, 2},
        {0, 3, 4},
        {1, 2, 3},
        {1, 4, 7},
        {2, 3, 5},
        {2, 5, 8},
        {3, 6, 1},
        {4, 5, 6},
        {5, 6, 9}
    };

    printf("Minimum Spanning Tree using Kruskal's Algorithm\n");
    printf("Number of Vertices: %d\n", V);
    printf("Number of Edges: %d\n\n", E);

    kruskalMST(edges, V, E);

    return 0;
}
