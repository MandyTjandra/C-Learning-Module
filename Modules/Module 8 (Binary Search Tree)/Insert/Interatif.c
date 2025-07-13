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

// Fungsi iteratif untuk insert ke BST tanpa duplikat
Node* insert(Node* root, int value) {
    Node* newNode = createNode(value);

    if (root == NULL) {
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else if (value > current->value) {
            current = current->right;
        } else {
            // Nilai sudah ada, tidak boleh duplikat
            free(newNode);  // Jangan lupa bebaskan memori
            return root;
        }
    }

    if (value < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

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

    int values[] = {8, 3, 10, 1, 6, 4, 7, 14, 6}; // Catatan: 6 muncul dua kali
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal (tanpa duplikat):\n");
    inorder(root);
    printf("\n");

    return 0;
}
