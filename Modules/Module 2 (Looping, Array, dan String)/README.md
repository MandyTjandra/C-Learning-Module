# Module 2: Looping, Arrays, and Strings in C

This module covers control flow (Loops), data collections (Arrays), and text handling (Strings). Below are the source codes and detailed explanations for each concept.

---

## 1. Looping Structures (Basics & Advanced)

### A. The While Loop (`While.c`)

A simple loop that keeps running as long as the condition is true. It is often used when the number of iterations is not known in advance.

```c
#include <stdio.h>

int main(){
    int i = 0;

    while (i < 10){
        printf("Aku ganteng (ke-%d)\n", i);
        i++;
    }

    return 0;
}

```

**💡 Code Explanation:**

* **Condition First:** The loop checks `i < 10` *before* running the code.
* **Logic:** Unlike the `for` loop, the initialization () happens outside, and the increment () must be written manually inside the block.
* **Output:** It prints the message 10 times (indexes 0 to 9).

### B. The Infinite Loop (`InfiniteLoop.c`)

A demonstration of a logical error where the loop never stops.

```c
#include <stdio.h>

int main(){
    int i;

    // Warning: This condition will always be true!
    for(i = 0; i < 10; i--){ 
        printf("INFINITE POWERRRR!!!!!!\n");
    }

    return 0;
}

```

**💡 Code Explanation:**

* **The Mistake:** The loop starts at 0 and checks if .
* **The Update:** Instead of increasing, `i--` decreases the value (0, -1, -2, ...).
* **Result:** Since negative numbers are always less than 10, the condition remains **True** forever, causing an infinite loop.

### C. Sequential Loops (`NestedLoop.c`)

Demonstrates how multiple loops interact. Although named "Nested," the specific logic in this file executes two loops one after another.

```c
#include <stdio.h>

int main(){
    int x, y; 
    
    // First Loop
    for(x = 0; x < 5; x++){
        printf("For pertama.\n");
    } 
    
    // Second Loop
    for(y = 0; y < 3; y++){
        printf("Ini namanya nested loop.\n");
        if(y == 2) printf("Genap!\n");
    }
    return 0;
}

```

**💡 Code Explanation:**

* **Flow:** The program runs the `x` loop 5 times completely. Once finished, it moves to the `y` loop.
* **Logic:** This shows that loops usually block the program from moving forward until they are finished.

---

## 2. Array Algorithms

### A. Dynamic Size Calculation (`SizeOfOperator.c`)

How to calculate the length of an array automatically without counting elements manually.

```c
#include <stdio.h>

int main(){
    int numbers[10] = {1,2,3,4,5,6,7,8,9,10}, i;

    printf("%d bytes\n", sizeof(numbers)); 
    
    // Calculating array length formula
    for(i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++){
        printf("Array ke-%d (%d)\n", i, numbers[i]);
    }
    return 0;
}

```

**💡 Code Explanation:**

* `sizeof(numbers)`: Returns total memory size of the array (e.g., ).
* `sizeof(numbers[0])`: Returns the size of a single item (4 bytes).
* **Formula:** . (). This allows the loop to adjust automatically if you add more numbers.

### B. Finding Min & Max (`MaxAndMin.c`)

A standard algorithm to find the largest and smallest numbers in a user-input list.

```c
#include <stdio.h>

int main() {
    int n, num, max, min;
    // ... (Input n code) ...
    
    // Initialize max/min with the first number
    printf("Enter number 1: ");
    scanf("%d", &num);
    max = min = num;  

    for (int i = 2; i <= n; i++) {
        scanf("%d", &num);
        if (num > max) max = num; // Update max if new number is bigger
        if (num < min) min = num; // Update min if new number is smaller
    }
    // ... (Print output) ...
    return 0;
}

```

**💡 Code Explanation:**

* **Initialization:** We assume the *first* number entered is both the Max and Min.
* **Comparison:** We check every subsequent number. If a number is bigger than the current `max`, it becomes the new `max`. Same logic applies to `min`.

### C. Reversing an Array (`ReverseArray.c`)

Logic to flip the order of elements (e.g., 1-2-3 becomes 3-2-1).

```c
// ... (Input Logic) ...
    for (int i = 0; i < x / 2; i++) {
        int temp = t[i];
        t[i] = t[x - i - 1];
        t[x - i - 1] = temp;
    }
// ...

```

**💡 Code Explanation:**

* **Swapping:** The loop runs only halfway ().
* **Logic:** It swaps the first element with the last, the second with the second-to-last, and so on.
* **Variable:** `temp` is used to temporarily hold a value so it isn't lost during the swap.

### D. Finding the Mode (`Modus.c`)

A complex algorithm to find the "Mode" (the number that appears most frequently).

