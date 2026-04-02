#include <stdio.h>

// DFS function
void dfs(int n, int isConnected[n][n], int visited[], int city) {
    for(int i = 0; i < n; i++) {
        if(isConnected[city][i] == 1 && !visited[i]) {
            visited[i] = 1;
            dfs(n, isConnected, visited, i);
        }
    }
}

int findProvinces(int n, int isConnected[n][n]) {
    int visited[n];
    
    // Initialize visited array
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int provinces = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            provinces++;
            visited[i] = 1;
            dfs(n, isConnected, visited, i);
        }
    }

    return provinces;
}

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int isConnected[n][n];

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int result = findProvinces(n, isConnected);

    printf("Number of Provinces: %d\n", result);

    return 0;
}