#include <stdio.h>

void change(int a, int b){
    a = a + 5;
    b = b + 5;
}

int main(){
    int x = 10, y = 6;
    change(x, y);
    printf("%d %d\n", x, y);

    return 0;
}

/*Pass by Value berarti saat kita memasukkan (passing) 
argumen pada fungsi, nilai dari argumen tersebut akan disalin 
ke variabel yang berada pada parameter fungsi. Karena hanya 
nilainya saja yang diterima oleh fungsi, perubahan yang terjadi 
pada variabel parameter fungsi tidak akan berpengaruh terhadap 
variabel asalnya.*/