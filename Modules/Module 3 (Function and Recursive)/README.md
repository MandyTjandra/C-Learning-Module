# Module 3: Functions and Recursion in C

This module introduces **Modular Programming**. Instead of writing all logic in `main()`, you will learn how to break code into smaller, reusable blocks called **Functions**. We also cover **Recursion**, a technique where functions call themselves.

---

## 1. Function Basics

### A. Defining Functions (`PendefinisianFungsi.c`)
This example shows how to create simple functions and call them from the main program.

```c
#include <stdio.h>

// A void function returns nothing
void print(){
    printf("Aku suka fungsi!\n");
}

// An int function returns an integer
int angka(){
    int x, y, z;

    printf("Masukan 2 angka: ");
    scanf("%d %d", &x, &y);

    z = x + y;

    printf("Hasilnya adalah: %d", z);
    
    return 0; 
}

int main(){
    print(); // Calling the void function
    angka(); // Calling the int function

    return 0;
}

```

**💡 Code Explanation:**

1. **`void print()`:** This function performs an action (printing) but does not send any data back to the main program.
2. **`int angka()`:** This function is defined to return an integer (hence `int`), although in this specific example, it handles the printing internally.
3. **Calling:** In `main()`, we simply write the function name followed by parentheses `()` to execute them.

### B. Function Prototypes (`PrototypeFungsi.c`)

In C, the compiler reads code from top to bottom. If you want to put your function *below* `main`, you must declare it *above* `main` first.

```c
#include <stdio.h>

void cetak(); // PROTOTYPE: "I promise this function exists later"

int main(){
    cetak(); // Works because of the prototype above
    return 0;
}

// REAL DEFINITION
void cetak(){
    printf("Hello, World!");
}

```

**💡 Code Explanation:**

1. **The Problem:** If you remove the top line (`void cetak();`), the compiler will error because it doesn't know what `cetak` is when it sees it inside `main`.
2. **The Solution:** The **Prototype** acts as a header or a signature, telling the compiler what to expect.

---

## 2. Data Flow in Functions

### A. Parameters (`ParameterFungsi.c`)

Parameters allow you to pass data **into** a function so it can process different inputs.

```c
#include <stdio.h>

// Accepts a string (character array)
void cetak(char str[]) {
    printf("Pesan: %s\n", str);
}

// Accepts two integers
void jumlah(int a, int b) {
    int hasil = a + b;
    printf("Hasil penjumlahan: %d\n", hasil);
}

int main() {
    // Sending data into the functions
    cetak("Hello, dunia!");
    jumlah(5, 7);

    return 0;
}

```

**💡 Code Explanation:**

1. **`void cetak(char str[])`:** The variable `str` is a placeholder. Whatever text you put in the parentheses when calling the function becomes `str`.
2. **`jumlah(5, 7)`:** The number `5` is copied into `a`, and `7` is copied into `b`.

### B. Return Values (`FungsiReturn.c`)

The `return` keyword allows a function to send a result **back** to the place where it was called.

```c
#include <stdio.h>
 
int jumlah(int a, int b); // Prototype
 
int main()
{
    int x = 2, y = 3, hasil;
    
    // The function calculates, returns a value, and we store it in 'hasil'
    hasil = jumlah(x, y); 
    
    printf("%d\n", hasil);
    return 0;
}
 
int jumlah(int a, int b)
{
    int hasil = a;
    hasil += b;
    return hasil; // Sends the value back
}

```

**💡 Code Explanation:**

1. **`int jumlah`:** The `int` at the start means "This function will give you back an integer."
2. **Capturing the result:** In `main`, `hasil = jumlah(x, y)` takes the answer from the function and saves it.

---

## 3. Recursion

Recursion is when a function calls **itself**. It is a powerful concept often used in mathematics and algorithms.

### A. Infinite Recursion (`Rekursi.c`)

What happens if a function calls itself without stopping?

```c
#include <stdio.h>
 
void rekursi(int n)
{
    printf("%d\n", n);
    rekursi(n+1);       // Calls itself again... and again...
}

int main()
{
    rekursi(1);
    return 0;
}

```

**💡 Code Explanation:**

1. **The Logic:** `rekursi(1)` calls `rekursi(2)`, which calls `rekursi(3)`, etc.
2. **The Result:** This creates an **Infinite Loop**. Eventually, the program will crash because the computer runs out of memory (Stack Overflow).

### B. The Base Case (`BaseCase.c`)

To stop recursion, we need a condition to stop calling the function. This is called the **Base Case**.

```c
#include <stdio.h>
 
int power(int a, int m)
{
    if (m == 0) return 1;       // BASE CASE: Stop when power is 0
    return (a * power(a, m-1)); // RECURSIVE CASE: Keep going
}
 
int main()
{
    printf("%d\n", power(2,3)); // Calculate 2 to the power of 3
    return 0;
}

```

**💡 Code Explanation:**

1. **Goal:** Calculate .
2. **Flow:**
* 
* 
*  -> Hit Base Case! returns 1.
* Result: .



### C. Factorial Example (`Rekursi2.c`)

A classic math problem solved using recursion: .

```c
#include <stdio.h>

int fact(int n){
    if(n < 1){
        return 1; // Base case: 0! is 1
    } else{
        return n *=  fact(n-1); // Recursion
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", fact(n));
    
    return 0;
}

```

**💡 Code Explanation:**

1. **Logic:** If you input `4`:
* Calculates `4 * fact(3)`
* ... `3 * fact(2)`
* ... `2 * fact(1)`
* ... `1 * fact(0)` -> Returns 1.
2. **Syntax Note:** `n *= fact(n-1)` is a shorthand for `n = n * fact(n-1)`.
