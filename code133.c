#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }

    stack[++top] = v;
}

// Topological Sort
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topologicalSort(V);

    return 0;
}