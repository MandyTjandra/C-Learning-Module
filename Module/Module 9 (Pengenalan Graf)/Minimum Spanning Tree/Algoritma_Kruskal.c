#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Struktur Edge
typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int V, E; // Jumlah simpul dan sisi

// Union-Find dengan Path Compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (xroot != yroot)
        parent[yroot] = xroot;
}

// Perbandingan untuk sorting edge
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal's Algorithm
void kruskal() {
    qsort(edges, E, sizeof(Edge), compareEdges);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int mstWeight = 0;
    printf("Edge dalam MST:\n");

    int edgeCount = 0;
    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            unionSet(u, v);
            printf("%d -- %d (berat = %d)\n", u, v, w);
            mstWeight += w;
            edgeCount++;
        }
    }

    printf("Total berat MST: %d\n", mstWeight);
}

// ==== Main ====
int main() {
    V = 5; // Jumlah simpul
    E = 7; // Jumlah sisi

    // Definisi edge (u, v, weight)
    edges[0] = (Edge){0, 1, 10};
    edges[1] = (Edge){0, 2, 6};
    edges[2] = (Edge){0, 3, 5};
    edges[3] = (Edge){1, 3, 15};
    edges[4] = (Edge){2, 3, 4};
    edges[5] = (Edge){1, 2, 25};
    edges[6] = (Edge){3, 4, 2}; // Tambahan edge ke simpul ke-4

    kruskal();

    return 0;
}
