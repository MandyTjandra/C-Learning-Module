#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur node AVL Tree
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left, *right;
} AVLNode;

// Struktur AVL Tree
typedef struct AVL {
    AVLNode *root;
    int _size;
} AVL;

// ============================
// Fungsi Utilitas
// ============================

// Fungsi maksimum dua integer
int _max(int a, int b) {
    return (a > b) ? a : b;
}

// Mengembalikan tinggi node
int _getHeight(AVLNode *node) {
    return node ? node->height : 0;
}

// Menghitung balance factor dari sebuah node
int _getBalanceFactor(AVLNode *node) {
    return node ? _getHeight(node->left) - _getHeight(node->right) : 0;
}

// Membuat node baru dengan nilai tertentu
AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ============================
// Fungsi Rotasi
// ============================

// Rotasi single right (LL Case)
AVLNode* _leftCaseRotate(AVLNode *node) {
    AVLNode *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));
    newRoot->height = 1 + _max(_getHeight(newRoot->left), _getHeight(newRoot->right));

    return newRoot;
}

// Rotasi single left (RR Case)
AVLNode* _rightCaseRotate(AVLNode *node) {
    AVLNode *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));
    newRoot->height = 1 + _max(_getHeight(newRoot->left), _getHeight(newRoot->right));

    return newRoot;
}

// Rotasi double kiri-kanan (LR Case)
AVLNode* _leftRightCaseRotate(AVLNode *node) {
    node->left = _rightCaseRotate(node->left);
    return _leftCaseRotate(node);
}

// Rotasi double kanan-kiri (RL Case)
AVLNode* _rightLeftCaseRotate(AVLNode *node) {
    node->right = _leftCaseRotate(node->right);
    return _rightCaseRotate(node);
}

// ============================
// Fungsi Inti AVL
// ============================

// Fungsi rekursif pencarian node
AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

// Fungsi rekursif untuk menyisipkan nilai
AVLNode* _insert_AVL(AVL *avl, AVLNode *node, int value) {
    // Kasus dasar: insert pertama
    if (node == NULL)
        return _avl_createNode(value);

    // Rekursi ke kiri atau kanan sesuai nilai
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    // Update tinggi node
    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    // Hitung balance factor
    int balanceFactor = _getBalanceFactor(node);

    // Lakukan rotasi sesuai kasus ketidakseimbangan
    if (balanceFactor > 1 && value < node->left->data)
        return _leftCaseRotate(node);          // LL Case
    if (balanceFactor > 1 && value > node->left->data)
        return _leftRightCaseRotate(node);     // LR Case
    if (balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);         // RR Case
    if (balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);     // RL Case

    return node; // Tidak perlu rotasi
}

// Fungsi publik untuk mencari nilai dalam AVL Tree
bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->root, value);
    return temp != NULL && temp->data == value;
}

// Fungsi publik untuk menyisipkan nilai
void avl_insert(AVL *avl, int value) {
    if (!avl_find(avl, value)) {
        avl->root = _insert_AVL(avl, avl->root, value);
        avl->_size++;
    }
}

// ============================
// Fungsi Tambahan: Traversal
// ============================

// Inorder traversal untuk cetak tree
void inorder(AVLNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// ============================
// Fungsi Main (Uji Program)
// ============================

int main() {
    AVL tree;
    tree.root = NULL;
    tree._size = 0;

    // Contoh penyisipan
    avl_insert(&tree, 30);
    avl_insert(&tree, 20);
    avl_insert(&tree, 40);
    avl_insert(&tree, 10);
    avl_insert(&tree, 25);
    avl_insert(&tree, 35);
    avl_insert(&tree, 50);
    avl_insert(&tree, 5);   // Harus menyeimbangkan tree

    // Cetak hasil inorder traversal
    printf("Inorder traversal AVL Tree:\n");
    inorder(tree.root);
    printf("\n");

    // Cek apakah nilai ada dalam tree
    int key = 25;
    if (avl_find(&tree, key))
        printf("Key %d ditemukan dalam AVL Tree.\n", key);
    else
        printf("Key %d tidak ditemukan.\n", key);

    return 0;
}
