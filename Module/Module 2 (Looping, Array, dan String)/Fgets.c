#include <stdio.h>
#include <string.h>

int main() {
    char arr[100];
    
    while (1) { // Infinite loop
        fgets(arr, sizeof(arr), stdin); // Safer alternative to gets()
        
        // Removing the newline character if present
        arr[strcspn(arr, "\n")] = 0;
        
        if (strcmp(arr, "exit") == 0) { // Exit condition
            break;
        }

        printf("-- %s\n", arr);
    }
    
    return 0;
}
