#include <stdio.h>
#define SIZE 100

//Using Array
int stack[SIZE];
int top = -1;

void push(int value) {
    if (top >= SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

void pop() {
    if (top < 0)
        printf("Stack Underflow\n");
    else
        top--;
}

int peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (top < 0)
        printf("Stack is empty\n");
    else {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();      // Output: 30 20 10
    pop();
    display();      // Output: 20 10
    printf("Top: %d\n", peek()); // Output: 20
    return 0;
}
