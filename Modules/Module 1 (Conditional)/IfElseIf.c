#include <stdio.h>

int main(){
    int x;

    printf("Masukan perintah (1/0): ");
    scanf("%d", &x);

    if (x == 1){
        printf("Lampu menyala.");
    } else if (x == 0){
        printf("Lamput mati.");
    } else 
        printf("Perintah tidak dikenal.");

    return 0;
}