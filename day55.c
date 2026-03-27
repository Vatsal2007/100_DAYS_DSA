#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// create node
struct node* newNode(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// queue
struct node* queue[100];
int front = 0, rear = 0;

void enqueue(struct node* x) {
    queue[rear++] = x;
}

struct node* dequeue() {
    return queue[front++];
}

// build tree
struct node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct node* curr = dequeue();

        // left
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // right
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// right view
void rightView(struct node* root) {
    if (!root) return;

    enqueue(root);

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct node* temp = dequeue();

            // print last node of this level
            if (i == size - 1)
                printf("%d ", temp->data);

            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}

// MAIN
int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    front = rear = 0;
    struct node* root = buildTree(arr, n);

    front = rear = 0;
    rightView(root);

    return 0;
}