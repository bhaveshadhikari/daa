#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10
#define INFINITY 999

int n; // Number of nodes
int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix representing edge weights
int distance[MAX_NODES] ; // Shortest distance from source to each node
int pred[MAX_NODES]; // Predecessor array to store the shortest path
bool visited[MAX_NODES]; // To track visited nodes

int findMinDistance() {
    int min = INFINITY;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printPath(int node, int source) {
    if (node == source) {
        printf("%d ", node);
        return;
    }
    printPath(pred[node], source);
    printf("%d ", node);
}

void dijkstra(int source) {
    for (int i = 0; i < n; i++) {
        distance[i] = INFINITY;
        visited[i] = false;
    }
    distance[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance();
        if (u == -1) {
            break; // No more reachable nodes
        }
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(source);

    printf("Shortest distances from node %d:\n", source);
    for (int i = 0; i < n; i++) {
        printf("Node %d: %d, Path: ", i, distance[i]);
        printPath(i, source);
        printf("\n");
    }

    return 0;
}

/*
Enter the number of nodes: 6
Enter the adjacency matrix:
0 3 2 7 0 0
3 0 0 0 5 0
2 0 0 5 2 0
7 0 5 0 0 6
0 5 2 0 0 1
0 0 0 6 1 0
Enter the source node: 0
Shortest distances from node 0:
Node 0: 0, Path: 0
Node 1: 3, Path: 0 1
Node 2: 2, Path: 0 2
Node 3: 7, Path: 0 3
Node 4: 4, Path: 0 2 4
Node 5: 5, Path: 0 2 4 5
*/
