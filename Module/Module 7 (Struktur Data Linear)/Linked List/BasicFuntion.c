#include <stdio.h>
#include <stdlib.h>

// Definisi node untuk singly linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Fungsi untuk memeriksa apakah list kosong
int isEmpty(Node *head) {
    return head == NULL;
}

// Fungsi untuk menambah elemen di belakang (push back)
void pushBack(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(*head)) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menambah elemen di depan (push front)
void pushFront(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Fungsi untuk menyisipkan elemen pada posisi tertentu (insert at)
void insertAt(Node **head, int index, int value) {
    if (index < 0) return;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    for (int i = 0; i < index - 1; i++) {
        if (temp == NULL) return;  // Indeks lebih besar dari jumlah elemen
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk mendapatkan elemen di depan (front)
int front(Node *head) {
    if (isEmpty(head)) {
        return -1;  // Mengembalikan -1 jika list kosong
    }
    return head->data;
}

// Fungsi untuk mendapatkan elemen di belakang (back)
int back(Node *head) {
    if (isEmpty(head)) {
        return -1;  // Mengembalikan -1 jika list kosong
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp->data;
}

// Fungsi untuk mendapatkan elemen pada indeks tertentu (getAt)
int getAt(Node *head, int index) {
    if (index < 0) return -1;

    Node *temp = head;
    for (int i = 0; i < index; i++) {
        if (temp == NULL) return -1;  // Indeks lebih besar dari jumlah elemen
        temp = temp->next;
    }
    return temp ? temp->data : -1;
}

// Fungsi untuk menghapus elemen di belakang (pop back)
void popBack(Node **head) {
    if (isEmpty(*head)) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while (temp->next && temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Fungsi untuk menghapus elemen di depan (pop front)
void popFront(Node **head) {
    if (isEmpty(*head)) return;

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Fungsi untuk menghapus elemen berdasarkan nilai (remove)
void removeNode(Node **head, int value) {
    if (isEmpty(*head)) return;

    Node *temp = *head;

    // Jika head node yang harus dihapus
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Mencari node yang akan dihapus
    Node *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Jika elemen tidak ditemukan
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Fungsi untuk mencetak seluruh elemen dalam linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi untuk membebaskan memori
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    // Menambahkan elemen
    pushBack(&head, 10);
    pushBack(&head, 20);
    pushFront(&head, 5);
    insertAt(&head, 1, 15);  // Sisipkan 15 di index 1

    printf("List setelah pushBack, pushFront, dan insertAt:\n");
    printList(head);

    printf("Front: %d\n", front(head));
    printf("Back: %d\n", back(head));
    printf("Element at index 2: %d\n", getAt(head, 2));

    popBack(&head);
    printf("List setelah popBack:\n");
    printList(head);

    popFront(&head);
    printf("List setelah popFront:\n");
    printList(head);

    removeNode(&head, 15);  // Menghapus elemen dengan nilai 15
    printf("List setelah removeNode:\n");
    printList(head);

    freeList(head);

    return 0;
}
