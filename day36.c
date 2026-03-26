#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0, size = 0;

void enqueue(int x) {
    if (size == MAX) return;
    queue[rear] = x;
    rear = (rear + 1) % MAX;
    size++;
}

void dequeue() {
    if (size == 0) return;
    front = (front + 1) % MAX;
    size--;
}

void display() {
    int i = front;
    int count = size;
    while (count--) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}