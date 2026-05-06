// Bucket Sort in C for numbers in range [0,1)
// VS Code Compatible

#include <stdio.h>
#include <stdlib.h>

// Structure for bucket using linked list
struct Node {
    float data;
    struct Node* next;
};

// Function to insert node in sorted order
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse and insert
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Bucket Sort Function
void bucketSort(float arr[], int n) {
    // Create n buckets
    struct Node* buckets[n];

    // Initialize buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets into array
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];

        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

// Main Function
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter %d numbers between 0 and 1:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }

    return 0;
}