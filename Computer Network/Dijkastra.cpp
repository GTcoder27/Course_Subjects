#include<stdio.h>
#include<stdlib.h>

#define INFINITE 999

//function prototype
void dijkstraBacktrack(int n,  int cost[10][10], int s, int t, int dist[10], int currentDist, int *minDist);

int main() {
    int i, j, n, s, cost[10][10], dist[10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            //if cost is zero then it is considered to br infinite
            if (cost[i][j] == 0) {
                cost[i][j] = INFINITE;
            }
        }
    }
    printf("Enter the source node: ");
    scanf("%d", &s);

    // Initialize minimum distance to a large value
    int minDist = INFINITE;
    // Find shortest path using backtracking
    dijkstraBacktrack(n, cost, s, s, dist, 0, &minDist);

    // Display the shortest path from the source node
    printf("Shortest path from %d is:\n", s);
    for (i = 1; i <= n; i++) {
        if (s != i) {
            printf("%d->%d=%d\n", s, i, dist[i]);
        }
    }
    return 0;
}

void dijkstraBacktrack(int n,  int cost[10][10], int s, int t, int dist[10], int currentDist, int *minDist) {
    if (s == t) {
        if (currentDist < *minDist) {
            *minDist = currentDist;
            for (int i = 1; i <= n; i++) {
                dist[i] = cost[s][i];
            }
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (cost[s][i] != INFINITE) {
            int tempDist = cost[s][i];
            // Marking the current edge as visited
            cost[s][i] = INFINITE; 

            // function call to explore the next node
            dijkstraBacktrack(n, cost, i, t, dist, currentDist + tempDist, minDist);

            // Backtrack: restore the cost matrix
            cost[s][i] = tempDist; 
        }
    }
}
