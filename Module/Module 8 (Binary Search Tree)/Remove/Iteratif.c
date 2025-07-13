#include <stdio.h>
#include <stdlib.h>

// Struktur node
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Membuat node baru
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Menyisipkan node ke BST secara rekursif
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

// Fungsi untuk mencari node minimum di subtree
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Fungsi untuk menghapus node dari BST secara iteratif
Node* deleteIterative(Node* root, int key) {
    Node* parent = NULL;
    Node* current = root;

    // Temukan node yang akan dihapus dan parent-nya
    while (current != NULL && current->value != key) {
        parent = current;
        if (key < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
        return root; // Node tidak ditemukan

    // Kasus 1 & 2: node dengan 0 atau 1 anak
    if (current->left == NULL || current->right == NULL) {
        Node* child = (current->left) ? current->left : current->right;

        if (parent == NULL) {
            free(current);
            return child; // Root dihapus
        }

        if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;

        free(current);
    }
    // Kasus 3: dua anak
    else {
        Node* successorParent = current;
        Node* successor = current->right;

        // Cari node terkecil di subtree kanan
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        current->value = successor->value; // Salin nilai successor ke current

        // Hapus successor
        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;

        free(successor);
    }

    return root;
}

// Traversal inorder
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
    int values[] = {8, 3, 10, 1, 6, 4, 7, 14};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("BST sebelum penghapusan:\n");
    inorder(root);
    printf("\n");

    root = deleteIterative(root, 6);  // Node dengan dua anak
    root = deleteIterative(root, 1);  // Node daun
    root = deleteIterative(root, 10); // Node dengan satu anak

    printf("BST setelah penghapusan:\n");
    inorder(root);
    printf("\n");

    return 0;
}
