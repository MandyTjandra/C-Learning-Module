# Module 1: Conditional Statements in C

This module introduces decision-making and control-flow branching in the C programming language. You will learn to use `if`, `else`, `else if`, ternary operators, and `switch-case` statements.

---

## 🎯 Learning Objectives

By the end of this module, students and learners will be able to:
- Direct program flow using `if`, `else if`, and `else` conditional structures.
- Evaluate relational conditions (`==`, `!=`, `<`, `>`, `<=`, `>=`).
- Pass memory addresses to `scanf("%d", &var)` for reading console inputs.
- Implement discrete jump-table selections using `switch`, `case`, `break`, and `default`.
- Write concise inline conditional expressions using the ternary operator `? :`.

---

## 1. Simple Decision (`If.c`)

The basic `if` statement executes the guarded block only when the condition evaluates to non-zero (true).

```c
#include <stdio.h>

int main(){
    int balon = 4;
    if (balon < 5){
        printf("Balonku ku pegang erat-erat.\n");
    }
    return 0;
}
```

**💡 Code Explanation:**
1. **Condition:** `if (balon < 5)` evaluates whether `balon` is strictly less than 5.
2. **Execution:** Since 4 is less than 5, the condition evaluates to true (1) and executes the block.

---

## 2. Binary Choice (`IfElse.c`)

An `if-else` block provides two alternative pathways:

```c
#include <stdio.h>

int main(){
    int pin;

    printf("Masukan 5 digit pin: ");
    scanf("%d", &pin);

    if (pin != 12345) {
        printf("Pin yang dimasukan salah.\n");
    } else {
        printf("Pin benar.\n"); 
    }
    
    return 0;
}
```

**💡 Code Explanation:**
1. **`scanf("%d", &pin)`**: Reads an integer from `stdin` and writes it to the address `&pin`.
2. **`pin != 12345`**: Inequality operator. If true, the first branch executes; otherwise, the `else` branch executes.

---

## 3. Multiple Conditions (`IfElseIf.c`)

When multiple mutually exclusive conditions exist, use the `else if` ladder:

```c
#include <stdio.h>

int main(){
    int x;

    printf("Masukan perintah (1/0): ");
    scanf("%d", &x);

    if (x == 1){
        printf("Lampu menyala.\n");
    } else if (x == 0){
        printf("Lampu mati.\n");
    } else {
        printf("Perintah tidak dikenal.\n");
    }

    return 0;
}
```

---

## 4. Menu Selection (`SwitchCase.c`)

The `switch` statement matches a single integral expression against multiple `case` labels:

```c
#include <stdio.h>

int main()
{
    char platNomor;
    printf("Masukkan huruf awal plat nomor Anda: ");
    scanf(" %c", &platNomor);

    switch(platNomor)
    {
        case 'L':
            printf("Plat nomor Surabaya\n");
            break;
        case 'B':
            printf("Plat nomor Jakarta\n");
            break;
        case 'D':
            printf("Plat nomor Bandung\n");
            break;
        case 'N':
            printf("Plat nomor Malang/Lumajang\n");
            break;
        default:
            printf("Karakter plat nomor tidak diketahui\n");
    } 
    return 0;
}
```

**💡 Code Explanation:**
1. **`break;`**: Stops execution from falling through into the subsequent case.
2. **`default:`**: Executed when no case matches the input character.

---

## 5. Ternary Operator (`OperatorKondisional.c`)

A concise inline replacement for simple two-way branching:

```c
#include <stdio.h>

int main (){
    float nilai;

    printf("Masukan nilai murid: ");
    scanf("%f", &nilai);

    printf("%s\n", (nilai <= 75 ? "Remedial" : "Lulus"));
    return 0;
}
```

---

## ⚠️ Common Pitfalls & Tips

1. **Forgetting `&` in `scanf`:**
   Passing `scanf("%d", x)` instead of `scanf("%d", &x)` passes the *value* of `x` as a memory address, causing immediate segmentation fault (`SIGSEGV`).
2. **Assignment (`=`) in Conditions:**
   Writing `if (x = 5)` assigns 5 to `x` and always evaluates to true. Always use equality: `if (x == 5)`.
3. **Missing `break` in `switch` (Fall-Through):**
   In C, omitting `break` causes execution to continue running through all subsequent cases until a `break` or the end of the block is reached.

---

## 🧪 Hands-On Practice Challenges

- 🟢 **Challenge 1 (Even or Odd Parity)**:
  Prompt the user for an integer. Use `%` and an `if-else` statement to print whether it is even or odd.
- 🟡 **Challenge 2 (Four-Function Menu Calculator)**:
  Prompt the user to enter two numbers and an arithmetic operator character (`+`, `-`, `*`, `/`). Compute and print the result using a `switch` statement, displaying an error on division by zero.
- 🔴 **Challenge 3 (Leap Year Validator)**:
  Prompt for a year integer. Print `"Leap Year"` if divisible by 4 and not 100, or if divisible by 400; otherwise print `"Common Year"`.
