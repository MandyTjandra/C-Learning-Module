#include <stdio.h>

int main (){
    float nilai;

    printf("Masukan nilai murid: ");
    scanf("%f", &nilai);

    printf(nilai <= 75 ? "Remedial\n" : "Lulus\n");
    return 0;
}