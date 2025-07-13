#include <stdio.h>
#define SIZE 100

//Using Array

int queue[SIZE];
int front = 0, rear = -1;

void enqueue(int value) {
    if (rear >= SIZE - 1)
        printf("Queue Overflow\n");
    else
        queue[++rear] = value;
}

void dequeue() {
    if (front > rear)
        printf("Queue Underflow\n");
    else
        front++;
}

void display() {
    if (front > rear)
        printf("Queue is empty\n");
    else {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();        // Output: 10 20 30
    dequeue();
    display();        // Output: 20 30
    return 0;
}
