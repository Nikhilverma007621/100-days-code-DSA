#include <stdio.h>
#include <limits.h>

#define SIZE 101

int findCheapestPrice(int n, int flights[][3], int flightsSize, int src, int dst, int k) {
    int dist[SIZE], temp[SIZE];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax edges k+1 times
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

int main() {
    int n, m;

    printf("Enter number of cities and flights: ");
    scanf("%d %d", &n, &m);

    int flights[1000][3];

    printf("Enter flights (from to price):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &flights[i][0], &flights[i][1], &flights[i][2]);
    }

    int src, dst, k;
    printf("Enter src, dst and k: ");
    scanf("%d %d %d", &src, &dst, &k);

    int result = findCheapestPrice(n, flights, m, src, dst, k);

    if (result == -1)
        printf("No valid route\n");
    else
        printf("Cheapest Price: %d\n", result);

    return 0;
}