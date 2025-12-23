# Module 8: Trees, Traversals, and Associative Structures

This module covers the entire hierarchy of Tree structures in C:
1.  **Binary Search Trees (BST):** The foundational structure.
2.  **Tree Traversals:** Different ways to visit every node (DFS vs BFS).
3.  **AVL Trees:** Optimizing BSTs to remain balanced (O(log n)).
4.  **Sets & Maps:** Real-world applications of Balanced Trees.

---

## 1. Binary Search Tree (BST) Basics

A BST organizes data so that for every node, the **Left Child < Parent < Right Child**.

### A. Recursive vs. Iterative (`Rekursif.c` & `Iteratif.c`)
* **Recursive:** Cleaner code. Uses the system stack.
    ```c
    // Recursive Insert
    Node* insert(Node* root, int value) {
        if (root == NULL) return createNode(value);
        if (value < root->value) root->left = insert(root->left, value);
        else root->right = insert(root->right, value);
        return root;
    }
    ```
* **Iterative:** More memory efficient (no stack overflow risk).
    ```c
    // Iterative Search
    while (current != NULL) {
        if (target == current->value) return 1;
        if (target < current->value) current = current->left;
        else current = current->right;
    }
    ```

### B. Deletion Logic
Deleting a node is the hardest part of BSTs. We handle three cases:
1.  **Leaf Node:** Just remove it.
2.  **One Child:** The child replaces the parent.
3.  **Two Children:** Find the **In-order Successor** (smallest value in the right subtree), copy its value to the target node, and then delete the successor.

---

## 2. Tree Traversals (`Transversal.c`)

How do we "read" or "visit" every node in a tree?

### A. Depth-First Search (DFS)
Uses recursion (or a stack) to go deep into branches first.
* **Inorder (Left -> Root -> Right):** Results in sorted data (ascending).
    ```c
    void inorder(Node* root) {
        if (root) { inorder(root->left); printf("%d ", root->value); inorder(root->right); }
    }
    ```
* **Preorder (Root -> Left -> Right):** Good for copying/cloning trees.
* **Postorder (Left -> Right -> Root):** Good for deleting trees (delete children before parent).

### B. Breadth-First Search (BFS) / Level Order
Visits nodes level-by-level (Level 1, then Level 2, etc.).
* **Implementation:** Uses a **Queue**.
* **Logic:** Enqueue Root -> Dequeue & Print -> Enqueue Left Child -> Enqueue Right Child -> Repeat.

---

## 3. AVL Trees (Self-Balancing)

Standard BSTs can become "skewed" (like a linked list) if data is inserted in sorted order (1, 2, 3, 4, 5). **AVL Trees** fix this by ensuring the height difference (Balance Factor) between left and right subtrees is never more than 1.

### A. Logic (`Self_Balancing.c`)
Every node tracks its `height`. After every insertion/deletion, we check the **Balance Factor**:
```c
int getBalance(struct Node* N) {
    return height(N->left) - height(N->right);
}

```

### B. Rotations

If `Balance > 1` or `Balance < -1`, we perform rotations to fix the structure:

1. **Left Rotation:** Fixes Right-Right imbalance.
2. **Right Rotation:** Fixes Left-Left imbalance.
3. **Left-Right / Right-Left:** Double rotations for "Zig-Zag" cases.

---

## 4. Associative Containers (Applications)

We use Balanced BSTs (AVL) to build powerful Abstract Data Types (ADTs).

### A. The Set (`Set.c`)

A **Set** is a collection of **unique** keys, stored in sorted order.

* **Why AVL?** Allows checking if a number exists (`avl_find`) in O(log n) time, which is much faster than an array O(n).
* **Feature:** Duplicates are automatically rejected during insertion.

### B. The Map (`Map.c`)

A **Map** (or Dictionary) stores **Key-Value Pairs**.

* **Structure:**
```c
typedef struct MapNode {
    int key;    // Used for sorting/balancing
    int value;  // The actual data stored
    struct MapNode *left, *right;
} MapNode;

```


* **Usage:**
```c
map_insert(&m, 1, 2); // Key 1 maps to Value 2
printf("%d", map_get(&m, 1)); // Returns 2

```


* **Efficiency:** Finding a value by its key takes O(log n).

---

## 🚀 Comparison Summary

| Structure | Ordering | Duplicates? | Search Speed | Best For |
| --- | --- | --- | --- | --- |
| **Array** | None (unless sorted) | Yes | O(N) | Simple storage |
| **BST** | Sorted | Depends | O(N) (Worst case) | Hierarchical data |
| **AVL Tree** | Sorted | Depends | O(log N) | Performance critical lookups |
| **Set** | Sorted | No | O(log N) | Checking "Have I seen this before?" |
| **Map** | Sorted by Key | Unique Keys | O(log N) | Dictionaries, Caching |
