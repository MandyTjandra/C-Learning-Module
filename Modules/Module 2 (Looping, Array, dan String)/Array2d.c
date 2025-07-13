#include <stdio.h>

int main() {
    // Deklarasi array 2 dimensi dengan ukuran 3x3
    int matrix[5][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}
    };
    
    // Menampilkan isi array 2 dimensi
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
