#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i;
    int *ptr = arr;

    for (i = 0; i < 5; ++i) {
        printf("&arr[%d] => %p\n", i, &arr[i]);
    }
    printf("Address of arr => %p\n", arr);

    for (i = 0; i < 5; ++i) {
        printf("Iterasi ke-%d: %d \n", i, *(ptr+i));
    }
    return 0;
}