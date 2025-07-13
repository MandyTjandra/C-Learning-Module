#include <stdio.h>

int main(){
    int numbers[10] = {1,2,3,4,5,6,7,8,9,10}, i;

    printf("%d bytes\n", sizeof(numbers)); 
    
    for(i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++){
        printf("Array ke-%d (%d)\n", i, numbers[i]);
    }
    return 0;
}