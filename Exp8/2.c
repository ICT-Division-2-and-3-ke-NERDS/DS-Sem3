#include <stdio.h>

#define MAX 20

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Function to add element to queue
void enqueue(int v)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = v;
}

// Function to remove element from queue
int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    int v = queue[front];
    front++;
    return v;
}

// Breadth First Search (BFS)
void BFS(int adj[MAX][MAX], int n, int start)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);
    while (front <= rear)
    {
        int node = dequeue();
        printf("%d ", node);

        for (int j = 0; j < n; j++)
        {
            if (adj[node][j] == 1 && !visited[j])
            {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}

// Depth First Search (DFS)
void DFSUtil(int adj[MAX][MAX], int n, int v)
{
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && !visited[i])
            DFSUtil(adj, n, i);
    }
}

void DFS(int adj[MAX][MAX], int n, int start)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from vertex %d: ", start);
    DFSUtil(adj, n, start);
    printf("\n");
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    int n, adj[MAX][MAX], start;

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

    printf("Enter starting vertex (0 - %d): ", n - 1);
    scanf("%d", &start);

    printf("\n");
    BFS(adj, n, start);
    DFS(adj, n, start);

    return 0;
}
