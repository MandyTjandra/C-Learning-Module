#include <stdio.h>

#define MAX 100

//Using array

struct Stack {
    int data[MAX];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}

void sortStack(struct Stack* s) {
    int temp[MAX];
    int n = 0;

    // Pop all elements into temp array
    while (!isEmpty(s)) {
        temp[n++] = pop(s);
    }

    // Sort the array (simple bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    // Push sorted elements back into stack
    for (int i = 0; i < n; i++) {
        push(s, temp[i]);
    }
}

void printStack(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    init(&s);

    push(&s, 5);
    push(&s, 1);
    push(&s, 3);
    push(&s, 4);
    push(&s, 2);

    printf("Original stack (bottom to top): ");
    printStack(&s);

    sortStack(&s);

    printf("Sorted stack (bottom to top):   ");
    printStack(&s);

    return 0;
}
