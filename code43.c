#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) return 0;

    int value;
    scanf("%d", &value);

    struct Node* head = createNode(value);
    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        temp->next = createNode(value);
        temp = temp->next;
    }

    printList(head);
    printf("\n");

    int total = countNodes(head);
    printf("Total Nodes: %d\n", total);

    return 0;
}