/*Dijkstra's Algorithm (Graf Berbobot, Tak Berarah)*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Struktur node untuk adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];

// Buat simpul baru
Node* createNode(int vertex, int weight) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Tambahkan edge ke graf tak berarah
void addEdge(int u, int v, int weight) {
    Node* nodeV = createNode(v, weight);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u, weight);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

// Cari simpul dengan jarak minimum yang belum dikunjungi
int minDistance(int dist[], int visited[], int V) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Algoritma Dijkstra
void dijkstra(int V, int start) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];

    // Inisialisasi
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    // Proses semua simpul
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break; // Semua simpul terjangkau sudah diproses

        visited[u] = 1;

        // Update jarak tetangga dari u
        Node* temp = adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    // Cetak hasil
    printf("Jarak terpendek dari simpul %d:\n", start);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("Ke %d: Tidak terjangkau\n", i);
        else
            printf("Ke %d: %d\n", i, dist[i]);
    }
}

// ==== Main ====
int main() {
    int V = 5;

    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
    }

    // Tambahkan edge (u, v, weight)
    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(1, 4, 2);
    addEdge(2, 3, 4);
    addEdge(3, 0, 7);
    addEdge(3, 2, 6);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);

    dijkstra(V, 0); // Jalankan dari simpul 0

    return 0;
}
