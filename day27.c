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

struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

int length(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* l1, struct Node* l2) {
    int len1 = length(l1);
    int len2 = length(l2);

    int diff = len1 - len2;

    if (diff > 0) {
        while (diff--) l1 = l1->next;
    } else {
        diff = -diff;
        while (diff--) l2 = l2->next;
    }

    while (l1 && l2) {
        if (l1->data == l2->data) return l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = append(l1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l2 = append(l2, x);
    }

    struct Node* res = findIntersection(l1, l2);

    if (res) printf("%d", res->data);
    else printf("No Intersection");

    return 0;
}