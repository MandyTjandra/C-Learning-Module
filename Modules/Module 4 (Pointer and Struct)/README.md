# Module 4: Pointers and Structures in C

This module introduces advanced memory management using **Pointers** and custom data types using **Structures (Structs)**. Below are the source codes and detailed explanations for each concept.

---

## 1. Pointer Fundamentals

### A. The Address-Of Operator (`OperatorAddressOf.c`)
Before understanding pointers, you must understand how to find where a variable is stored in memory.

```c
#include <stdio.h>

int main(){
    int var = 5;

    printf("%d\n", var);  // Prints the VALUE (5)
    printf("%p\n", &var); // Prints the MEMORY ADDRESS (e.g., 0061FF1C)

    return 0;
}

```

**💡 Code Explanation:**

1. **`var`**: Refers to the data stored (the number 5).
2. **`&var`**: Refers to the location in RAM where that number is saved.
3. **`%p`**: The format specifier used to print addresses in hexadecimal format.

### B. Declaring & Dereferencing (`PengenalanPointer.c`)

How to create a pointer and use it to modify values indirectly.

```c
#include <stdio.h>

int main() {
    int a = 10;      
    int *ptr = &a;   // Pointer 'ptr' holds the address of 'a'

    // Accessing value via pointer (Dereferencing)
    printf("Nilai yang ditunjuk oleh ptr: %d\n", *ptr);

    // Modifying 'a' remotely through the pointer
    *ptr = 20;
    printf("Nilai a setelah diubah melalui pointer: %d\n", a);

    return 0;
}

```

**💡 Code Explanation:**

1. **`int *ptr`**: Declares a variable that will store an address.
2. **`ptr = &a`**: Links the pointer to the variable `a`.
3. **`*ptr` (Dereference)**: The star operator here means "Go to the address stored in `ptr` and get/change the value there." Changing `*ptr` changes `a`.

### C. Double Pointers (`DoublePointer.c`)

A pointer can also point to another pointer.

```c
#include <stdio.h>

int main(void)
{
    int var = 23;
    int *ptr = &var;
    int **dbPtr = &ptr; // Pointer to a Pointer

    printf("%d\n", *ptr);    // Prints 23
    printf("%d\n", **dbPtr); // Prints 23
    
    return 0;
}

```

**💡 Code Explanation:**

1. **Level 1 (`*ptr`)**: Points to the integer `var`.
2. **Level 2 (`**dbPtr`)**: Points to the pointer `ptr`.
3. **Logic:** `dbPtr` holds the address of `ptr`, which holds the address of `var`. Using `**` follows the chain all the way to the value.

---

## 2. Pointers & Arrays

### A. Pointer Arithmetic (`PointerDanArray.c`)

Demonstrates that arrays are essentially pointers to the first element.

```c
#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i;
    int *ptr = arr; // Array name 'arr' acts as a pointer

    for (i = 0; i < 5; ++i) {
        printf("Iterasi ke-%d: %d \n", i, *(ptr+i));
    }
    return 0;
}

```

**💡 Code Explanation:**

1. **`ptr = arr`**: Valid because the name `arr` is a reference to `&arr[0]`.
2. **`*(ptr+i)`**: This is pointer arithmetic. It moves the pointer forward by `i` steps (integers) and reads the value. It is exactly the same as writing `arr[i]`.

---

## 3. Function Parameters

### A. Pass by Value (`PassByValue.c`)

The standard way functions work: data is copied.

```c
void change(int a, int b){
    a = a + 5; // Only changes the local copy
    b = b + 5;
}

int main(){
    int x = 10, y = 6;
    change(x, y);
    printf("%d %d\n", x, y); // Output remains: 10 6
    return 0;
}

```

**💡 Code Explanation:**

1. **Behavior:** The function receives a **copy** of `x` and `y`.
2. **Result:** Changes inside `change()` do not affect the original variables in `main()`.

### B. Pass by Address (`PassbyAddress.c`)

Using pointers to modify the original variables.

```c
void change(int *a, int *b){
    *a = *a + 5; // Modifies the value at the specific address
    *b = *b + 5;
}

int main(){
    int x = 10, y = 6;
    change(&x, &y); // Sends the addresses, not the values
    printf("%d %d\n", x, y); // Output becomes: 15 11
    return 0;
}

```

**💡 Code Explanation:**

1. **Input:** The function accepts pointers (`int *a`).
2. **Call:** We send the addresses using `&x` and `&y`.
3. **Result:** The function modifies the memory where `x` and `y` live, so the changes persist outside the function.

---

## 4. Structures (Structs)

### A. Defining a Struct (`Struct.c`)

Grouping different data types into a single object (e.g., a Student).

```c
#include <stdio.h>
#include <string.h>

struct Mahasiswa{
    char nama[100];
    char nrp[20];
    int umur;
    double ipk;
};

int main(void){
    struct Mahasiswa mhs1;

    strcpy(mhs1.nama, "Ahmad");
    mhs1.ipk = 3.94;

    printf("Nama\t: %s\n", mhs1.nama);
    printf("IPK\t: %.2lf\n", mhs1.ipk);
    
    return 0;
}

```

**💡 Code Explanation:**

1. **`struct Mahasiswa`**: Defines a blueprint containing a String (name), String (ID), Integer (age), and Double (GPA).
2. **`mhs1`**: Creates an instance (a variable) based on that blueprint.
3. **Dot Operator (`.`):** Used to access specific fields (e.g., `mhs1.ipk`).

### B. Array of Structures (`ArrayOfStruct.c`)

Creating a list of objects.

```c
#include <stdio.h>

struct Point{
    int x, y;
};

int main(){
    struct Point arr[3]; // An array of 3 Points
    
    // Setting values for the first point
    arr[0].x = 2; 
    arr[0].y = 3;

    // Setting values for the second point
    arr[1].x = 5; 
    arr[1].y = 3;

    printf("%d %d\n", arr[0].x, arr[0].y);
    
    return 0;
}

```

**💡 Code Explanation:**

1. **`struct Point arr[3]`**: Creates 3 separate boxes (`arr[0]`, `arr[1]`, `arr[2]`).
2. **Access:** Each box has its own `x` and `y`. You access them by combining the array index and the dot operator: `arr[index].variable`.
