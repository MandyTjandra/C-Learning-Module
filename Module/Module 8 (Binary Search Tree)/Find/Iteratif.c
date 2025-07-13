#include <stdio.h>
#include <stdlib.h>

// Struktur node BST
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menyisipkan node ke BST
Node* insert(Node* root, int value) {
    Node* newNode = createNode(value);

    if (root == NULL) {
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (value < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Fungsi iteratif untuk mencari nilai dalam BST
int find(Node* root, int target) {
    Node* current = root;

    while (current != NULL) {
        if (target == current->value)
            return 1;  // Ditemukan
        else if (target < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return 0;  // Tidak ditemukan
}

// Fungsi untuk uji coba
int main() {
    Node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 4);
    insert(root, 7);
    insert(root, 14);

    int key = 6;
    if (find(root, key))
        printf("Angka %d ditemukan dalam BST.\n", key);
    else
        printf("Angka %d tidak ditemukan dalam BST.\n", key);

    return 0;
}
