#include <stdio.h>
#include <stdlib.h>

#define V_MAX 7
#define E_MAX 9

typedef struct Edge {
    int src, dest, weight;
} Edge;

int parent[V_MAX];

void makeSet() {
    for (int i = 0; i < V_MAX; i++) {
        parent[i] = i;
    }
}

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void Union(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parent[rootB] = rootA;
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

void kruskalMST(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(Edge), compareEdges);

    makeSet();

    Edge resultMST[V - 1];
    int edgeCount = 0;

    printf("Processing edges to build MST:\n");
    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        Edge nextEdge = edges[i];

        int rootSrc = find(nextEdge.src);
        int rootDest = find(nextEdge.dest);

        if (rootSrc != rootDest) {
            resultMST[edgeCount++] = nextEdge;
            Union(nextEdge.src, nextEdge.dest);

            printf("  Included edge (%d - %d) with weight %d (MST Edges: %d)\n",
                    nextEdge.src, nextEdge.dest, nextEdge.weight, edgeCount);
        } else {
            printf("  Rejected edge (%d - %d) with weight %d (Forms a cycle)\n",
                    nextEdge.src, nextEdge.dest, nextEdge.weight);
        }
    }

    printf("\nMinimum Spanning Tree (MST) Edges:\n");
    int minCost = 0;
    for (int i = 0; i < V - 1; i++) {
        printf("  %d -- %d (Weight: %d)\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight);
        minCost += resultMST[i].weight;
    }
    printf("Total Minimum Cost: %d\n", minCost);
}

int main() {
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    int V = 7;
    int E = 9;

    Edge edges[E_MAX] = {
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

    printf("Kruskal's Algorithm for MST\n");
    printf("Graph has %d vertices (0 to %d) and %d edges.\n\n", V, V - 1, E);

    kruskalMST(edges, V, E);

    return 0;
}