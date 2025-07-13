#include <stdio.h>

int main() {
    char nama[100];  // Membuat array untuk menyimpan nama

    // Meminta input nama dari pengguna
    printf("Masukkan nama Anda: ");
    fgets(nama, sizeof(nama), stdin);  // Menggunakan fgets agar bisa menangani spasi

    // Menampilkan kembali nama yang dimasukkan
    printf("Halo %s!", nama);

    return 0;
}
