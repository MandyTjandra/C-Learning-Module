#include <stdio.h>
#include <stdlib.h>

// Struktur node
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi rekursif untuk insert ke BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Fungsi inorder traversal (untuk melihat hasil insert)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Fungsi utama
int main() {
    Node* root = NULL;

    // Menyisipkan nilai ke BST
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 4);
    insert(root, 7);
    insert(root, 14);

    printf("Inorder traversal (urutan terkecil ke terbesar):\n");
    inorder(root);
    printf("\n");

    return 0;
}
