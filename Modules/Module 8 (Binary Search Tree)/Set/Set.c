#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode {
    int data;
    struct AVLNode *left, *right;
    int height;
} AVLNode;

typedef struct AVL {
    AVLNode *_root;
    unsigned int _size;
} AVL;

// Fungsi utilitas
int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(AVLNode *node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalanceFactor(AVLNode *node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

AVLNode *createNode(int value) {
    AVLNode *newNode = (AVLNode *) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Rotasi
AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Pencarian
AVLNode *search(AVLNode *root, int value) {
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

bool avl_find(AVL *avl, int value) {
    return search(avl->_root, value) != NULL;
}

// Penyisipan
AVLNode *insertNode(AVLNode *node, int value) {
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insertNode(node->left, value);
    else if (value > node->data)
        node->right = insertNode(node->right, value);
    else
        return node; // duplikasi tidak diperbolehkan

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && value < node->left->data)
        return rightRotate(node);
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void avl_insert(AVL *avl, int value) {
    if (!avl_find(avl, value)) {
        avl->_root = insertNode(avl->_root, value);
        avl->_size++;
    }
}

// Minimum node (untuk penghapusan)
AVLNode *findMinNode(AVLNode *node) {
    AVLNode *curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

// Penghapusan
AVLNode *removeNode(AVLNode *node, int value) {
    if (node == NULL)
        return node;

    if (value < node->data)
        node->left = removeNode(node->left, value);
    else if (value > node->data)
        node->right = removeNode(node->right, value);
    else {
        if (node->left == NULL || node->right == NULL) {
            AVLNode *temp = node->left ? node->left : node->right;
            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else
                *node = *temp;

            free(temp);
        } else {
            AVLNode *temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && getBalanceFactor(node->left) >= 0)
        return rightRotate(node);
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalanceFactor(node->right) <= 0)
        return leftRotate(node);
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void avl_remove(AVL *avl, int value) {
    if (avl_find(avl, value)) {
        avl->_root = removeNode(avl->_root, value);
        avl->_size--;
    }
}

// Traversal inorder (urut menaik)
void inorderTraversal(AVLNode *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Inisialisasi
void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0;
}

// Program utama
int main() {
    AVL mySet;
    avl_init(&mySet);

    printf("Cek apakah kosong: %s\n", mySet._root == NULL ? "Ya" : "Tidak");

    printf("Menambahkan elemen: 4 3 2 1\n");
    avl_insert(&mySet, 4);
    avl_insert(&mySet, 3);
    avl_insert(&mySet, 2);
    avl_insert(&mySet, 1);

    printf("Isi set (inorder): ");
    inorderTraversal(mySet._root);
    printf("\n");

    printf("Cari 5: %s\n", avl_find(&mySet, 5) ? "Ditemukan" : "Tidak ditemukan");
    printf("Cari 3: %s\n", avl_find(&mySet, 3) ? "Ditemukan" : "Tidak ditemukan");

    printf("Hapus 2...\n");
    avl_remove(&mySet, 2);
    printf("Isi set sekarang: ");
    inorderTraversal(mySet._root);
    printf("\n");

    return 0;
}
