#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode_t {
    int data;
    struct BSTNode_t *left, *right;
} BSTNode;

typedef struct BST_t {
    BSTNode* root;
} BST;

// Fungsi untuk menginisialisasi pohon BST
void bst_init(BST* bst) {
    bst->root = NULL;
}

// Fungsi untuk membuat node baru
BSTNode* _newNode(int data) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi untuk menyisipkan node dalam pohon BST
BSTNode* _insert(BSTNode* node, int data) {
    // Jika pohon kosong, buat node baru
    if (node == NULL)
        return _newNode(data);

    // Jika data lebih kecil dari node, masukkan ke kiri
    if (data < node->data)
        node->left = _insert(node->left, data);
    // Jika data lebih besar dari node, masukkan ke kanan
    else if (data > node->data)
        node->right = _insert(node->right, data);

    // Kembalikan node yang tidak berubah
    return node;
}

// Fungsi untuk menambah data ke dalam pohon BST
void bst_insert(BST* bst, int data) {
    bst->root = _insert(bst->root, data);
}

// Fungsi untuk mencetak inorder traversal dari BST
void _inorder(BSTNode* root) {
    if (root != NULL) {
        _inorder(root->left);
        printf("%d ", root->data);
        _inorder(root->right);
    }
}

// Fungsi untuk mencetak inorder traversal pohon BST
void bst_inorder(BST* bst) {
    _inorder(bst->root);
    printf("\n");
}

// Fungsi untuk mencari nilai minimum di pohon BST
BSTNode* _minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi untuk menghapus node dari pohon BST
BSTNode* _deleteNode(BSTNode* root, int key) {
    // 1. Jika pohon kosong
    if (root == NULL)
        return root;

    // 2. Jika key lebih kecil dari root, maka hapus dari subtree kiri
    if (key < root->data)
        root->left = _deleteNode(root->left, key);
    // 3. Jika key lebih besar dari root, maka hapus dari subtree kanan
    else if (key > root->data)
        root->right = _deleteNode(root->right, key);
    else {
        // 4. Jika key ditemukan (root adalah node yang akan dihapus)
        // Kasus 1: node dengan satu anak atau tidak ada anak
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }

        // Kasus 2: node dengan dua anak, temukan nilai minimum node dari subtree kanan
        BSTNode* temp = _minValueNode(root->right);

        // Ganti data root dengan data node pengganti
        root->data = temp->data;

        // Hapus node pengganti
        root->right = _deleteNode(root->right, temp->data);
    }

    return root;
}

// Fungsi untuk menghapus data dari pohon BST
void bst_delete(BST* bst, int data) {
    bst->root = _deleteNode(bst->root, data);
}

// Fungsi untuk mencari elemen dalam pohon BST
BSTNode* _search(BSTNode* root, int key) {
    // Pohon kosong atau key ditemukan
    if (root == NULL || root->data == key)
        return root;

    // Jika key lebih kecil dari root, cari di subtree kiri
    if (key < root->data)
        return _search(root->left, key);

    // Jika key lebih besar dari root, cari di subtree kanan
    return _search(root->right, key);
}

// Fungsi untuk mencari elemen dalam pohon BST
BSTNode* bst_search(BST* bst, int key) {
    return _search(bst->root, key);
}

// Fungsi utama untuk menjalankan program
int main() {
    BST bst;
    bst_init(&bst);

    // Menambah elemen ke dalam BST
    bst_insert(&bst, 50);
    bst_insert(&bst, 30);
    bst_insert(&bst, 20);
    bst_insert(&bst, 40);
    bst_insert(&bst, 70);
    bst_insert(&bst, 60);
    bst_insert(&bst, 80);

    // Mencetak inorder traversal
    printf("Inorder traversal of the BST: ");
    bst_inorder(&bst);

    // Menghapus elemen dari BST
    bst_delete(&bst, 20);
    printf("Inorder traversal after deleting 20: ");
    bst_inorder(&bst);

    bst_delete(&bst, 30);
    printf("Inorder traversal after deleting 30: ");
    bst_inorder(&bst);

    bst_delete(&bst, 50);
    printf("Inorder traversal after deleting 50: ");
    bst_inorder(&bst);

    // Mencari elemen dalam BST
    int search_key = 40;
    BSTNode* result = bst_search(&bst, search_key);
    if (result != NULL)
        printf("Node with key %d found in the BST.\n", search_key);
    else
        printf("Node with key %d not found in the BST.\n", search_key);

    return 0;
}
