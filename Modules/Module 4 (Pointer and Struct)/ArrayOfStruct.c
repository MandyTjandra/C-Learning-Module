#include <stdio.h>

struct Point{
    int x, y;
};

int main(){
    struct Point arr[3];
    arr[0].x = 2, arr[0].y = 3;
    arr[1].x = 5, arr[1].y = 3;
    arr[2].x = 2, arr[2].y = 8;

    printf("%d %d\n", arr[0].x, arr[0].y);
    printf("%d %d\n", arr[1].x, arr[1].y);
    printf("%d %d\n", arr[2].x, arr[2].y);
    
    return 0;
}