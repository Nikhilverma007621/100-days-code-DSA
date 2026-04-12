#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INF 1000000000

// Function to calculate Manhattan distance
int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int n;
    scanf("%d", &n);

    int points[MAX][2];

    // Input points
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int visited[MAX] = {0};
    int minDist[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        minDist[i] = INF;
    }

    minDist[0] = 0;
    int totalCost = 0;

    // Prim’s Algorithm
    for (int i = 0; i < n; i++) {
        int u = -1;

        // Find minimum distance unvisited node
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = manhattan(points[u][0], points[u][1],
                                     points[v][0], points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    printf("%d\n", totalCost);

    return 0;
}