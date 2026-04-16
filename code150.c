#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue structure
typedef struct {
    int *data;
    int front, rear;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(size * sizeof(int));
    q->front = q->rear = 0;
    return q;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

bool isBipartite(int **graph, int n, int *colSize) {
    int *color = (int*)malloc(n * sizeof(int));

    // Initialize colors
    for (int i = 0; i < n; i++)
        color[i] = -1;

    // Check each component
    for (int i = 0; i < n; i++) {
        if (color[i] != -1) continue;

        Queue* q = createQueue(n);
        enqueue(q, i);
        color[i] = 0;

        while (!isEmpty(q)) {
            int node = dequeue(q);

            for (int j = 0; j < colSize[node]; j++) {
                int neighbor = graph[node][j];

                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    enqueue(q, neighbor);
                } else if (color[neighbor] == color[node]) {
                    free(color);
                    free(q->data);
                    free(q);
                    return false;
                }
            }
        }

        free(q->data);
        free(q);
    }

    free(color);
    return true;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int **graph = (int**)malloc(n * sizeof(int*));
    int *colSize = (int*)malloc(n * sizeof(int));

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        printf("Enter number of neighbors of node %d: ", i);
        scanf("%d", &colSize[i]);

        graph[i] = (int*)malloc(colSize[i] * sizeof(int));

        printf("Enter neighbors of node %d: ", i);
        for (int j = 0; j < colSize[i]; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isBipartite(graph, n, colSize))
        printf("Graph is Bipartite\n");
    else
        printf("Graph is NOT Bipartite\n");

    // Free memory
    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    free(colSize);

    return 0;
}