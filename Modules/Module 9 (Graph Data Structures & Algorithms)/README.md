# Module 9: Graph Algorithms in C

A **Graph** is a non-linear data structure consisting of **Vertices** (Nodes) connected by **Edges** (Links). Graphs model real-world networks such as computer routing, social networks, transportation grids, and dependency topologies.

---

## 🎯 Learning Objectives

By the end of this module, students and learners will be able to:
- Model graphs using Adjacency Matrices, Adjacency Lists, and Edge Lists in pure C.
- Model implicit grid graphs (e.g. 2D mazes and tile boards).
- Traverse graphs using Breadth-First Search (BFS) and Depth-First Search (DFS).
- Implement Disjoint-Set Union (DSU / Union-Find) with path compression and union-by-rank.
- Construct Minimum Spanning Trees (MST) using Kruskal's algorithm.
- Calculate single-source shortest paths on weighted graphs using Dijkstra's algorithm.

---

## 1. Graph Representations (`Representasi.c`)

Before processing a graph, we must store it in memory. There are three common ways:

### A. Adjacency Matrix
A 2D array `adj[i][j]` where `1` indicates a connection and `0` indicates none.
* **Pros:** Fast lookup (O(1)) to check if two nodes are connected.
* **Cons:** Consumes O(V^2) memory, wasteful for sparse graphs.

### B. Adjacency List
An array of Linked Lists where `adj[i]` points to a list of neighbors for vertex `i`.
* **Pros:** Saves memory (O(V+E)).
* **Cons:** Slower lookup (O(Degree)).

### C. Edge List
An array of structs `{u, v}` that simply lists every connection. Used in algorithms like Kruskal's.

```c
typedef struct Edge {
    int u, v;
} Edge;

```

---

## 2. Graph Traversal

Traversing means visiting every node in the graph.

### A. Breadth-First Search (BFS) (`BFS.c`)

Explores the graph **layer by layer** (closest neighbors first).

* **Data Structure:** Uses a **Queue** (FIFO).
* **Logic:**
1. Start at a node, mark as visited, enqueue it.
2. Dequeue a node, visit all its unvisited neighbors, and enqueue them.


* **Application:** Finding the shortest path in unweighted graphs.

### B. Depth-First Search (DFS) (`DFS.c`)

Explores as **deep** as possible along each branch before backtracking.

* **Data Structure:** Uses a **Stack** (or Recursion).
* **Logic:**
1. Visit a node, mark as visited.
2. Recursively call DFS on the first unvisited neighbor.


* **Application:** Maze solving, cycle detection.

### C. Implicit Graph DFS (`Implisit.c`)

Sometimes graphs aren't stored explicitly but exist as a grid (e.g., a maze or a map).

* **Logic:** The "neighbors" are calculated mathematically (e.g., `x+1`, `y-1`).
* **Boundary Checks:** The `isValid()` function ensures we don't go out of the grid bounds.

---

## 3. Disjoint Set Union (DSU) (`Disjoint-Set_Union.c`)

A helper data structure used to track which "set" or "group" an element belongs to. Essential for Kruskal's Algorithm.

* **`find(i)`**: Returns the representative (root) of the set containing `i`. Uses **Path Compression** to make future lookups fast.
* **`union(i, j)`**: Merges the set containing `i` and the set containing `j`.

```c
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]); // Path Compression
    return parent[x];
}

```

---

## 4. Minimum Spanning Tree (MST)

An MST connects all vertices in a graph with the **minimum possible total edge weight**, without forming any cycles.

### Kruskal's Algorithm (`Kruskal_DSU.c` & `Algoritma_Kruskal.c`)

A **Greedy Algorithm** that builds the MST edge by edge.

1. **Sort** all edges from smallest weight to largest.
2. Iterate through the edges.
3. **Check:** If adding the edge connects two previously unconnected nodes (using `find`), add it.
4. **Union:** Merge the sets of the two nodes.
5. If adding the edge would create a cycle (both nodes are already in the same set), **skip** it.

```c
// Core Logic
if (find(u) != find(v)) {
    unionSet(u, v);
    mstWeight += w;
}

```

---

## 5. Shortest Path Algorithms

### Dijkstra's Algorithm (`Dijkstra.c`)

Finds the shortest path from a **Start Node** to all other nodes in a weighted graph.

* **Concept:** "Relaxation". We always process the closest known node next.
* **Logic:**
1. Set distance to start = 0, all others = Infinity (`INF`).
2. Pick the unvisited node with the smallest distance.
3. Check its neighbors: If going through this node is shorter than the current known path, update the neighbor's distance.


```c
if (dist[u] + weight < dist[v]) {
    dist[v] = dist[u] + weight;
}

```


* **Note:** This implementation uses a simple array scan (O(V^2)). For efficiency with huge graphs, a Priority Queue is usually preferred.

---

## ⚠️ Common Pitfalls & Tips

1. **Adjacency Matrix Memory Footprint:**
   An adjacency matrix requires $V \times V$ integers. For $V = 100,000$ vertices, an adjacency matrix requires $\sim 40\text{ GB}$ of RAM! Always use Adjacency Lists for sparse graphs ($E \ll V^2$).
2. **Visited Array in Cyclic Graphs:**
   Failing to track visited nodes in cyclic graphs causes BFS and DFS to loop indefinitely. Always mark `visited[u] = true` as soon as a vertex is discovered.
3. **Negative Edge Weights with Dijkstra:**
   Dijkstra's greedy assumption assumes distance only increases. If negative edges exist, Dijkstra can output incorrect shortest paths or loop forever.

---

## 🧪 Hands-On Practice Challenges

- 🟢 **Challenge 1 (Connected Components Count)**:
  Given an undirected graph represented as an adjacency matrix, use BFS or DFS to determine how many connected sub-networks exist.
- 🟡 **Challenge 2 (Cycle Detection in Undirected Graph)**:
  Implement cycle detection using the Disjoint-Set Union (DSU) data structure.
- 🔴 **Challenge 3 (Maze Shortest Path via Implicit BFS)**:
  Using the implicit grid representation (`Implisit.c`), find the minimum number of steps required to navigate from the top-left cell $(0,0)$ to the bottom-right cell $(R-1, C-1)$ in a 2D obstacle maze.
