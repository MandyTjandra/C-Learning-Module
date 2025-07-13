#include <stdio.h>

int main(){

    int pin;

    printf("Masukan 5 digit pin: ");
    scanf("%d", &pin);

    if (pin != 12345) {
        printf("Pin yang dimasukan salah.");
    } else {
        printf("Pin benar."); 
    }
    
    return 0;
}

