#include <stdio.h>

int main()
{
    char platNomor;
    printf("Masukkan huruf awal plat nomor Anda: ");
    scanf("%c", &platNomor);

    switch(platNomor)
    {
        case 'L':
            printf("Plat nomor Surabaya");
            break;

        case 'B':
            printf("Plat nomor Jakarta");
            break;

        case 'D':
            printf("Plat nomor Bandung");
            break;

        case 'N':
            printf("Plat nomor Malang/Lumajang");
            break;

        default:
            printf("Karakter plat nomor tidak diketahui");
    } 
    return 0;
}