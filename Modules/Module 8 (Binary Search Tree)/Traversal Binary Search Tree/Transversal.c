#include <stdio.h>
#include <stdlib.h>

// Struktur node BST
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Buat node baru
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi insert rekursif
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

/* 
 * Inorder Traversal: LEFT -> NODE -> RIGHT
 * Hasilnya adalah nilai-nilai dalam urutan naik (ascending order) pada BST.
 */
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

/*
 * Preorder Traversal: NODE -> LEFT -> RIGHT
 * Digunakan untuk menyalin/mencetak struktur pohon.
 */
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

/*
 * Postorder Traversal: LEFT -> RIGHT -> NODE
 * Digunakan untuk menghapus pohon (karena anak dihapus duluan).
 */
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

/*
 * Level Order Traversal (BFS): cetak per level dari atas ke bawah, kiri ke kanan.
 * Digunakan untuk melihat struktur pohon secara horizontal.
 * Diimplementasikan dengan queue (antrian).
 */

// Struktur queue sederhana untuk level order
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* newQueueNode = (QueueNode*) malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newQueueNode;
    } else {
        q->rear->next = newQueueNode;
        q->rear = newQueueNode;
    }
}

Node* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return treeNode;
}

int isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue q = {NULL, NULL};
    enqueue(&q, root);

    while (!isQueueEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->value);

        if (current->left != NULL)
            enqueue(&q, current->left);
        if (current->right != NULL)
            enqueue(&q, current->right);
    }
}

// Fungsi utama
int main() {
    Node* root = NULL;
    int values[] = {8, 3, 10, 1, 6, 4, 7, 14};
    int n = sizeof(values) / sizeof(values[0]);

    // Membuat BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder Traversal (L -> N -> R):\n");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal (N -> L -> R):\n");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal (L -> R -> N):\n");
    postorder(root);
    printf("\n");

    printf("Level Order Traversal (per level):\n");
    levelOrder(root);
    printf("\n");

    return 0;
}
