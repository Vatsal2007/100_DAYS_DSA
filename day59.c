#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* build(int* inorder, int is, int ie, int* postorder, int ps, int pe) {
    if (is > ie || ps > pe) return NULL;

    struct Node* root = newNode(postorder[pe]);

    int i = is;
    while (inorder[i] != root->data) i++;

    int leftSize = i - is;

    root->left = build(inorder, is, i - 1, postorder, ps, ps + leftSize - 1);
    root->right = build(inorder, i + 1, ie, postorder, ps + leftSize, pe - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int* inorder = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    struct Node* root = build(inorder, 0, n - 1, postorder, 0, n - 1);

    preorder(root);

    free(inorder);
    free(postorder);
    return 0;
}