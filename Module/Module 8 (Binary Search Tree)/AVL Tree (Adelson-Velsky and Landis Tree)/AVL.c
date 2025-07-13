#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode_t {
    int data;
    struct AVLNode_t *left, *right;
    int height;
} AVLNode;

typedef struct AVL_t {
    AVLNode *_root;
    unsigned int _size;
} AVL;

// Fungsi untuk menginisialisasi pohon AVL
void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

// Fungsi untuk mendapatkan tinggi node
int _getHeight(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Fungsi untuk mendapatkan faktor keseimbangan dari node
int _getBalance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

// Fungsi untuk membuat node baru
AVLNode* _newNode(int data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // node baru memiliki tinggi 1
    return node;
}

// Fungsi untuk rotasi kanan
AVLNode* _rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Melakukan rotasi
    x->right = y;
    y->left = T2;

    // Memperbarui tinggi node
    y->height = 1 + (_getHeight(y->left) > _getHeight(y->right) ? _getHeight(y->left) : _getHeight(y->right));
    x->height = 1 + (_getHeight(x->left) > _getHeight(x->right) ? _getHeight(x->left) : _getHeight(x->right));

    // Mengembalikan root baru
    return x;
}

// Fungsi untuk rotasi kiri
AVLNode* _leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Melakukan rotasi
    y->left = x;
    x->right = T2;

    // Memperbarui tinggi node
    x->height = 1 + (_getHeight(x->left) > _getHeight(x->right) ? _getHeight(x->left) : _getHeight(x->right));
    y->height = 1 + (_getHeight(y->left) > _getHeight(y->right) ? _getHeight(y->left) : _getHeight(y->right));

    // Mengembalikan root baru
    return y;
}

// Fungsi untuk menyisipkan node dalam pohon AVL
AVLNode* _insert(AVLNode* node, int data) {
    // 1. Melakukan insert standar BST
    if (node == NULL)
        return _newNode(data);

    if (data < node->data)
        node->left = _insert(node->left, data);
    else if (data > node->data)
        node->right = _insert(node->right, data);
    else
        return node; // Tidak ada duplikat dalam AVL Tree

    // 2. Memperbarui tinggi node
    node->height = 1 + (_getHeight(node->left) > _getHeight(node->right) ? _getHeight(node->left) : _getHeight(node->right));

    // 3. Mendapatkan faktor keseimbangan dan melakukan rotasi jika perlu
    int balance = _getBalance(node);

    // Jika node tidak seimbang, ada 4 kemungkinan kasus:

    // Kasus 1: Rotasi Kiri Kiri (Left-Left Case)
    if (balance > 1 && data < node->left->data)
        return _rightRotate(node);

    // Kasus 2: Rotasi Kanan Kanan (Right-Right Case)
    if (balance < -1 && data > node->right->data)
        return _leftRotate(node);

    // Kasus 3: Rotasi Kiri Kanan (Left-Right Case)
    if (balance > 1 && data > node->left->data) {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    // Kasus 4: Rotasi Kanan Kiri (Right-Left Case)
    if (balance < -1 && data < node->right->data) {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    // Mengembalikan node yang tidak berubah
    return node;
}

// Fungsi untuk menambah data ke dalam pohon AVL
void avl_insert(AVL* avl, int data) {
    avl->_root = _insert(avl->_root, data);
    avl->_size++;
}

// Fungsi untuk mencetak inorder traversal dari AVL Tree
void _inorder(AVLNode* root) {
    if (root != NULL) {
        _inorder(root->left);
        printf("%d ", root->data);
        _inorder(root->right);
    }
}

// Fungsi untuk mencetak inorder traversal pohon AVL
void avl_inorder(AVL* avl) {
    _inorder(avl->_root);
    printf("\n");
}

// Fungsi utama untuk menjalankan program
int main() {
    AVL avl;
    avl_init(&avl);

    // Menambah elemen ke dalam AVL Tree
    avl_insert(&avl, 10);
    avl_insert(&avl, 20);
    avl_insert(&avl, 30);
    avl_insert(&avl, 15);
    avl_insert(&avl, 25);

    // Mencetak inorder traversal
    printf("Inorder traversal of the AVL tree: ");
    avl_inorder(&avl);

    return 0;
}
