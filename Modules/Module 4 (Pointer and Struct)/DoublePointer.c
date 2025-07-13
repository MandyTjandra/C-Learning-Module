#include <stdio.h>

int main(void)
{
    int var = 23;
    int *ptr = &var;
    int **dbPtr = &ptr; /* Pointer untuk pointer menambah jumlah *,
                        contoh: 1 pointer = *ptr
                                2 pointer = **dbPtr
                                3 pointer = ***trPtr
                                dst, */

    printf("%d\n", *ptr);
    printf("%d\n", **dbPtr);
    
    return 0;
}