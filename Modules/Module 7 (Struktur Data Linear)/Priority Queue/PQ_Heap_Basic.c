/* Priority Queue berbasis linked list menyimpan elemen secara terurut 
   berdasarkan prioritas, dengan operasi push yang lebih lambat (O(n)) 
   namun pop dan top yang cepat (O(1)). Sedangkan Priority Queue berbasis 
   heap menggunakan struktur pohon biner untuk menjaga urutan prioritas, 
   membuat operasi push dan pop lebih efisien (O(log n)), terutama saat 
   menangani banyak data. */

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

// Menukar dua elemen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Menambahkan elemen baru (push)
void push(PriorityQueue *pq, int value) {
    if (pq->size == SIZE) {
        printf("Priority Queue is full\n");
        return;
    }
    pq->data[pq->size] = value;
    int current = pq->size;
    pq->size++;

    // Perbaiki posisi dengan heapify up
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (pq->data[parent] > pq->data[current]) {
            swap(&pq->data[parent], &pq->data[current]);
            current = parent;
        } else {
            break;
        }
    }
    printf("%d pushed to priority queue\n", value);
}

// Menghapus elemen top (pop)
void pop(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("%d popped from priority queue\n", pq->data[0]);
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    // Perbaiki posisi dengan heapify down
    int current = 0;
    while (1) {
        int left = current * 2 + 1;
        int right = current * 2 + 2;
        int smallest = current;

        if (left < pq->size && pq->data[left] < pq->data[smallest])
            smallest = left;
        if (right < pq->size && pq->data[right] < pq->data[smallest])
            smallest = right;
        
        if (smallest != current) {
            swap(&pq->data[current], &pq->data[smallest]);
            current = smallest;
        } else {
            break;
        }
    }
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
