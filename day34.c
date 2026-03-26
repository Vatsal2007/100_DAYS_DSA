#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {
    struct Node* stack = NULL;
    char exp[100];
    int i = 0;

    fgets(exp, sizeof(exp), stdin);

    while (exp[i]) {
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, num);
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int b = pop(&stack);
            int a = pop(&stack);
            int res;

            if (exp[i] == '+') res = a + b;
            else if (exp[i] == '-') res = a - b;
            else if (exp[i] == '*') res = a * b;
            else res = a / b;

            push(&stack, res);
        }
        i++;
    }

    printf("%d", pop(&stack));

    return 0;
}