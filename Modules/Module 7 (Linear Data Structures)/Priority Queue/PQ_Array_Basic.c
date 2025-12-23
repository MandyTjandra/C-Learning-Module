/* Priority Queue adalah struktur data antrian yang menyusun elemen 
   berdasarkan prioritas, bukan urutan masuk. Elemen dengan prioritas 
   tertinggi akan keluar lebih dulu, sehingga cocok digunakan untuk 
   masalah yang melibatkan pemrosesan berdasarkan tingkat kepentingan. */

#include <stdio.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int size;
} PriorityQueue;

// Inisialisasi pqueue
void init(PriorityQueue *pq) {
    pq->size = 0;
}

// Cek apakah pqueue kosong
int isEmpty(PriorityQueue *pq) {
    return (pq->size == 0);
}

// Menambahkan data baru (push)
void push(PriorityQueue *pq, int value) {
    if (pq->size == SIZE) {
        printf("Priority Queue is full\n");
        return;
    }
    int i = pq->size - 1;
    // geser elemen supaya tetap urut (dari besar ke kecil)
    while (i >= 0 && pq->data[i] < value) {
        pq->data[i + 1] = pq->data[i];
        i--;
    }
    pq->data[i + 1] = value;
    pq->size++;
    printf("%d pushed to priority queue\n", value);
}

// Menghapus elemen top (pop)
void pop(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("%d popped from priority queue\n", pq->data[0]);
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    pq->size--;
}

// Melihat data top (top)
int top(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    return pq->data[0];
}

// Menampilkan isi pqueue
void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue elements: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->data[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    init(&pq);

    push(&pq, 30);
    push(&pq, 50);
    push(&pq, 10);
    push(&pq, 40);

    display(&pq);

    printf("Top element: %d\n", top(&pq));

    pop(&pq);
    display(&pq);

    printf("Top element: %d\n", top(&pq));

    return 0;
}
