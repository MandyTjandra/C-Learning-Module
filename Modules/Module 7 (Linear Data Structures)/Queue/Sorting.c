#include <stdio.h>

#define MAX 100

//Using array

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

void init(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front++];
}

void sortQueue(struct Queue* q) {
    int n = q->rear - q->front + 1;
    int temp[MAX];

    // Copy queue elements to temp array
    for (int i = 0; i < n; i++) {
        temp[i] = q->data[q->front + i];
    }

    // Sort the array (using simple bubble sort for demonstration)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    // Rebuild the queue from sorted array
    q->front = 0;
    q->rear = -1;
    for (int i = 0; i < n; i++) {
        enqueue(q, temp[i]);
    }
}

void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 2);

    printf("Original queue: ");
    printQueue(&q);

    sortQueue(&q);

    printf("Sorted queue:   ");
    printQueue(&q);

    return 0;
}
