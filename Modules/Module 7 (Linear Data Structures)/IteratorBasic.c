/* Iterator di C bukanlah fitur bawaan bahasa seperti di beberapa 
   bahasa pemrograman lain, tetapi konsep ini bisa diterapkan menggunakan 
   pointer atau indeks dalam struktur data yang dapat diiterasi, 
   seperti array, linked list, dan lain-lain. */
#include <stdio.h>

// Fungsi untuk menampilkan elemen array menggunakan pointer (sebagai iterator)
void printArray(int *arr, int size) {
    // Iterator (pointer) untuk mengakses elemen array
    for (int *it = arr; it < arr + size; ++it) {
        printf("%d ", *it);  // Menampilkan nilai yang ditunjuk oleh iterator
    }
    printf("\n");
}

// Fungsi untuk mencari elemen dalam array menggunakan pointer
int findElement(int *arr, int size, int target) {
    for (int *it = arr; it < arr + size; ++it) {
        if (*it == target) {
            return it - arr;  // Mengembalikan indeks elemen yang ditemukan
        }
    }
    return -1;  // Mengembalikan -1 jika elemen tidak ditemukan
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Elemen dalam array: ");
    printArray(arr, size);

    int target = 30;
    int index = findElement(arr, size, target);

    if (index != -1) {
        printf("Elemen %d ditemukan di indeks %d\n", target, index);
    } else {
        printf("Elemen %d tidak ditemukan dalam array\n", target);
    }

    return 0;
}
