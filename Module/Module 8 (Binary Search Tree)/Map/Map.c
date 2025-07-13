#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MapNode {
    int key;
    int value;
    int height;
    struct MapNode *left, *right;
} MapNode;

typedef struct Map {
    MapNode *_root;
    unsigned int _size;
} Map;

// Utility
int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(MapNode *node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalance(MapNode *node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

MapNode *createNode(int key, int value) {
    MapNode *newNode = (MapNode *)malloc(sizeof(MapNode));
    newNode->key = key;
    newNode->value = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Rotations
MapNode *rightRotate(MapNode *y) {
    MapNode *x = y->left;
    MapNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

MapNode *leftRotate(MapNode *x) {
    MapNode *y = x->right;
    MapNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Find
MapNode *findNode(MapNode *node, int key) {
    while (node != NULL) {
        if (key < node->key)
            node = node->left;
        else if (key > node->key)
            node = node->right;
        else
            return node;
    }
    return NULL;
}

// Insert or update
MapNode *insertNode(MapNode *node, int key, int value) {
    if (node == NULL)
        return createNode(key, value);

    if (key < node->key)
        node->left = insertNode(node->left, key, value);
    else if (key > node->key)
        node->right = insertNode(node->right, key, value);
    else {
        node->value = value; // update
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Minimum node
MapNode *findMinNode(MapNode *node) {
    MapNode *curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

// Delete
MapNode *deleteNode(MapNode *node, int key) {
    if (node == NULL)
        return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        if (node->left == NULL || node->right == NULL) {
            MapNode *temp = node->left ? node->left : node->right;
            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }
            free(temp);
        } else {
            MapNode *temp = findMinNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Interface
void map_init(Map *map) {
    map->_root = NULL;
    map->_size = 0;
}

bool map_empty(Map *map) {
    return map->_size == 0;
}

void map_insert(Map *map, int key, int value) {
    MapNode *found = findNode(map->_root, key);
    if (!found)
        map->_size++;
    map->_root = insertNode(map->_root, key, value);
}

int map_get(Map *map, int key) {
    MapNode *node = findNode(map->_root, key);
    return node ? node->value : 0;
}

void map_erase(Map *map, int key) {
    if (findNode(map->_root, key)) {
        map->_root = deleteNode(map->_root, key);
        map->_size--;
    }
}

void map_traverse(MapNode *node) {
    if (node) {
        map_traverse(node->left);
        printf("%d => %d\n", node->key, node->value);
        map_traverse(node->right);
    }
}

// Main
int main() {
    Map m;
    map_init(&m);

    if (map_empty(&m)) {
        printf("Map ini kosong\n");
    }

    map_insert(&m, 1, 2);
    map_insert(&m, 2, 3);
    map_insert(&m, 3, 4);
    map_insert(&m, 4, 5);
    map_insert(&m, 5, map_get(&m, 5) + 1); // increment

    printf("\nIsi map:\n");
    map_traverse(m._root);

    printf("\nCari key 1:\n");
    printf("1 => %d\n", map_get(&m, 1));

    printf("\nHapus key 1 dan 2:\n");
    map_erase(&m, 1);
    map_erase(&m, 2);

    printf("Map setelah penghapusan:\n");
    map_traverse(m._root);

    return 0;
}
