#include <stdio.h>

// DFS function
void dfs(int n, int isConnected[n][n], int visited[], int city) {
    visited[city] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[city][j] == 1 && !visited[j]) {
            dfs(n, isConnected, visited, j);
        }
    }
}

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int isConnected[n][n];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int visited[n];

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(n, isConnected, visited, i);
            provinces++;
        }
    }

    printf("Number of Provinces: %d\n", provinces);

    return 0;
}