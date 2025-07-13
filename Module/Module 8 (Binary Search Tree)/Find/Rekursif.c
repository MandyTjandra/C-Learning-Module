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
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Fungsi rekursif untuk mencari nilai dalam BST
int find(Node* root, int target) {
    if (root == NULL)
        return 0; // Tidak ditemukan

    if (target == root->value)
        return 1; // Ditemukan
    else if (target < root->value)
        return find(root->left, target);
    else
        return find(root->right, target);
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

    int key = 0;
    if (find(root, key))
        printf("Angka %d ditemukan dalam BST.\n", key);
    else
        printf("Angka %d tidak ditemukan dalam BST.\n", key);

    return 0;
}
