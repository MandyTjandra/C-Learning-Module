#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// =====================
// Struktur AVL Tree
// =====================
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left, *right;
} AVLNode;

typedef struct AVL {
    AVLNode *root;
    int _size;
} AVL;

// =====================
// Fungsi Utilitas
// =====================
int _max(int a, int b) {
    return (a > b) ? a : b;
}

int _getHeight(AVLNode *node) {
    return node ? node->height : 0;
}

int _getBalanceFactor(AVLNode *node) {
    return node ? _getHeight(node->left) - _getHeight(node->right) : 0;
}

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// =====================
// Fungsi Rotasi
// =====================
AVLNode* _leftCaseRotate(AVLNode *node) {
    AVLNode *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));
    newRoot->height = 1 + _max(_getHeight(newRoot->left), _getHeight(newRoot->right));

    return newRoot;
}

AVLNode* _rightCaseRotate(AVLNode *node) {
    AVLNode *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));
    newRoot->height = 1 + _max(_getHeight(newRoot->left), _getHeight(newRoot->right));

    return newRoot;
}

AVLNode* _leftRightCaseRotate(AVLNode *node) {
    node->left = _rightCaseRotate(node->left);
    return _leftCaseRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode *node) {
    node->right = _leftCaseRotate(node->right);
    return _rightCaseRotate(node);
}

// =====================
// Fungsi AVL Insert
// =====================
AVLNode* _insert_AVL(AVL *avl, AVLNode *node, int value) {
    if (!node)
        return _avl_createNode(value);
    
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    int balance = _getBalanceFactor(node);

    if (balance > 1 && value < node->left->data)
        return _leftCaseRotate(node);
    if (balance > 1 && value > node->left->data)
        return _leftRightCaseRotate(node);
    if (balance < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if (balance < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);

    return node;
}

void avl_insert(AVL *avl, int value) {
    avl->root = _insert_AVL(avl, avl->root, value);
    avl->_size++;
}

// =====================
// Fungsi AVL Remove
// =====================
AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *curr = node;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

AVLNode* _remove_AVL(AVLNode *node, int value) {
    if (!node)
        return node;

    if (value < node->data)
        node->left = _remove_AVL(node->left, value);
    else if (value > node->data)
        node->right = _remove_AVL(node->right, value);
    else {
        AVLNode *temp;
        if (!node->left || !node->right) {
            temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }
            free(temp);
        } else {
            temp = _findMinNode(node->right);
            node->data = temp->data;
            node->right = _remove_AVL(node->right, temp->data);
        }
    }

    if (!node)
        return node;

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));
    int balance = _getBalanceFactor(node);

    if (balance > 1 && _getBalanceFactor(node->left) >= 0)
        return _leftCaseRotate(node);
    if (balance > 1 && _getBalanceFactor(node->left) < 0)
        return _leftRightCaseRotate(node);
    if (balance < -1 && _getBalanceFactor(node->right) <= 0)
        return _rightCaseRotate(node);
    if (balance < -1 && _getBalanceFactor(node->right) > 0)
        return _rightLeftCaseRotate(node);

    return node;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = avl->root;
    while (temp) {
        if (value < temp->data)
            temp = temp->left;
        else if (value > temp->data)
            temp = temp->right;
        else
            return true;
    }
    return false;
}

void avl_remove(AVL *avl, int value) {
    if (avl_find(avl, value)) {
        avl->root = _remove_AVL(avl->root, value);
        avl->_size--;
    }
}

// =====================
// Fungsi Tambahan
// =====================
void inorder(AVLNode *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// =====================
// Fungsi Main
// =====================
int main() {
    AVL tree;
    tree.root = NULL;
    tree._size = 0;

    // Insert beberapa nilai
    avl_insert(&tree, 40);
    avl_insert(&tree, 20);
    avl_insert(&tree, 10);
    avl_insert(&tree, 25);
    avl_insert(&tree, 50);
    avl_insert(&tree, 60);
    avl_insert(&tree, 30);

    printf("Inorder sebelum penghapusan:\n");
    inorder(tree.root);
    printf("\n");

    // Hapus node yang menyebabkan rotasi (misalnya 20 dan 40)
    printf("Menghapus 20...\n");
    avl_remove(&tree, 20);

    printf("Inorder setelah hapus 20:\n");
    inorder(tree.root);
    printf("\n");

    printf("Menghapus 40...\n");
    avl_remove(&tree, 40);

    printf("Inorder setelah hapus 40:\n");
    inorder(tree.root);
    printf("\n");

    return 0;
}
