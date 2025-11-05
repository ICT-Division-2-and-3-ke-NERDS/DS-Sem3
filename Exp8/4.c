#include <stdio.h>
#include <limits.h>

#define MAX 20

int findMinKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, minIndex;
    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[MAX][MAX], int n)
{
    int totalCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d -- %d (Weight: %d)\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total Minimum Cost: %d\n", totalCost);
}

void primMST(int graph[MAX][MAX], int n)
{
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = findMinKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nMinimum Spanning Tree using Prim's Algorithm\n");
    primMST(graph, n);

    return 0;
}
