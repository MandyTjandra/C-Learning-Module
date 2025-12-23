# Module 7: Linear Data Structures

This module covers advanced linear storage structures. Unlike static arrays, these structures define specific rules for how data is added, removed, and managed in memory.

---

## 1. Linked Lists

A **Linked List** is a chain of "Nodes" where each node contains data and a pointer to the next node. Unlike arrays, they are dynamic and do not require a contiguous block of memory.

### A. Basic Types

* **Singly Linked List (`SinglyLingkedList.c`):** Each node points forward to the `next` node.
* **Doubly Linked List (`DoublyLingkedList.c`):** Each node has a `next` pointer and a `prev` pointer, allowing traversal in both directions.
* **Circular Linked List (`CircularLingkedList.c`):** The last node points back to the `head` instead of `NULL`, creating an infinite loop.

### B. Full Implementation (`BasicFuntion.c`)

This file contains a complete library of Singly Linked List operations.

**Key Concept: Double Pointers (`Node **head`)**
We pass `**head` to functions because we need to modify the *actual* head pointer (e.g., when inserting at the front).

```c
// Adding a node to the front (Push Front)
void pushFront(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // 1. Create Node
    newNode->data = value;      // 2. Fill Data
    newNode->next = *head;      // 3. Point new node to current head
    *head = newNode;            // 4. Update head to be the new node
}

// Removing a node by value
void removeNode(Node **head, int value) {
    // Logic to find the node, re-link the previous node to the next node, 
    // and free the memory... (See source code)
}

```

---

## 2. The Stack (LIFO)

A **Stack** follows the **LIFO** (Last In, First Out) principle. Imagine a stack of plates; you add to the top and remove from the top.

### A. Array Implementation

* **`StackBasic.c`** & **`StackArray.c`**:
* Uses a fixed-size array (`int stack[SIZE]`) and a `top` integer.
* **Push:** Increment `top`, then insert data.
* **Pop:** Return data, then decrement `top`.
* **Peek:** Just return `stack[top]`.



### B. Linked List Implementation (`StackList.c`)

Dynamic implementation where the "Top" is the Head of the list.

* **Push:** Create a new node and make it the new Head.
* **Pop:** Remove the Head node and move the pointer to the `next` node.

### C. Stack Sorting (`SortingStack.c`)

Demonstrates how to sort a stack without complex pointer manipulation.

* **Logic:**
1. **Pop** all elements from the stack into a temporary array.
2. **Sort** the array using a standard algorithm (e.g., Bubble Sort).
3. **Push** the sorted elements back into the stack.



---

## 3. The Queue (FIFO)

A **Queue** follows the **FIFO** (First In, First Out) principle. Imagine a line of people; the first person to join is the first served.

### A. Array Implementation

* **`QueueBasic.c`** & **`QueueArray.c`**:
* Uses two indices: `front` (removal point) and `rear` (insertion point).
* **Enqueue (Push):** Increment `rear`, add data.
* **Dequeue (Pop):** Return data at `front`, increment `front`.



### B. Linked List Implementation (`QueueList.c`)

* **Enqueue:** Add a new node to the **Tail** (Rear).
* **Dequeue:** Remove the node from the **Head** (Front).
* **Benefit:** Unlike the array version, this never becomes "full" as long as system memory exists.

### C. Queue Sorting (`Sorting.c`)

Similar to stack sorting, but applied to queues.

* **Logic:** Transfer data to an array, sort the array, and re-enqueue everything back into the queue structure.

---

## 4. Deque (Double-Ended Queue)

A **Deque** (pronounced "Deck") is a generalized queue where you can add or remove elements from both the **Front** and the **Back**.

### A. Array Implementation (`DEQUE_Array_Basic.c`)

Uses a global array and circular logic.

* **Push Front:** Decrements front index.
* **Push Back:** Increments rear index.

### B. Struct Implementation (`Deque_Struct_Basic.c`)

Encapsulates the array and indices into a struct for cleaner code organization.

```c
typedef struct {
    int data[SIZE];
    int front;
    int rear;
} Deque;

void pushFront(Deque *deque, int value) {
    // Check if full...
    // Wrap around logic: if front is 0, new front becomes SIZE-1
    if (deque->front == 0) {
        deque->front = SIZE - 1;
    } else {
        deque->front--;
    }
    deque->data[deque->front] = value;
}

```

---

## 5. Priority Queues

A **Priority Queue** is a Queue where elements are popped based on **Importance (Priority)**, not just arrival time. In these examples, smaller numbers (or larger, depending on logic) have higher priority.

### A. Array Approach (`PQ_Array_Basic.c`)

* **Insertion ():** Slow. When you push data, the code shifts elements to keep the array sorted immediately.
* **Deletion ():** Fast. Since it's sorted, you just pick the top element.

```c
// Logic: Shift elements to make room for the new value
void push(PriorityQueue *pq, int value) {
    int i = pq->size - 1;
    while (i >= 0 && pq->data[i] < value) {
        pq->data[i + 1] = pq->data[i]; // Shift right
        i--;
    }
    pq->data[i + 1] = value; // Insert
}

```

### B. Heap Approach (`PQ_Heap_Basic.c`)

* **Insertion & Deletion ():** Efficient. Uses a Binary Heap (Tree structure) logic.
* **Heapify:** When adding, we add to the end and "bubble up" (swap with parent) if the order is wrong. When removing, we take the root, move the last element to the top, and "bubble down".

```c
// Logic: Add to end, then fix the heap order
void push(PriorityQueue *pq, int value) {
    pq->data[pq->size] = value;
    int current = pq->size; 
    
    // Heapify Up
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (pq->data[parent] > pq->data[current]) {
            swap(&pq->data[parent], &pq->data[current]);
            current = parent;
        } else {
            break;
        }
    }
}

```

**Comparison:** The Heap approach is much faster for large datasets because it doesn't require shifting the entire array.

---

## 6. Dynamic Arrays (Vectors)

Standard arrays in C (`int arr[10]`) have a fixed size. A **Dynamic Array** grows automatically when full.

### A. Implementation (`DynamicArray.c`)

This code manually implements the behavior of `std::vector` in C++.

```c
typedef struct {
    int *data;
    int size;      // Current number of elements
    int capacity;  // Total memory allocated
} DynamicArray;

void pushBack(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        // 1. Double the capacity
        arr->capacity *= 2;  
        // 2. Request more memory from RAM
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

```

**💡 Code Explanation:**

* **`capacity` vs `size`:** Capacity is how many seats are in the bus. Size is how many passengers are sitting.
* **`realloc`:** When the bus is full, this function effectively "buys a bigger bus" and moves everyone into it. This allows the array to accept unlimited inputs.

---

## 7. Iterators

### A. Pointer as Iterator (`IteratorBasic.c`)

C does not have high-level iterators like Python or Java, but **Pointers** serve the same purpose.

```c
void printArray(int *arr, int size) {
    // 'it' points to the start of the array
    // Loop continues as long as 'it' is within the array memory range
    for (int *it = arr; it < arr + size; ++it) {
        printf("%d ", *it);  // Access value
    }
}

```

**💡 Code Explanation:**

* `int *it = arr`: The iterator starts at index 0.
* `it < arr + size`: The loop stops when the pointer moves past the last element.
* `++it`: Moves the pointer to the next memory address (next integer).