```c
// ... (Code logic summary) ...
    for (i = 0; i < x; i++) {
        count = 0;
        for (j = 0; j < x; j++) {
            if (arr[i] == arr[j]) count++; 
        }
        if (count > maxCount) {
            maxCount = count;
            modus = arr[i];
        } 
        // ...
    }

```

**💡 Code Explanation:**

* **Nested Loops:** Compares every number (`arr[i]`) against every other number (`arr[j]`) to count occurrences.
* **Validation:** The code includes logic to detect if there are two modes (Invalid) and prints out numbers that are not the mode.

---

## 3. String Operations

### A. Basic String Printing (`String.c`)

Demonstrates the simplest way to print a string variable.

```c
#include <stdio.h>

int main () 
{  
    char str[] = "Halo"; 

    printf(str);

    return 0;
}

```

**💡 Code Explanation:**

* **Declaration:** `char str[]` automatically calculates the size based on the text "Halo" (5 bytes: 4 letters + 1 null terminator).
* **Printing:** `printf(str)` works here because `str` is treated as a format string. *Note: In advanced scenarios, it is safer to use `printf("%s", str)`.*

### B. Input with Scanf (`String2.c`)

Using scanf for strings inside an infinite loop.

```c
#include <stdio.h>

int main () {
  
    char arr[10];
    while(1) // Infinite Loop
    {
        scanf("%s", arr);
        printf("-- %s\n", arr);
    }
    return 0;
}

```

**💡 Code Explanation:**

* **`scanf` Behavior:** Unlike `fgets`, `scanf("%s", ...)` stops reading at the first space. If you type "Hello World", it only captures "Hello".
* **No `&`:** Notice we use `arr`, not `&arr`. Strings (arrays) are already pointers, so we don't need the `&` symbol.

### C. Basic String I/O (`InputOutputString.c`)

How to read strings containing spaces safely.

```c
#include <stdio.h>
int main() {
    char nama[100];
    printf("Masukkan nama Anda: ");
    fgets(nama, sizeof(nama), stdin); // Handles spaces
    printf("Halo %s!", nama);
    return 0;
}

```

**💡 Code Explanation:**

* **`scanf` vs `fgets`:** `scanf` usually stops reading at a space. `fgets` reads the entire line, allowing names like "John Doe".

### D. The Unsafe Function (`Gets.c`)

A demonstration of `gets()` and why it should **not** be used.

```c
    char arr[100];
    while(true) {
        gets(arr); // WARNING: Unsafe!
        printf("-- %s\n", arr);
    }

```

**💡 Code Explanation:**

* **The Risk:** `gets()` does not check the size of the input. If you type more than 100 characters, it will crash the program (Buffer Overflow).
* **Solution:** Always use `fgets` instead.

### E. String Length (`Strlen.c`)

Calculates how many characters are in a string.

```c
#include <stdio.h>
#include <string.h>

int main () {
  
    char a[] = "Halo";
    
    printf("Panjang string a adalah %d\n", strlen(a));
    
    return 0;
}

```

**💡 Code Explanation:**

* **Logic:** `strlen` counts characters until it hits the hidden null terminator (`\0`).
* **Result:** It returns 4 (H-a-l-o). It does not count the null terminator itself.

### F. String Copying (`Strcpy.c`)

In C, you cannot simply say `b = a` to copy a string. You must use `strcpy`.

```c
#include <stdio.h>
#include <string.h>

int main () {
  
    char a[] = "Halo";
    char b[10];
    
    // Copy string a into string b
    strcpy(b, a);
    
    printf("%s\n", b);
    
    return 0;
}

```

**💡 Code Explanation:**

* **The Function:** `strcpy(destination, source)`.
* **Important:** The destination (array `b`) must be large enough to hold the text from `a`. If `b` were size `[2]`, this code would cause a crash (overflow).

### G. Concatenation (`Strcat.c`)

Joining two strings together.

```c
#include <string.h>
int main() {
    char a[20] = "Halo";
    char b[] = " Kawan";
    strcpy(a, b);  // a becomes " Kawan"
    
    char c[20] = "Awalan";
    strcat(c, a);  // c becomes "Awalan Kawan"
    printf("%s\n", c); 
    return 0;
}

```

**💡 Code Explanation:**

* `strcpy(target, source)`: Replaces the content of the target with the source.
* `strcat(target, source)`: Appends (adds) the source to the end of the target string.

### H. Comparison (`Strcmp.c`)

Checking if two strings are identical.

```c
#include <string.h>
int main () {
    char a[] = "Halo";
    char b[] = "Hai";
    
    if(strcmp(a, b) == 0) printf("String a sama dengan b\n");
    else printf("String a tidak sama dengan b\n");
    return 0;
}

```

**💡 Code Explanation:**

* **The Rule:** You cannot use `if (a == b)` for strings in C.
* **The Function:** `strcmp` returns 0 if strings are exact matches. It returns a non-zero value if they are different.
