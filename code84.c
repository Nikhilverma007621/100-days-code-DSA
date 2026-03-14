#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

/* ---------- Max Heap ---------- */

void maxHeapInsert(int val) {
    int i = maxSize++;
    maxHeap[i] = val;

    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[(i - 1) / 2];
        maxHeap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int maxHeapRemove() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;

        if (l < maxSize && maxHeap[l] > maxHeap[largest])
            largest = l;

        if (r < maxSize && maxHeap[r] > maxHeap[largest])
            largest = r;

        if (largest == i)
            break;

        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;

        i = largest;
    }

    return root;
}

/* ---------- Min Heap ---------- */

void minHeapInsert(int val) {
    int i = minSize++;
    minHeap[i] = val;

    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        int temp = minHeap[i];
        minHeap[i] = minHeap[(i - 1) / 2];
        minHeap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int minHeapRemove() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];

    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;

        if (l < minSize && minHeap[l] < minHeap[smallest])
            smallest = l;

        if (r < minSize && minHeap[r] < minHeap[smallest])
            smallest = r;

        if (smallest == i)
            break;

        int temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;

        i = smallest;
    }

    return root;
}

/* ---------- Add Number ---------- */

void addNum(int num) {

    if (maxSize == 0 || num <= maxHeap[0])
        maxHeapInsert(num);
    else
        minHeapInsert(num);

    if (maxSize > minSize + 1)
        minHeapInsert(maxHeapRemove());

    if (minSize > maxSize)
        maxHeapInsert(minHeapRemove());
}

/* ---------- Find Median ---------- */

double findMedian() {

    if (maxSize > minSize)
        return maxHeap[0];

    return (maxHeap[0] + minHeap[0]) / 2.0;
}

/* ---------- Main Function ---------- */

int main() {

    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter numbers:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        addNum(x);

        printf("Current Median: %.2f\n", findMedian());
    }

    return 0;
}