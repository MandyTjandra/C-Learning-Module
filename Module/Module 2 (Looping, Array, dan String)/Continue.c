#include <stdio.h>

int main(){
    int i;

    for(i = 0; i < 8; i++){
        if(i == 4){
        continue;
    }
    printf("Lantai-%d\n", i);
    }
    return 0;
}