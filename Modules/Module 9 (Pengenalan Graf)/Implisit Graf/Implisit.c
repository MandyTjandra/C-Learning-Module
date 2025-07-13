/*Contoh Implementasi dalam C (DFS pada graf implisit 2D)*/
#include <stdio.h>

#define N 5
#define M 5

int visited[N][M];

// Cek apakah koordinat valid dan belum dikunjungi
int isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y]);
}

// Fungsi DFS implisit
void dfs(int x, int y) {
    if (!isValid(x, y)) return;

    visited[x][y] = 1;
    printf("Visited (%d, %d)\n", x, y);

    // Pindah ke atas, kanan, bawah, kiri
    dfs(x - 1, y); // atas
    dfs(x, y + 1); // kanan
    dfs(x + 1, y); // bawah
    dfs(x, y - 1); // kiri
}

int main() {
    // Inisialisasi semua belum dikunjungi
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;

    // Mulai DFS dari (0, 0)
    dfs(0, 0);

    return 0;
}
