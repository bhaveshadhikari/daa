#include <stdio.h>
#define V 4
#define INF 99999

void printSolution(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int dist[][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

int main() {
    int graph[V][V] = { 
        { 0, 2, INF, 7 },
        { INF, 0, 3, INF },
        { INF, INF, 0, 1 },
        { INF, INF, INF, 0 } 
    };
    
    floydWarshall(graph);
    return 0;
}

/*
Shortest distances between every pair of vertices:
      0      2      5      6
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0


*/
