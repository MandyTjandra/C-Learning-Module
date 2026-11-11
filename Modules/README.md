# 📚 C Course Modules & File Syllabus Index

Welcome to the **Modules Directory** for the pure C curriculum. This collection spans **9 comprehensive chapters** containing **99 isolated, compilable C programs**, systematically covering foundational syntax, pointer mechanics, low-level dynamic data structures, balanced trees, and graph algorithms.

---

## 🧭 Curriculum Progression Track

```text
  ┌───────────────────────────┐       ┌───────────────────────────┐       ┌───────────────────────────┐
  │ Module 1: Conditionals    │ ────> │ Module 2: Loops & Strings │ ────> │ Module 3: Functions & Rec │
  │ if, else, switch, ternary │       │ for, while, 2D, string.h  │       │ Prototypes, Call Stack    │
  └───────────────────────────┘       └───────────────────────────┘       └───────────────────────────┘
                                                                                        │
  ┌───────────────────────────┐       ┌───────────────────────────┐                     ▼
  │ Module 6: File Handling   │ <──── │ Module 5: Sorting/Search  │ <──── ┌───────────────────────────┐
  │ FILE*, fopen, fread/write │       │ Quick, Merge, Binary Srch │       │ Module 4: Pointers/Struct │
  └───────────────────────────┘       └───────────────────────────┘       │ *, &, **, Pass-by-Address │
               │                                                          └───────────────────────────┘
               ▼
  ┌───────────────────────────┐       ┌───────────────────────────┐       ┌───────────────────────────┐
  │ Module 7: Linear Structs  │ ────> │ Module 8: BST & AVL Trees │ ────> │ Module 9: Graph DSA       │
  │ Lists, Stacks, Queues, PQ │       │ Balanced Trees, Rotations │       │ BFS, DFS, Dijkstra, MST   │
  └───────────────────────────┘       └───────────────────────────┘       └───────────────────────────┘
```

---

## 📋 Comprehensive Chapter Guide

### [Module 1: Conditional Statements](./Module%201%20(Conditional))
* **Level**: Beginner | **Est. Time**: 1 Hour
* **Key Files**: [`If.c`](./Module%201%20(Conditional)/If.c), [`IfElse.c`](./Module%201%20(Conditional)/IfElse.c), [`IfElseIf.c`](./Module%201%20(Conditional)/IfElseIf.c), [`OperatorKondisional.c`](./Module%201%20(Conditional)/OperatorKondisional.c), [`SwitchCase.c`](./Module%201%20(Conditional)/SwitchCase.c).
* **Core Competency**: Master logical branching, ternary operators, and efficient switch-case jump tables.

---

### [Module 2: Looping, Arrays, and Strings](./Module%202%20(Looping%2C%20Array%2C%20dan%20String))
* **Level**: Beginner - Intermediate | **Est. Time**: 2 - 3 Hours
* **Key Files**:
  * Loops: [`For.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/For.c), [`While.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/While.c), [`DoWhile.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/DoWhile.c), [`NestedLoop.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/NestedLoop.c).
  * Arrays: [`Array.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Array.c), [`Array2d.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Array2d.c), [`ReverseArray.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/ReverseArray.c), [`SizeOfOperator.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/SizeOfOperator.c).
  * Strings: [`Fgets.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Fgets.c), [`Strlen.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Strlen.c), [`Strcmp.c`](./Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Strcmp.c).
* **Core Competency**: Iterate with counters, navigate 1D and 2D matrices, compute byte lengths with `sizeof`, and safely process null-terminated character strings (`fgets`).

---

### [Module 3: Functions and Recursion](./Module%203%20(Function%20and%20Recursive))
* **Level**: Intermediate | **Est. Time**: 1.5 - 2 Hours
* **Key Files**: [`PrototypeFungsi.c`](./Module%203%20(Function%20and%20Recursive)/PrototypeFungsi.c), [`ParameterFungsi.c`](./Module%203%20(Function%20and%20Recursive)/ParameterFungsi.c), [`FungsiReturn.c`](./Module%203%20(Function%20and%20Recursive)/FungsiReturn.c), [`Rekursi.c`](./Module%203%20(Function%20and%20Recursive)/Rekursi.c), [`BaseCase.c`](./Module%203%20(Function%20and%20Recursive)/BaseCase.c).
* **Core Competency**: Modularize applications into reusable functions, forward declare prototypes, and implement recursive algorithms with terminating base cases.

