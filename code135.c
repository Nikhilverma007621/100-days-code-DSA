#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];
    int indegree[MAX] = {0};

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Add all vertices with indegree 0 to queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;
    int topo[MAX];

    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (j = 0; j < n; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    // Check for cycle
    if (count != n) {
        printf("Graph has a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}