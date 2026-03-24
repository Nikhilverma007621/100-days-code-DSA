#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order array
struct TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct TreeNode* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Find a node by value
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    struct TreeNode* left = findNode(root->left, val);
    if (left != NULL) return left;

    return findNode(root->right, val);
}

// LCA function
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q)
        return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p_val, q_val;
    scanf("%d %d", &p_val, &q_val);

    // Build tree
    struct TreeNode* root = buildTree(arr, n, 0);

    // Find nodes
    struct TreeNode* p = findNode(root, p_val);
    struct TreeNode* q = findNode(root, q_val);

    // Find LCA
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->val);
    else
        printf("LCA not found\n");

    return 0;
}