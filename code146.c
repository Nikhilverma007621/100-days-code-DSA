#include <stdio.h>
#include <stdlib.h>

// Find with path compression
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union function
int unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py)
        return 0; // cycle found

    parent[py] = px;
    return 1;
}

int main() {
    int n;

    printf("Enter number of edges: ");
    scanf("%d", &n);

    int edges[n][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int parent[n + 1];

    // Initialize parent array
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int ans[2] = {-1, -1};

    // Process edges
    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (!unionSet(parent, u, v)) {
            ans[0] = u;
            ans[1] = v;
        }
    }

    // Output result
    printf("Redundant edge: [%d, %d]\n", ans[0], ans[1]);

    return 0;
}