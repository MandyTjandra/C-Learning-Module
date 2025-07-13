#include <stdio.h>

void change(int *a, int *b){
    *a = *a + 5;
    *b = *b + 5;
}

int main(){
    int x = 10, y = 6;
    change(&x, &y);
    printf("%d %d\n", x, y);

    return 0;
}

/*Berbeda dengan sebelumnya, sesuai namanya, metode Pass 
by Address berarti argumen yang dimasukkan (passing) ke 
parameter fungsi adalah alamat memori variabel. Segala 
perubahan yang terjadi pada variabel tersebut, juga mempengaruhi 
langsung ke variabel asalnya. Hal ini terjadi karena argumennya 
adalah langsung berupa alamat memorinya.*/