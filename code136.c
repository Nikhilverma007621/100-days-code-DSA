#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 26

int adj[MAX][MAX];
int indegree[MAX];
int present[MAX];

// Queue
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

// Main function to find alien order
void alienOrder(char words[][100], int n) {
    memset(adj, 0, sizeof(adj));
    memset(indegree, 0, sizeof(indegree));
    memset(present, 0, sizeof(present));

    // Mark characters present
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);
        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // Invalid case: prefix issue
        if (!found && len1 > len2) {
            printf("\"\n");
            return;
        }
    }

    // Push nodes with indegree 0
    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            enqueue(i);
        }
    }

    char result[MAX];
    int idx = 0;

    while (!isEmpty()) {
        int u = dequeue();
        result[idx++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    // Count unique characters
    int total = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) total++;
    }

    // Cycle check
    if (idx != total) {
        printf("\"\n");
        return;
    }

    result[idx] = '\0';
    printf("%s\n", result);
}

// Driver
int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[500][100];

    printf("Enter words:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    alienOrder(words, n);

    return 0;
}