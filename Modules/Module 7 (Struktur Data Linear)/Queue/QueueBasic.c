#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

// Cek apakah queue kosong
int queue_isEmpty() {
    return (front == -1 || front > rear);
}

// Ambil nilai front queue
int queue_front() {
    if (!queue_isEmpty()) {
        return queue[front];
    }
    return -1;
}

// Push (enqueue)
void push(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
    printf("%d pushed to queue\n", value);
}

// Pop (dequeue)
void pop() {
    if (queue_isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d popped from queue\n", queue[front]);
    front++;
}

// Peek (get front element)
void peek() {
    if (queue_isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", queue[front]);
}

// Display all elements
void display() {
    if (queue_isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();

    // Tambahan penggunaan queue_front
    if (!queue_isEmpty()) {
        printf("Front element using queue_front(): %d\n", queue_front());
    } else {
        printf("Queue is empty\n");
    }

    return 0;
}
