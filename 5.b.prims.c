#include <stdio.h>
#define MAX_NODES 10

int n;
int cost[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int mincost = 0; 

void primMST() {
    visited[1] = 1;
    //n vertices has n-1 edges
    for (int i = 1; i <= n - 1; i++) {
        int min = 999; // Initialize minimum cost to a large value
        int u, v;

        //harek visited yaa unvisited node maa traverse garney
        
        for (int j = 1; j <= n; j++) {
            if (visited[j]) { // jun node (j) visited cha tyas node ko connected node herney
                for (int k = 1; k <= n; k++) {
                    //!visited[k] ensures k node visited chhaina bhaney matra
                    // j,k ko weight lai considered garney
                    if (!visited[k] && cost[j][k] < min) {
                        min = cost[j][k];
                        u = j; // The visited vertex
                        v = k; // unvisited vertex
                    }
                }
            }
        }

        visited[v] = 1; // Mark the unvisited vertex as visited
        mincost += min; // Add the minimum cost to the total cost
        printf("Edge %d: (%d - %d) cost: %d\n", i, u, v, min);

        cost[u][v]= 999; // Mark the edge as visited by setting cost to infinity
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Set absent edges to infinity
            }
        }
    }

    primMST(); // Call the MST calculation function

    printf("Minimum cost of the Minimum Spanning Tree: %d\n", mincost);

    return 0;
}

/*
Enter the number of nodes: 5
Enter the adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Sample Output:
Edges in the Minimum Spanning Tree:
Edge: (1 - 2) cost: 2
Edge: (2 - 3) cost: 3
Edge: (1 - 4) cost: 6
Edge: (2 - 5) cost: 5
Minimum cost of the Minimum Spanning Tree: 16

*/
