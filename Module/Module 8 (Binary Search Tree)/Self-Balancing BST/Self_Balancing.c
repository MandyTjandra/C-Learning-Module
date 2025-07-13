#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk AVL Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Fungsi untuk mendapatkan tinggi pohon
int height(struct Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Fungsi untuk mendapatkan faktor keseimbangan
int getBalance(struct Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Fungsi untuk membuat node baru
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // node baru memiliki tinggi 1
    return node;
}

// Fungsi untuk rotasi kanan
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Melakukan rotasi
    x->right = y;
    y->left = T2;

    // Memperbarui tinggi node
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    // Mengembalikan root baru
    return x;
}

// Fungsi untuk rotasi kiri
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Melakukan rotasi
    y->left = x;
    x->right = T2;

    // Memperbarui tinggi node
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    // Mengembalikan root baru
    return y;
}

// Fungsi untuk menambah node pada AVL Tree
struct Node* insert(struct Node* node, int data) {
    // 1. Melakukan insert standar BST
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Tidak ada duplikat dalam AVL Tree

    // 2. Memperbarui tinggi node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // 3. Mendapatkan faktor keseimbangan dan melakukan rotasi jika perlu
    int balance = getBalance(node);

    // Jika node tidak seimbang, ada 4 kemungkinan kasus:

    // Kasus 1: Rotasi Kanan Kiri (Left-Left Case)
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Kasus 2: Rotasi Kanan Kanan (Right-Right Case)
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Kasus 3: Rotasi Kiri Kanan (Left-Right Case)
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Kasus 4: Rotasi Kanan Kiri (Right-Left Case)
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Mengembalikan node yang tidak berubah
    return node;
}

// Fungsi untuk mencetak inorder traversal dari AVL Tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Fungsi utama untuk menjalankan program
int main() {
    struct Node* root = NULL;

    // Menambah elemen ke dalam AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 25);

    // Mencetak inorder traversal
    printf("Inorder traversal of the AVL tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
