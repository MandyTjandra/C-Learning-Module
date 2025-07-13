#include <stdio.h>
#define SIZE 100

int deque[SIZE];
int front = -1;
int rear = -1;

// Cek apakah deque kosong
int isEmpty() {
    return (front == -1);
}

// Tambah elemen di depan
void pushFront(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
    printf("%d pushed to front\n", value);
}

// Tambah elemen di belakang
void pushBack(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("%d pushed to back\n", value);
}

// Lihat elemen depan
int getFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[front];
}

// Lihat elemen belakang
int getRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[rear];
}

// Hapus elemen depan
void popFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("%d popped from front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Hapus elemen belakang
void popBack() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("%d popped from back\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

// Tampilkan semua isi deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    pushBack(10);
    pushBack(20);
    pushFront(5);
    pushFront(2);
    display();

    printf("Front element: %d\n", getFront());
    printf("Rear element: %d\n", getRear());

    popFront();
    display();

    popBack();
    display();

    return 0;
}
