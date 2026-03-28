#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Check mirror
int isMirror(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL)
        return 1;

    if (left == NULL || right == NULL)
        return 0;

    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Check symmetric
int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}