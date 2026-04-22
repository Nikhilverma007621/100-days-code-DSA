#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

// DFS for articulation points
void dfs(int u, int parent, struct Graph* graph,
         int visited[], int tin[], int low[],
         int* timer, int ap[]) {

    visited[u] = 1;
    tin[u] = low[u] = (*timer)++;
    int children = 0;

    struct Node* temp = graph->adj[u];

    while (temp != NULL) {
        int v = temp->vertex;

        if (v == parent) {
            temp = temp->next;
            continue;
        }

        if (!visited[v]) {
            dfs(v, u, graph, visited, tin, low, timer, ap);

            if (low[v] < low[u])
                low[u] = low[v];

            // articulation condition
            if (low[v] >= tin[u] && parent != -1) {
                ap[u] = 1;
            }

            children++;
        } else {
            if (tin[v] < low[u])
                low[u] = tin[v];
        }

        temp = temp->next;
    }

    // root node case
    if (parent == -1 && children > 1) {
        ap[u] = 1;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph graph;
    graph.V = V;

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        graph.adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    int visited[MAX] = {0};
    int tin[MAX], low[MAX];
    int ap[MAX] = {0};
    int timer = 0;

    // Run DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, &graph, visited, tin, low, &timer, ap);
        }
    }

    // Print articulation points
    int found = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("-1");
    }

    return 0;
}