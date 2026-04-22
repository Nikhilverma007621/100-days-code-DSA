#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with large values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;  // undirected graph
    }

    int key[MAX], visited[MAX];

    // Initialize keys and visited
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from node 1
    key[1] = 0;

    int total_weight = 0;

    // Prim's Algorithm
    for (int i = 1; i <= n; i++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;

        total_weight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total_weight);

    return 0;
}