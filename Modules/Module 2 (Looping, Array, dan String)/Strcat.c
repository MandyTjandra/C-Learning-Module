#include <stdio.h>
#include <string.h>

int main() {
    char a[20] = "Halo"; // Increase the size of a to avoid overflow
    char b[] = " Kawan";
    char c[20] = "Awalan";
    
    // Copy string b into string a
    strcpy(a, b); // a now holds " Kawan"
    
    // Append string a to the end of string c
    strcat(c, a); // c now holds "Awalan Kawan"
    
    printf("%s\n", c); // Output: Awalan Kawan
    
    return 0;
}