---

### [Module 4: Pointers and Structures](./Module%204%20(Pointer%20and%20Struct))
* **Level**: Intermediate | **Est. Time**: 2 - 3 Hours
* **Key Files**: [`OperatorAddressOf.c`](./Module%204%20(Pointer%20and%20Struct)/OperatorAddressOf.c), [`PengenalanPointer.c`](./Module%204%20(Pointer%20and%20Struct)/PengenalanPointer.c), [`PointerDanArray.c`](./Module%204%20(Pointer%20and%20Struct)/PointerDanArray.c), [`DoublePointer.c`](./Module%204%20(Pointer%20and%20Struct)/DoublePointer.c), [`PassbyAddress.c`](./Module%204%20(Pointer%20and%20Struct)/PassbyAddress.c), [`Struct.c`](./Module%204%20(Pointer%20and%20Struct)/Struct.c).
* **Core Competency**: Inspect memory addresses (`&`), dereference memory (`*`), perform pointer arithmetic, mutate arguments via pass-by-address (`swap(&a, &b)`), and design composite data structures with `struct`.

---

### [Module 5: Sorting and Searching Algorithms](./Module%205%20(Sorting%20and%20Searching%20Algorithm))
* **Level**: Intermediate | **Est. Time**: 2 Hours
* **Key Files**: [`LinearSearch.c`](./Module%205%20(Sorting%20and%20Searching%20Algorithm)/LinearSearch.c), [`BinarySearch.c`](./Module%205%20(Sorting%20and%20Searching%20Algorithm)/BinarySearch.c), [`BubbleSort.c`](./Module%205%20(Sorting%20and%20Searching%20Algorithm)/BubbleSort.c), [`InsertionSort.c`](./Module%205%20(Sorting%20and%20Searching%20Algorithm)/InsertionSort.c), [`MergeSort.c`](./Module%205%20(Sorting%20and%20Searching%20Algorithm)/MergeSort.c), [`QuickSort.c`](./Module%205%20(Sorting%20and%20Searching%20Algorithm)/QuickSort.c).
* **Core Competency**: Implement classical sorting ($O(N^2)$ and $O(N \log N)$) and binary search ($O(\log N)$) from scratch in pure C.

---

### [Module 6: File Handling](./Module%206%20(File%20Handling))
* **Level**: Intermediate | **Est. Time**: 1 - 1.5 Hours
* **Key Files**: [`CreateFiles.c`](./Module%206%20(File%20Handling)/CreateFiles.c), [`WriteToFiles.c`](./Module%206%20(File%20Handling)/WriteToFiles.c), [`ReadFiles.c`](./Module%206%20(File%20Handling)/ReadFiles.c), [`AppendContent.c`](./Module%206%20(File%20Handling)/AppendContent.c).
* **Core Competency**: Persist data to disk using `FILE*`, file mode access (`"w"`, `"r"`, `"a"`), buffer-safe reading, and prevent resource leaks with `fclose()`.

---

### [Module 7: Linear Data Structures](./Module%207%20(Linear%20Data%20Structures))
* **Level**: Intermediate - Advanced | **Est. Time**: 3 - 4 Hours
* **Key Subfolders**:
  * [`Linked List/`](./Module%207%20(Linear%20Data%20Structures)/Linked%20List) — Singly, Doubly, and Circular Linked Lists.
  * [`Stack/`](./Module%207%20(Linear%20Data%20Structures)/Stack) — Array and node-based LIFO stacks with stack sorting.
  * [`Queue/`](./Module%207%20(Linear%20Data%20Structures)/Queue) — Array and node-based FIFO queues with queue sorting.
  * [`DEQUE/`](./Module%207%20(Linear%20Data%20Structures)/DEQUE) — Double-ended queues.
  * [`Priority Queue/`](./Module%207%20(Linear%20Data%20Structures)/Priority%20Queue) — Array and binary heap-based priority queues.
* **Core Competency**: Build manual dynamic memory data structures using `malloc` and `free`, re-linking node pointers without memory leaks.

