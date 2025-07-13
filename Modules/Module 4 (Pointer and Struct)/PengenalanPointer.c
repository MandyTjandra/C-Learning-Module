    #include <stdio.h>

    int main() {
        int a = 10;      // Deklarasi variabel integer
        int *ptr = &a;   // Pointer yang menunjuk ke alamat variabel a

        // Menampilkan nilai dan alamat dari variabel a
        printf("Nilai dari a: %d\n", a);
        printf("Alamat dari a: %p\n", &a);

        // Menampilkan ukuran nilai dan pointer a
        printf("Ukuran dari nilai a adalah %d\n", sizeof(a));
        printf("Ukuran dari pointer a adalah %d\n", sizeof(ptr));

        // Menampilkan nilai yang disimpan di pointer (alamat variabel a)
        printf("Pointer ptr menyimpan alamat: %p\n", ptr);

        // Mengakses nilai a menggunakan pointer
        printf("Nilai yang ditunjuk oleh ptr: %d\n", *ptr);

        // Mengubah nilai a melalui pointer
        *ptr = 20;
        printf("Nilai a setelah diubah melalui pointer: %d\n", a);

        return 0;
    }
