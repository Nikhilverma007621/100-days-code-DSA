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

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next; 
        current->next = prev;     
        prev = current;           
        current = nextNode;       
    }

    return prev;  
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("List is empty\n");
        return 0;
    }

    printf("Enter elements: ");
    scanf("%d", &value);

    struct Node* head = createNode(value);
    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        temp->next = createNode(value);
        temp = temp->next;
    }

    printf("Original List: ");
    printList(head);

    head = reverseList(head);

    printf("\nReversed List: ");
    printList(head);

    return 0;
}