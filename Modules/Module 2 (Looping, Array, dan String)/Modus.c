#include <stdio.h>

int main() {
    int x, i, j, count, maxCount = 0, modus, modusCount = 0;
    int nonModusCount = 0;  // Variabel untuk menghitung jumlah elemen yang bukan modus

    printf("Masukkan jumlah input: ");
    scanf("%d", &x);

    int arr[x];

    // Input elemen ke dalam array
    for (i = 0; i < x; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Mencari modus
    for (i = 0; i < x; i++) {
        count = 0;
        for (j = 0; j < x; j++) {
            if (arr[i] == arr[j]) {
                count++;  // Menghitung kemunculan arr[i]
            }
        }
        // Memperbarui modus jika elemen ini muncul lebih sering
        if (count > maxCount) {
            maxCount = count;
            modus = arr[i];
            modusCount = 1;  // Reset count modus jika ada modus baru
        } else if (count == maxCount && arr[i] != modus) {
            modusCount++;  // Tambah jika ada modus lain yang jumlahnya sama
        }
    }

    // Cek jika ada lebih dari satu modus
    if (modusCount > 1) {
        printf("Invalid, modus ada 2.\n");
        return 0;
    }

    // Menghitung jumlah elemen yang bukan modus
    printf("Jumlah bilangan yang tidak modus ada ");
    for (i = 0; i < x; i++) {
        if (arr[i] != modus) {
            nonModusCount++;  // Tambah jika elemen bukan modus
        }
    }
    printf("%d, yaitu: ", nonModusCount);

    // Cetak elemen yang bukan modus
    for (i = 0; i < x; i++) {
        if (arr[i] != modus) {
            printf("%d ", arr[i]);  // Cetak nilai yang bukan modus
        }
    }

    // Cetak modus dan jumlah kemunculannya
    printf("\nModusnya adalah %d dengan jumlah kemunculan %d kali\n", modus, maxCount);

    return 0;
}
