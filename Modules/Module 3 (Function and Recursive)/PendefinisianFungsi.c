#include <stdio.h>

void print(){
    printf("Aku suka fungsi!\n");
}

int angka(){
    int x, y, z;

    printf("Masukan 2 angka: ");
    scanf("%d %d", &x, &y);

    z = x + y;

    printf("Hasilnya adalah: %d", z);
    
    return 0;
}

int main(){
    print();
    angka();

    return 0;
}