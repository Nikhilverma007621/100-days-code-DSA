#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Search in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct TreeNode* build(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    struct TreeNode* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->val);

    root->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Queue for level order traversal
struct Queue {
    struct TreeNode* arr[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Print level order (LeetCode style)
void printLevelOrder(struct TreeNode* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct TreeNode* curr = dequeue(&q);

        if (curr) {
            printf("%d ", curr->val);
            enqueue(&q, curr->left);
            enqueue(&q, curr->right);
        } else {
            printf("null ");
        }
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    // Input preorder
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    // Input inorder
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct TreeNode* root = build(preorder, inorder, 0, n - 1, &preIndex);

    // Output (level order like LeetCode)
    printLevelOrder(root);

    return 0;
}