#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

// ==== 1. Adjacency Matrix ====
void printAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int V) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// ==== 2. Adjacency List ====
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct GraphList {
    Node* head[MAX_VERTICES];
} GraphList;

Node* createNode(int vertex) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void printAdjList(GraphList* graph, int V) {
    printf("Adjacency List:\n");
    for (int i = 0; i < V; i++) {
        Node* temp = graph->head[i];
        printf("%d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ==== 3. Edge List ====
typedef struct Edge {
    int u, v;
} Edge;

void printEdgeList(Edge edgeList[], int E) {
    printf("Edge List:\n");
    for (int i = 0; i < E; i++) {
        printf("%d -- %d\n", edgeList[i].u, edgeList[i].v);
    }
}

// ==== Main Program ====
int main() {
    int V = 5; // Jumlah simpul
    int E = 6; // Jumlah sisi

    // Contoh sisi
    Edge edgeList[MAX_EDGES] = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {3, 4}
    };

    // === Adjacency Matrix ===
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    for (int i = 0; i < E; i++) {
        int u = edgeList[i].u;
        int v = edgeList[i].v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // untuk graf tak berarah
    }

    // === Adjacency List ===
    GraphList graph;
    for (int i = 0; i < V; i++) graph.head[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u = edgeList[i].u;
        int v = edgeList[i].v;

        Node* nodeV = createNode(v);
        nodeV->next = graph.head[u];
        graph.head[u] = nodeV;

        Node* nodeU = createNode(u);
        nodeU->next = graph.head[v];
        graph.head[v] = nodeU;
    }

    // === Output ===
    printEdgeList(edgeList, E);
    printAdjMatrix(adjMatrix, V);
    printAdjList(&graph, V);

    return 0;
}
