/*DFS pada Graf Tak Berarah (Adjacency List)*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Struktur node untuk adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Array of adjacency list
Node* adjList[MAX_VERTICES];

// Array penanda kunjungan
int visited[MAX_VERTICES];

// Buat simpul baru
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Tambahkan edge ke adjacency list (graf tak berarah)
void addEdge(int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

// Fungsi DFS rekursif
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    Node* temp = adjList[vertex];
    while (temp != NULL) {
        int next = temp->vertex;
        if (!visited[next]) {
            DFS(next);
        }
        temp = temp->next;
    }
}

int main() {
    int V = 5;  // Jumlah simpul

    // Inisialisasi adjacency list dan visited
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Tambahkan sisi
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    // DFS dari simpul 0
    printf("DFS traversal mulai dari simpul 0:\n");
    DFS(0);

    return 0;
}
