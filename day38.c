#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void push_front(int x) {
    if (isFull()) return;
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
}

void push_back(int x) {
    if (isFull()) return;
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

void pop_front() {
    if (isEmpty()) return;
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) return;
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

int size() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void display() {
    if (isEmpty()) return;
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);
    pop_front();
    push_front(1);
    display();
    return 0;
}