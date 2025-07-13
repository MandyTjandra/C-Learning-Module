#include <stdio.h>

// Fungsi untuk mencetak string
void cetak(char str[]) {
    printf("Pesan: %s\n", str);
}

// Fungsi untuk menghitung penjumlahan dua angka
void jumlah(int a, int b) {
    int hasil = a + b;
    printf("Hasil penjumlahan: %d\n", hasil);
}

int main() {
    // Memanggil fungsi cetak dengan parameter string
    cetak("Hello, dunia!");

    // Memanggil fungsi jumlah dengan dua angka sebagai parameter
    jumlah(5, 7);

    return 0;
}
