#include <stdio.h>
#define MAX_NODES 10
int parent[MAX_NODES];

// Function to find the parent of a node
int find(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent[node]); // Path compression
}

// Function to perform the union of two sets
void unionSets(int u, int v) {
    parent[find(u)] = find(v);
}

void kruskalMST(int n, int edges[MAX_NODES][3], int edgeCount) {
    int mincost = 0;

    // Initialize parent array for union-find
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // Sort edges by weight (Bubble sort for simplicity)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                // Swap edges
                int temp[3];
                for (int k = 0; k < 3; k++)
                    temp[k] = edges[j][k];
                for (int k = 0; k < 3; k++)
                    edges[j][k] = edges[j + 1][k];
                for (int k = 0; k < 3; k++)
                    edges[j + 1][k] = temp[k];
            }
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        // Check if including this edge forms a cycle
        if (find(u) != find(v)) {
            unionSets(u, v);
            mincost += weight;
            printf("Edge: (%d - %d) cost: %d\n", u, v, weight);
        }
    }

    printf("Minimum cost of the Minimum Spanning Tree: %d\n", mincost);
}

int main() {
    int n, edgeCount = 0;
    int edges[MAX_NODES][3];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int adjacency[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adjacency[i][j]);
            if (adjacency[i][j] != 0 && i < j) { // Store only one direction of edge
                edges[edgeCount][0] = i;
                edges[edgeCount][1] = j;
                edges[edgeCount][2] = adjacency[i][j];
                edgeCount++;
            }
        }
    }

    kruskalMST(n, edges, edgeCount);
    return 0;
}