---

### [Module 8: Binary Search Tree (BST) & AVL Trees](./Module%208%20(Binary%20Search%20Tree))
* **Level**: Advanced | **Est. Time**: 4 Hours
* **Key Subfolders**:
  * [`Basic_Function.c`](./Module%208%20(Binary%20Search%20Tree)/Basic_Function.c) — BST node creation and recursive tree logic.
  * [`Traversal Binary Search Tree/`](./Module%208%20(Binary%20Search%20Tree)/Traversal%20Binary%20Search%20Tree) — In-order, Pre-order, and Post-order traversals.
  * [`AVL Tree/`](./Module%208%20(Binary%20Search%20Tree)/AVL%20Tree%20(Adelson-Velsky%20and%20Landis%20Tree)) — Self-balancing AVL tree: Left Rotation, Right Rotation, Left-Right, and Right-Left rotations to maintain $O(\log N)$ height balance.
  * [`Map/`](./Module%208%20(Binary%20Search%20Tree)/Map) & [`Set/`](./Module%208%20(Binary%20Search%20Tree)/Set) — Implementing associative map and set collections in pure C.
* **Core Competency**: Implement non-linear hierarchical data structures and compute balance factors to rebalance trees automatically.

---

### [Module 9: Graph Data Structures & Algorithms](./Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms))
* **Level**: Advanced | **Est. Time**: 3 - 4 Hours
* **Key Subfolders**:
  * [`Cara Merepresentasikan Graf/`](./Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Cara%20Merepresentasikan%20Graf) — Matrix & List representations.
  * [`Traversal Graf/`](./Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Traversal%20Graf) — Breadth-First Search (BFS) and Depth-First Search (DFS).
  * [`Minimum Spanning Tree/`](./Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Minimum%20Spanning%20Tree) — Disjoint-Set Union (DSU) and Kruskal's algorithm.
  * [`Shortest Path/`](./Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Shortest%20Path) — Dijkstra's shortest path algorithm.
* **Core Competency**: Construct graphs in memory, explore network connections, find minimum spanning trees, and calculate optimal paths.

---

## 👩‍🏫 10-Week Semester Lesson Plan Blueprint (For Teachers)

| Week | Focus Topic | Key Demonstration Files | Lab Assignment |
| :---: | :--- | :--- | :--- |
| **Week 1** | Conditionals & Logic | `IfElseIf.c`, `SwitchCase.c` | Build a menu-driven unit converter. |
| **Week 2** | Loops, Arrays & C-Strings | `NestedLoop.c`, `SizeOfOperator.c`, `Fgets.c` | Implement matrix multiplication and a word palindromic tester. |
| **Week 3** | Functions & Call Stack | `PrototypeFungsi.c`, `Rekursi2.c`, `BaseCase.c` | Write recursive Tower of Hanoi and power functions. |
| **Week 4** | Pointer Mechanics & Memory | `PengenalanPointer.c`, `PassbyAddress.c`, `Struct.c` | Build an in-place array reversal utility using pointer arithmetic. |
| **Week 5** | Sorting & Searching Algorithms | `BinarySearch.c`, `MergeSort.c`, `QuickSort.c` | Benchmark runtime differences between Bubble Sort and Quick Sort. |
| **Week 6** | Persistent File Handling | `CreateFiles.c`, `WriteToFiles.c`, `ReadFiles.c` | Create a persistent student record manager saving to `.txt`. |
| **Week 7** | Dynamic Linked Lists | `SinglyLingkedList.c`, `DoublyLingkedList.c` | Build an insert-at-position, delete-at-position linked list. |
| **Week 8** | Stacks, Queues & Deques | `StackArray.c`, `QueueList.c`, `PQ_Heap_Basic.c` | Balanced bracket checker using custom dynamic C stack. |
| **Week 9** | Binary Search Trees & AVL | `Basic_Function.c`, `AVL.c`, `Rotasi_Kanan.c` | Construct an auto-balancing AVL tree and verify height invariants. |
| **Week 10** | Graph Algorithms in C | `BFS.c`, `DFS.c`, `Kruskal_DSU.c`, `Dijkstra.c` | Implement network routing and cycle detection in undirected graphs. |
