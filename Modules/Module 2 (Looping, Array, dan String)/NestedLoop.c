#include <stdio.h>

int main(){
    int x, y; 
    
    for(x = 0; x < 5; x++){
        printf("For pertama.\n");
        } for(y = 0; y < 3; y++){
            printf("Ini namanya nested loop.\n");
                if(y == 2)
                printf("Genap!\n");
    }
    return 0;
}