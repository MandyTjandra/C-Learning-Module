# 🧠 C Language, Data Structures & Algorithms Module

> A comprehensive, hands-on C programming curriculum spanning fundamental syntax, manual memory management with pointers, algorithm analysis, low-level data structures (Linked Lists, Stacks, Queues, Deques), self-balancing AVL Binary Search Trees, and Graph algorithms in pure C.

[![Language: C](https://img.shields.io/badge/Language-C99%20%2F%20C11-A8B9CC.svg?logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Compiler: GCC](https://img.shields.io/badge/Compiler-GCC%20%2F%20Clang-brightgreen.svg)](https://gcc.gnu.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Curriculum Level](https://img.shields.io/badge/Level-Beginner%20to%20Advanced-orange.svg)](#-curriculum-roadmap)

---

## 📖 About This Project

This repository serves as a modular study guide for mastering the **C programming language** and foundational **Computer Science Data Structures and Algorithms (DSA)**.

- 🎓 **For Learners & Students**: Isolated, runnable `.c` source files with no heavy external dependencies. Grasp memory pointers, structs, dynamic memory allocation (`malloc`, `free`), trees, and graphs from first principles.
- 👨‍🏫 **For Educators & Mentors**: A structured 9-chapter curriculum suitable for university CS1/CS2 courses, Data Structures lab practica, and Systems Programming tracks.
- 🌐 **Bilingual Context**: Clear English documentation alongside Indonesian (`🇮🇩`) comments, terminology, and practical real-world examples.

---

## 🛠️ Compilation & Quickstart

### Prerequisites
Make sure you have a standard C compiler installed (`gcc` via MinGW on Windows or GCC/Clang on macOS/Linux):

```bash
# Verify GCC compiler installation
gcc --version
```

### Clone the Repository
```bash
git clone https://github.com/MandyTjandra/C-Learning-Module.git
cd C-Learning-Module
```

### Compiling and Running Any Program
Compile using standard `gcc` flags:

```bash
# Windows (PowerShell / Command Prompt):
gcc -O2 "Modules/Module 1 (Conditional)/If.c" -o program.exe
.\program.exe

# macOS / Linux:
gcc -O2 "Modules/Module 1 (Conditional)/If.c" -o program
./program
```

---

## 🗺️ Curriculum Roadmap

| Module | Core Topics | Key Learning Competencies | Level | Link |
| :---: | :--- | :--- | :---: | :---: |
| **01** | **Conditionals** | `if`, `else if`, `else`, ternary operator, `switch-case` | Control execution branching and jump-table evaluation. | Beginner | [Module 1](./Modules/Module%201%20(Conditional)) |
| **02** | **Loops, Arrays & Strings** | `for`, `while`, `do-while`, 1D/2D arrays, C-strings, `string.h` | Iteration control, memory sizing with `sizeof`, array bounds, and safe string manipulation (`fgets` vs `gets`). | Beginner-Intermediate | [Module 2](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)) |
| **03** | **Functions & Recursion** | Prototypes, parameters, pass-by-value, recursive call stack | Break applications into modular functions and manage recursive base cases. | Intermediate | [Module 3](./Modules/Module%203%20(Function%20and%20Recursive)) |
| **04** | **Pointers & Structs** | Address-of (`&`), dereferencing (`*`), double pointers (`**`), structs | Direct memory inspection, pointer arithmetic, pass-by-reference, and custom data models. | Intermediate | [Module 4](./Modules/Module%204%20(Pointer%20and%20Struct)) |
| **05** | **Sorting & Searching** | Linear/Binary Search, Bubble, Insertion, Merge, Quick Sort | Fundamental algorithmic paradigms (Divide & Conquer, Two Pointers) and asymptotic time complexity. | Intermediate | [Module 5](./Modules/Module%205%20(Sorting%20and%20Searching%20Algorithm)) |
| **06** | **File Handling** | `FILE*`, `fopen`, `fprintf`, `fscanf`, `fgets`, `fputs`, `fclose` | Persistent disk I/O, file access modes (`"w"`, `"r"`, `"a"`), and file descriptor lifecycle management. | Intermediate | [Module 6](./Modules/Module%206%20(File%20Handling)) |
| **07** | **Linear Data Structures** | Dynamic arrays, Singly/Doubly/Circular Linked Lists, Stacks, Queues, Deque | Manual memory management with `malloc`/`free`, pointer re-linking, LIFO/FIFO buffers. | Intermediate-Advanced | [Module 7](./Modules/Module%207%20(Linear%20Data%20Structures)) |
| **08** | **Binary Search Tree & AVL** | BST insertion/search/deletion, Traversals, AVL tree rotations (LL, RR, LR, RL), Map, Set | Tree structures, maintaining $O(\log N)$ logarithmic depth with self-balancing tree rotations. | Advanced | [Module 8](./Modules/Module%208%20(Binary%20Search%20Tree)) |
| **09** | **Graph Algorithms** | Adjacency Matrix/List, BFS, DFS, Kruskal's MST, Disjoint Set Union (DSU), Dijkstra | Non-linear network modeling, graph traversal, minimum spanning trees, and single-source shortest paths. | Advanced | [Module 9](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)) |

---

## 📂 Detailed File-by-File Course Catalog

### 📘 [Module 1: Conditional Statements](./Modules/Module%201%20(Conditional))
*5 standalone source files on decision branching:*
* **[`If.c`](./Modules/Module%201%20(Conditional)/If.c)**: Basic single-branch guard checking variable thresholds.
* **[`IfElse.c`](./Modules/Module%201%20(Conditional)/IfElse.c)**: Two-way decision branching.
* **[`IfElseIf.c`](./Modules/Module%201%20(Conditional)/IfElseIf.c)**: Multi-branch condition ladder.
* **[`OperatorKondisional.c`](./Modules/Module%201%20(Conditional)/OperatorKondisional.c)**: Inline ternary conditional expressions `(condition ? true_val : false_val)`.
* **[`SwitchCase.c`](./Modules/Module%201%20(Conditional)/SwitchCase.c)**: Discrete integral matching with `switch`, `case`, `break`, and `default`.

---

### 📙 [Module 2: Looping, Arrays, and Strings](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String))
*25 source files covering loops, multidimensional memory buffers, and text handling:*
* **Looping Constructs**:
  * [`For.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/For.c) — Counted iteration loops.
  * [`While.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/While.c) — Pre-test condition loops.
  * [`DoWhile.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/DoWhile.c) — Post-test iteration loops.
  * [`NestedLoop.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/NestedLoop.c) — Nested loops for multidimensional index traversal.
  * [`Break.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Break.c) — Premature loop termination.
  * [`Continue.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Continue.c) — Skipping the current cycle.
  * [`InfiniteLoop.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/InfiniteLoop.c) — Infinite loop traps and stop conditions.
* **Arrays & Algorithms**:
  * [`Array.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Array.c) & [`Array2.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Array2.c) — Static array declaration, zero-based indexing, and element modification.
  * [`ForArray.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/ForArray.c) — Iterating across array indices.
  * [`Array2d.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Array2d.c) & [`DimensiArray.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/DimensiArray.c) — 2D matrix arrays and coordinate traversal.
  * [`ReverseArray.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/ReverseArray.c) — Inverting array elements in-place.
  * [`MaxAndMin.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/MaxAndMin.c) — Finding maximum and minimum values in an array.
  * [`Modus.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Modus.c) — Statistical mode (most frequent value) frequency counter.
  * [`SizeOfOperator.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/SizeOfOperator.c) — Array length calculation via `sizeof(arr) / sizeof(arr[0])`.
* **String Manipulation**:
  * [`String.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/String.c) & [`String2.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/String2.c) — Null-terminated character arrays (`char[]`).
  * [`InputOutputString.c`](./Modules/Module%202%20(Looping%2C%20Array%20dan%20String)/InputOutputString.c) — Reading strings with `scanf("%s")`.
  * [`Gets.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Gets.c) & [`Fgets.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Fgets.c) — Unsafe `gets()` vs secure buffer-limited `fgets(str, sizeof(str), stdin)`.
  * [`Strlen.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Strlen.c) — Measuring length with `strlen()`.
  * [`Strcpy.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Strcpy.c) — Copying string buffers with `strcpy()`.
  * [`Strcat.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Strcat.c) — Concatenating strings with `strcat()`.
  * [`Strcmp.c`](./Modules/Module%202%20(Looping%2C%20Array%2C%20dan%20String)/Strcmp.c) — Lexicographical comparison with `strcmp()`.

---

### 📗 [Module 3: Functions and Recursion](./Modules/Module%203%20(Function%20and%20Recursive))
*7 source files covering modular procedure design:*
* **[`PendefinisianFungsi.c`](./Modules/Module%203%20(Function%20and%20Recursive)/PendefinisianFungsi.c)**: Declaring and invoking void functions.
* **[`PrototypeFungsi.c`](./Modules/Module%203%20(Function%20and%20Recursive)/PrototypeFungsi.c)**: Function prototyping for forward declaration.
* **[`ParameterFungsi.c`](./Modules/Module%203%20(Function%20and%20Recursive)/ParameterFungsi.c)**: Passing arguments into function parameters.
* **[`FungsiReturn.c`](./Modules/Module%203%20(Function%20and%20Recursive)/FungsiReturn.c)**: Returning calculated values to caller.
* **[`Rekursi.c`](./Modules/Module%203%20(Function%20and%20Recursive)/Rekursi.c)** & **[`Rekursi2.c`](./Modules/Module%203%20(Function%20and%20Recursive)/Rekursi2.c)**: Self-invoking recursive functions.
* **[`BaseCase.c`](./Modules/Module%203%20(Function%20and%20Recursive)/BaseCase.c)**: Establishing boundary base cases to avoid infinite recursion.

---

### 📕 [Module 4: Pointers and Structures](./Modules/Module%204%20(Pointer%20and%20Struct))
*8 source files on direct memory access and custom types:*
* **[`OperatorAddressOf.c`](./Modules/Module%204%20(Pointer%20and%20Struct)/OperatorAddressOf.c)**: Retrieving memory addresses via `&var`.
* **[`PengenalanPointer.c`](./Modules/Module%204%20(Pointer%20and%20Struct)/PengenalanPointer.c)**: Dereferencing pointers (`*ptr`) to read and mutate memory.
* **[`PointerDanArray.c`](./Modules/Module%204%20(Pointer%20and%20Struct)/PointerDanArray.c)**: Pointer arithmetic (`ptr + i`) and array decays.
* **[`DoublePointer.c`](./Modules/Module%204%20(Pointer%20and%20Struct)/DoublePointer.c)**: Pointer-to-pointer references (`int**`).
* **[`PassByValue.c`](./Modules/Module%204%20(Pointer%20and%20Struct)/PassByValue.c)** & **[`PassbyAddress.c`](./Modules/Module%204%20(Pointer%20and%20Struct)/PassbyAddress.c)**: Contrasting parameter copy semantics vs memory pointer mutation (`swap(&a, &b)`).
* **[`Struct.c`](./Modules/Module%204%20(Pointer%20and%20Struct)/Struct.c)**: Custom data bundling with `struct` and the dot (`.`) operator.
* **[`ArrayOfStruct.c`](./Modules/Module%204%20(Pointer%20and%20Struct)/ArrayOfStruct.c)**: Managing lists of structured records in arrays.

---

### 🟪 [Module 5: Sorting & Searching Algorithms](./Modules/Module%205%20(Sorting%20and%20Searching%20Algorithm))
*6 source files implementing classical CS algorithms:*
* **[`LinearSearch.c`](./Modules/Module%205%20(Sorting%20and%20Searching%20Algorithm)/LinearSearch.c)**: Sequential scanning in $O(N)$ time.
* **[`BinarySearch.c`](./Modules/Module%205%20(Sorting%20and%20Searching%20Algorithm)/BinarySearch.c)**: Divide-and-conquer searching on sorted data in $O(\log N)$ time.
* **[`BubbleSort.c`](./Modules/Module%205%20(Sorting%20and%20Searching%20Algorithm)/BubbleSort.c)**: Adjacent element swapping in $O(N^2)$ time.
* **[`InsertionSort.c`](./Modules/Module%205%20(Sorting%20and%20Searching%20Algorithm)/InsertionSort.c)**: Incremental element insertion in $O(N^2)$ time.
* **[`MergeSort.c`](./Modules/Module%205%20(Sorting%20and%20Searching%20Algorithm)/MergeSort.c)**: Stable recursive divide-and-conquer sort in $O(N \log N)$ time.
* **[`QuickSort.c`](./Modules/Module%205%20(Sorting%20and%20Searching%20Algorithm)/QuickSort.c)**: In-place pivot partitioning sort with average $O(N \log N)$ complexity.

---

### 🗃️ [Module 6: File Handling](./Modules/Module%206%20(File%20Handling))
*4 source files on persistent disk storage:*
* **[`CreateFiles.c`](./Modules/Module%206%20(File%20Handling)/CreateFiles.c)**: Opening file descriptors using `fopen()`.
* **[`WriteToFiles.c`](./Modules/Module%206%20(File%20Handling)/WriteToFiles.c)**: Writing data to text files using `fprintf()` and `"w"` mode.
* **[`ReadFiles.c`](./Modules/Module%206%20(File%20Handling)/ReadFiles.c)**: Reading file contents line-by-line using `fgets()` and `"r"` mode.
* **[`AppendContent.c`](./Modules/Module%206%20(File%20Handling)/AppendContent.c)**: Appending records to existing files without overwriting using `"a"` mode.

---

### 🔗 [Module 7: Linear Data Structures](./Modules/Module%207%20(Linear%20Data%20Structures))
*18 source files implementing dynamic pointer-based structures:*
* **Dynamic Arrays**: [`DynamicArray.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/DynamicArray.c), [`IteratorBasic.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/IteratorBasic.c).
* **Linked Lists**:
  * [`SinglyLingkedList.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Linked%20List/SinglyLingkedList.c) — Forward-pointing node chain.
  * [`DoublyLingkedList.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Linked%20List/DoublyLingkedList.c) — Two-way bidirectional node pointers (`next` and `prev`).
  * [`CircularLingkedList.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Linked%20List/CircularLingkedList.c) — Closed loop list where tail references head.
  * [`BasicFuntion.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Linked%20List/BasicFuntion.c) — Insertion, deletion, and traversal helper functions.
* **Stacks (LIFO)**: Array-based ([`StackArray.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Stack/StackArray.c)), Pointer-based ([`StackBasic.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Stack/StackBasic.c), [`StackList.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Stack/StackList.c)), and Stack Sorting ([`Sorting.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Stack/Sorting.c)).
* **Queues (FIFO)**: Array-based ([`QueueArray.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Queue/QueueArray.c)), Linked List-based ([`QueueBasic.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Queue/QueueBasic.c), [`QueueList.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Queue/QueueList.c)), and Queue Sorting ([`Sorting.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Queue/Sorting.c)).
* **Double-Ended Queues (Deque)**: [`DEQUE_Array_Basic.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/DEQUE/DEQUE_Array_Basic.c) and [`Deque_Struct_Basic.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/DEQUE/Deque_Struct_Basic.c).
* **Priority Queues**: [`PQ_Array_Basic.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Priority%20Queue/PQ_Array_Basic.c) and binary heap implementation [`PQ_Heap_Basic.c`](./Modules/Module%207%20(Linear%20Data%20Structures)/Priority%20Queue/PQ_Heap_Basic.c).

---

### 🌲 [Module 8: Binary Search Tree (BST) & AVL Trees](./Modules/Module%208%20(Binary%20Search%20Tree))
*18 source files covering non-linear hierarchical tree structures:*
* **BST Fundamentals**: [`Basic_Function.c`](./Modules/Module%208%20(Binary%20Search%20Tree)/Basic_Function.c), [`Insert/`](./Modules/Module%208%20(Binary%20Search%20Tree)/Insert) (Iterative & Recursive), [`Find/`](./Modules/Module%208%20(Binary%20Search%20Tree)/Find), [`Remove/`](./Modules/Module%208%20(Binary%20Search%20Tree)/Remove), and [`Traversal/`](./Modules/Module%208%20(Binary%20Search%20Tree)/Traversal%20Binary%20Search%20Tree) (In-order, Pre-order, Post-order).
* **AVL Trees (Adelson-Velsky & Landis)**:
  * [`AVL.c`](./Modules/Module%208%20(Binary%20Search%20Tree)/AVL%20Tree%20(Adelson-Velsky%20and%20Landis%20Tree)/AVL.c) — Complete self-balancing AVL Tree.
  * Rotations: Left Rotation ([`Rotasi_Kiri.c`](./Modules/Module%208%20(Binary%20Search%20Tree)/AVL%20Tree%20(Adelson-Velsky%20and%20Landis%20Tree)/Rotasi/Rotasi_Kiri.c)), Right Rotation ([`Rotasi_Kanan.c`](./Modules/Module%208%20(Binary%20Search%20Tree)/AVL%20Tree%20(Adelson-Velsky%20and%20Landis%20Tree)/Rotasi/Rotasi_Kanan.c)), Left-Right Zig-Zag ([`Left-Right_Zig-Zag.c`](./Modules/Module%208%20(Binary%20Search%20Tree)/AVL%20Tree%20(Adelson-Velsky%20and%20Landis%20Tree)/Rotasi/Left-Right_Zig-Zag.c)), and Right-Left Zig-Zag ([`Right-Left_Zig-Zag.c`](./Modules/Module%208%20(Binary%20Search%20Tree)/AVL%20Tree%20(Adelson-Velsky%20and%20Landis%20Tree)/Rotasi/Right-Left_Zig-Zag.c)).
  * Operations: [`Search_and_Insertion.c`](./Modules/Module%208%20(Binary%20Search%20Tree)/AVL%20Tree%20(Adelson-Velsky%20and%20Landis%20Tree)/Search%20dan%20Insertion/Search_and_Insertion.c) and [`Deletion.c`](./Modules/Module%208%20(Binary%20Search%20Tree)/AVL%20Tree%20(Adelson-Velsky%20and%20Landis%20Tree)/Deletion/Deletion.c).
* **Tree Applications in Pure C**: Custom Map (`Map/Map.c`), Set (`Set/Set.c`), and Self-Balancing abstractions (`Self-Balancing BST/Self_Balancing.c`).

---

### 🌐 [Module 9: Graph Data Structures & Algorithms](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms))
*8 source files on graph theory:*
* **Graph Modeling**: Adjacency Matrix & List ([`Representasi.c`](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Cara%20Merepresentasikan%20Graf/Representasi.c)) and Implicit Grid Graph ([`Implisit.c`](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Implisit%20Graf/Implisit.c)).
* **Traversals**: Breadth-First Search ([`BFS.c`](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Traversal%20Graf/BFS.c)) and Depth-First Search ([`DFS.c`](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Traversal%20Graf/DFS.c)).
* **Minimum Spanning Tree (MST)**: Disjoint Set Union ([`Disjoint-Set_Union.c`](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Minimum%20Spanning%20Tree/Disjoint-Set_Union.c)), Kruskal's Algorithm ([`Algoritma_Kruskal.c`](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Minimum%20Spanning%20Tree/Algoritma_Kruskal.c)), and Combined Kruskal-DSU ([`Kruskal_DSU.c`](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Minimum%20Spanning%20Tree/Kruskal_DSU.c)).
* **Shortest Path**: Dijkstra's Algorithm in C ([`Dijkstra.c`](./Modules/Module%209%20(Graph%20Data%20Structures%20%26%20Algorithms)/Shortest%20Path/Dijkstra.c)).

---

## 👨‍🏫 Pedagogical Study Method

```
 ┌──────────────┐     ┌──────────────┐     ┌──────────────┐     ┌──────────────┐
 │  1. EXAMINE  │ ──> │  2. COMPILE  │ ──> │3. EXPERIMENT │ ──> │   4. APPLY   │
 │ Read concept │     │ Build with   │     │ Test edge    │     │ Implement in │
 │  & comments  │     │ gcc -O2      │     │ cases & bugs │     │  challenges  │
 └──────────────┘     └──────────────┘     └──────────────┘     └──────────────┘
```

1. **Examine**: Study the module's `README.md` for memory models, pointer diagrams, and asymptotic complexities.
2. **Compile**: Compile with `gcc -Wall -O2 filename.c -o program`.
3. **Experiment**: Modify values, test corner cases (e.g. `NULL` pointer checks, empty lists), and verify memory safety.
4. **Apply**: Solve the graded practice exercises at the end of each module.

---

## 🤝 Contributing

Contributions are welcomed! Feel free to:
- Add exercise challenge solutions.
- Add additional data structures (e.g. Trie, Red-Black Trees, Segment Trees).
- Improve code comments and memory explanations.

Open a Pull Request or create an Issue to contribute.

---

## 📜 License

This project is licensed under the [MIT License](LICENSE) © 2026 Mandy Tjandra. Free for educational and personal use. Happy coding! 💻✨
