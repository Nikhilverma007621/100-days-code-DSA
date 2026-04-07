#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int recStack[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add directed edge
void addEdge(int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}

// DFS with recursion stack
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int u = temp->vertex;

        if (!visited[u]) {
            if (dfs(u))
                return 1;
        }
        else if (recStack[u]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

// Check cycle in all components
int isCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Input edges (directed)
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    if (isCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}