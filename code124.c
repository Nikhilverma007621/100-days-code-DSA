#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
void dfs(int room, int** rooms, int* roomsColSize, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(key, rooms, roomsColSize, visited);
        }
    }
}

// Function to check if all rooms can be visited
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));

    dfs(0, rooms, roomsColSize, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}

int main() {
    int n;
    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int** rooms = (int**)malloc(n * sizeof(int*));
    int* roomsColSize = (int*)malloc(n * sizeof(int));

    printf("Enter number of keys in each room:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &roomsColSize[i]);
        rooms[i] = (int*)malloc(roomsColSize[i] * sizeof(int));
    }

    printf("Enter keys for each room:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    if (canVisitAllRooms(rooms, n, roomsColSize)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(rooms[i]);
    }
    free(rooms);
    free(roomsColSize);

    return 0;
}