#include <stdio.h>

int main() {
    int x;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &x);

    int z[x], t[x];

    for (int i = 0; i < x; i++) {
        printf("Masukkan elemen ke-%d: ", i + 1);
        scanf("%d", &z[i]);
    }

    for (int i = 0; i < x; i++) {
        t[i] = z[i];
    }

    for (int i = 0; i < x / 2; i++) {
        int temp = t[i];
        t[i] = t[x - i - 1];
        t[x - i - 1] = temp;
    }

    printf("Isi array [%d]: ", x);
    for (int i = 0; i < x; i++) {
        printf("%d ", z[i]);
    }
    printf("\n");

    printf("Isi array dibalik [%d]: ", x);
    for (int i = 0; i < x; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}
