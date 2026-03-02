#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int stack1[100], stack2[100];
    int top1 = -1, top2 = -1;

    while (l1 != NULL) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* result = NULL;

    while (top1 >= 0 || top2 >= 0 || carry) {
        int sum = carry;

        if (top1 >= 0)
            sum += stack1[top1--];

        if (top2 >= 0)
            sum += stack2[top2--];

        carry = sum / 10;

        struct ListNode* newNode = createNode(sum % 10);
        newNode->next = result;  // Insert at front
        result = newNode;
    }

    return result;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {

    struct ListNode* l1 = createNode(7);
    l1->next = createNode(2);
    l1->next->next = createNode(4);
    l1->next->next->next = createNode(3);

    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    return 0;
}