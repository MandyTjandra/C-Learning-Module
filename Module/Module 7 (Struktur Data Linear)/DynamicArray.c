#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

// Fungsi untuk memeriksa apakah array kosong
int isEmpty(DynamicArray *arr) {
    return arr->size == 0;
}

// Fungsi untuk menambah elemen di belakang array
void pushBack(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;  // Meningkatkan kapasitas array
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

// Fungsi untuk menghapus elemen di belakang array
void popBack(DynamicArray *arr) {
    if (!isEmpty(arr)) {
        arr->size--;
    }
}

// Fungsi untuk mendapatkan elemen di belakang array
int back(DynamicArray *arr) {
    if (!isEmpty(arr)) {
        return arr->data[arr->size - 1];
    }
    return -1;  // Mengembalikan -1 jika array kosong
}

// Fungsi untuk mendapatkan elemen di depan array
int front(DynamicArray *arr) {
    if (!isEmpty(arr)) {
        return arr->data[0];
    }
    return -1;  // Mengembalikan -1 jika array kosong
}

// Fungsi untuk mengatur nilai elemen di indeks tertentu
void setAt(DynamicArray *arr, int index, int value) {
    if (index >= 0 && index < arr->size) {
        arr->data[index] = value;
    }
}

// Fungsi untuk mendapatkan elemen di indeks tertentu
int getAt(DynamicArray *arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->data[index];
    }
    return -1;  // Mengembalikan -1 jika indeks tidak valid
}

// Fungsi untuk menginisialisasi dynamic array
void initArray(DynamicArray *arr, int initialCapacity) {
    arr->size = 0;
    arr->capacity = initialCapacity;
    arr->data = (int *)malloc(arr->capacity * sizeof(int));
}

// Fungsi untuk membersihkan memori dynamic array
void freeArray(DynamicArray *arr) {
    free(arr->data);
}

int main() {
    DynamicArray arr;
    int x, y;

    printf("Masukan ukuran array yang diinginkan: ");
    scanf("%d", &x);
    initArray(&arr, x);

    for(int i = 0; i < x; i++){
        printf("Masukan isi array indeks ke-%d: ", i);
        scanf("%d", &y);
        pushBack(&arr, y);
    }

    printf("Front: %d\n", front(&arr));
    printf("Back: %d\n", back(&arr));
    printf("Element at index 2: %d\n", getAt(&arr, 2));

    setAt(&arr, 2, 100);
    printf("Element at index 2 after set: %d\n", getAt(&arr, 2));

    popBack(&arr);
    printf("Back after pop: %d\n", back(&arr));

    freeArray(&arr);
    return 0;
}
