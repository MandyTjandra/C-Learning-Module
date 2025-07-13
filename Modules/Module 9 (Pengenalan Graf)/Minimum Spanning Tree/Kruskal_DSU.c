/*Kode lengkap implementasi Algoritma Kruskal dalam bahasa C, 
menggunakan Edge List dan Disjoint Set Union (DSU)*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Struktur untuk Edge
typedef struct {
    int u, v, weight;
} Edge;

// Global
Edge edgeList[MAX_EDGES];
int parent[MAX_VERTICES];
int V, E; // Jumlah vertex dan edge

// ====== DSU: Find dengan Path Compression ======
int find_parent(int x) {
    if (parent[x] != x)
        parent[x] = find_parent(parent[x]);
    return parent[x];
}

// ====== DSU: Union ======
void union_set(int x, int y) {
    int xRoot = find_parent(x);
    int yRoot = find_parent(y);
    if (xRoot != yRoot)
        parent[yRoot] = xRoot;
}

// ====== Comparator untuk qsort ======
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// ====== Algoritma Kruskal ======
void kruskal() {
    // Inisialisasi parent untuk DSU
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    // Urutkan edge berdasarkan bobot
    qsort(edgeList, E, sizeof(Edge), compareEdges);

    int mstWeight = 0;
    printf("Edge dalam Minimum Spanning Tree:\n");

    int edgesUsed = 0;
    for (int i = 0; i < E && edgesUsed < V - 1; i++) {
        int u = edgeList[i].u;
        int v = edgeList[i].v;
        int w = edgeList[i].weight;

        if (find_parent(u) != find_parent(v)) {
            printf("%d -- %d (berat = %d)\n", u, v, w);
            union_set(u, v);
            mstWeight += w;
            edgesUsed++;
        }
    }

    printf("Total berat MST: %d\n", mstWeight);
}

// ====== Main ======
int main() {
    V = 5; // Jumlah simpul
    E = 7; // Jumlah sisi

    // Tambahkan edge ke list (u, v, weight)
    edgeList[0] = (Edge){0, 1, 10};
    edgeList[1] = (Edge){0, 2, 6};
    edgeList[2] = (Edge){0, 3, 5};
    edgeList[3] = (Edge){1, 3, 15};
    edgeList[4] = (Edge){2, 3, 4};
    edgeList[5] = (Edge){1, 2, 25};
    edgeList[6] = (Edge){3, 4, 2};

    kruskal();

    return 0;
}
