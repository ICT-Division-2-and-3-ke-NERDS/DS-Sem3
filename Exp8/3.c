#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];  // Used for directed graph cycle detection

// ---------- Directed Graph Cycle Detection ----------
int isCyclicDirectedUtil(int v, int n)
{
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i])
        {
            if (!visited[i] && isCyclicDirectedUtil(i, n))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int isCyclicDirected(int n)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCyclicDirectedUtil(i, n))
                return 1;
        }
    }
    return 0;
}

// ---------- Undirected Graph Cycle Detection ----------
int isCyclicUndirectedUtil(int v, int visited[], int parent, int n)
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i])
        {
            if (!visited[i])
            {
                if (isCyclicUndirectedUtil(i, visited, v, n))
                    return 1;
            }
            else if (i != parent)
            {
                return 1;
            }
        }
    }
    return 0;
}

int isCyclicUndirected(int n)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCyclicUndirectedUtil(i, visited, -1, n))
                return 1;
        }
    }
    return 0;
}

// ---------- Main Function ----------
int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    int n, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nChoose Graph Type:\n1. Directed Graph\n2. Undirected Graph\nEnter your choice: ");
    scanf("%d", &choice);

    int result = 0;
    if (choice == 1)
    {
        result = isCyclicDirected(n);
        if (result)
            printf("\nCycle detected in the Directed Graph.\n");
        else
            printf("\nNo cycle found in the Directed Graph.\n");
    }
    else if (choice == 2)
    {
        result = isCyclicUndirected(n);
        if (result)
            printf("\nCycle detected in the Undirected Graph.\n");
        else
            printf("\nNo cycle found in the Undirected Graph.\n");
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}
