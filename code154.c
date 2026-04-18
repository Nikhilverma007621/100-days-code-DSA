#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// adjacency list
int *graph[MAX];
int graphSize[MAX];

// Tarjan arrays
int disc[MAX], low[MAX];
int timeCounter;

// store result
int result[MAX][2];
int resultSize = 0;

// DFS
void dfs(int u, int parent) {
    disc[u] = low[u] = ++timeCounter;

    for (int i = 0; i < graphSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (disc[v] == 0) {
            dfs(v, u);

            if (low[v] < low[u])
                low[u] = low[v];

            // bridge condition
            if (low[v] > disc[u]) {
                result[resultSize][0] = u;
                result[resultSize][1] = v;
                resultSize++;
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;

    // Input
    scanf("%d %d", &n, &m);

    // allocate adjacency list
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(m * sizeof(int)); // safe size
        graphSize[i] = 0;
        disc[i] = 0;
        low[i] = 0;
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    // run DFS
    for (int i = 0; i < n; i++) {
        if (disc[i] == 0) {
            dfs(i, -1);
        }
    }

    // output
    for (int i = 0; i < resultSize; i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }

    return 0;
}