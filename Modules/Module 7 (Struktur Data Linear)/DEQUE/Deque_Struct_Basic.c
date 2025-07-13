#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front;
    int rear;
} Deque;

// Membuat deque baru
void initDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Cek apakah deque kosong
int isEmpty(Deque *deque) {
    return (deque->front == -1);
}

// Push depan
void pushFront(Deque *deque, int value) {
    if ((deque->front == 0 && deque->rear == SIZE - 1) || (deque->front == deque->rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = SIZE - 1;
    } else {
        deque->front--;
    }
    deque->data[deque->front] = value;
    printf("%d pushed to front\n", value);
}

// Push belakang
void pushBack(Deque *deque, int value) {
    if ((deque->front == 0 && deque->rear == SIZE - 1) || (deque->front == deque->rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (deque->rear == SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->data[deque->rear] = value;
    printf("%d pushed to back\n", value);
}

// Lihat front
int getFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->data[deque->front];
}

// Lihat rear
int getRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->data[deque->rear];
}

// Pop depan
void popFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    printf("%d popped from front\n", deque->data[deque->front]);
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else if (deque->front == SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
}

// Pop belakang
void popBack(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    printf("%d popped from back\n", deque->data[deque->rear]);
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = SIZE - 1;
    } else {
        deque->rear--;
    }
}

// Display semua elemen
void display(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = deque->front;
    while (1) {
        printf("%d ", deque->data[i]);
        if (i == deque->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initDeque(&deque);

    pushBack(&deque, 10);
    pushFront(&deque, 5);
    pushBack(&deque, 20);
    pushFront(&deque, 2);
    display(&deque);

    printf("Front element: %d\n", getFront(&deque));
    printf("Rear element: %d\n", getRear(&deque));

    popFront(&deque);
    display(&deque);

    popBack(&deque);
    display(&deque);

    return 0;
}
