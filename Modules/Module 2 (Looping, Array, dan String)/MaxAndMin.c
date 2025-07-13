#include <stdio.h>

int main() {
    int n, num, max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("Number of elements must be larger than 0.\n");
        return 1;
    }

    printf("Enter number 1: ");
    scanf("%d", &num);
    max = min = num;  

    for (int i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    printf("Maximum number is: %d\n", max);
    printf("Minimum number is: %d\n", min);

    return 0;
}
