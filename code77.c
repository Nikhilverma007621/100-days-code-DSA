#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (for insert)
void heapifyUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

// Heapify Down (for extractMin)
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert operation
void insert(int value) {
    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Peek operation
void peek() {
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

// Extract Min operation
void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char operation[20];
        scanf("%s", operation);

        if (operation[0] == 'i') {   // insert
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (operation[0] == 'p') {   // peek
            peek();
        }
        else if (operation[0] == 'e') {   // extractMin
            extractMin();
        }
    }

    return 0;
}