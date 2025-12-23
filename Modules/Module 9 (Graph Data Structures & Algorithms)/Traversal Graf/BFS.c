/*Implementasi BFS dalam C (Adjacency List)*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// ==== Struktur untuk Adjacency List ====
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// ==== Queue untuk BFS ====
typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;

    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// ==== Utility ====
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

// ==== BFS ====
void BFS(int startVertex) {
    Queue* q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("Visited %d\n", current);

        Node* temp = adjList[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(q, neighbor);
            }
            temp = temp->next;
        }
    }

    free(q);
}

// ==== Main ====
int main() {
    int V = 5;

    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Tambahkan sisi
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    // Jalankan BFS dari simpul 0
    printf("BFS traversal mulai dari simpul 0:\n");
    BFS(0);

    return 0;
}
