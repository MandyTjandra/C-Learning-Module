#include <stdio.h>
#include <stdlib.h>

// Struktur node
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Buat node baru
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert rekursif
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    
    return root;
}

// Cari node terkecil di subtree
Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Fungsi remove / delete dari BST
Node* removeNode(Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        // Node ditemukan
        // Kasus 1 & 2: tidak ada anak atau satu anak
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Kasus 3: dua anak
        Node* temp = findMin(root->right); // in-order successor
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value); // hapus successor
    }
    return root;
}

// Inorder traversal
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

    // Menghapus node
    root = removeNode(root, 6);  // kasus dua anak
    root = removeNode(root, 1);  // kasus daun
    root = removeNode(root, 10); // kasus satu anak

    printf("BST setelah penghapusan:\n");
    inorder(root);
    printf("\n");

    return 0;
}
