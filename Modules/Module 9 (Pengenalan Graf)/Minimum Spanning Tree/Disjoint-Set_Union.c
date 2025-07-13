#include <stdio.h>

#define MAX 100

int parent[MAX];
int rank[MAX];

// Inisialisasi setiap elemen sebagai set sendiri
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Temukan root dengan path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Gabungkan dua set dengan union by rank
void unionSet(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot == yRoot)
        return;

    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

// Contoh penggunaan
int main() {
    int n = 5;  // jumlah elemen (0,1,2,3,4)

    makeSet(n);

    unionSet(0, 1);
    unionSet(1, 2);
    unionSet(3, 4);

    // Periksa apakah 0 dan 2 berada di set yang sama
    if (find(0) == find(2))
        printf("0 dan 2 berada dalam satu set.\n");
    else
        printf("0 dan 2 berada dalam set yang berbeda.\n");

    // Periksa apakah 0 dan 3 berada di set yang sama
    if (find(0) == find(3))
        printf("0 dan 3 berada dalam satu set.\n");
    else
        printf("0 dan 3 berada dalam set yang berbeda.\n");

    return 0;
}
