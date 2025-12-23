# Module 1: Conditional Statements in C

This module introduces decision-making structures in C programming. Below are the source codes and detailed explanations for each concept.

---

## 1. Simple Decision (`If.c`)
This example demonstrates the basic `if` statement. The code inside the block executes only when the condition is true.

```c
#include <stdio.h>

int main(){
    int balon = 0;
    balon = 4;
    if (balon < 5){
        printf("Balonku ku pegang erat-erat.");
    }

    return 0;
}

```

### 💡 Code Explanation

1. **Variable Setup:** We define an integer `balon` and set it to `4`.
2. **The Condition:** The line `if (balon < 5)` checks if the value is less than 5.
3. **Execution:** Since 4 is indeed less than 5, the condition is **TRUE**, and the program prints *"Balonku ku pegang erat-erat."*
4. **Note:** If `balon` were 6, the program would skip the `printf` and do nothing.

---

## 2. Binary Choice (`IfElse.c`)

This example uses `if-else` to handle a "True vs False" scenario, simulating a PIN verification.

```c
#include <stdio.h>

int main(){

    int pin;

    printf("Masukan 5 digit pin: ");
    scanf("%d", &pin);

    if (pin != 12345) {
        printf("Pin yang dimasukan salah.");
    } else {
        printf("Pin benar."); 
    }
    
    return 0;
}

```

### 💡 Code Explanation

1. **Input:** The user enters a PIN number.
2. **Comparison:** The condition `if (pin != 12345)` checks if the input is **NOT equal** to the stored PIN.
3. **True Block:** If the input is wrong (e.g., 11111), it prints *"Pin yang dimasukan salah."*
4. **Else Block:** If the condition is false (meaning the input *is* 12345), the program automatically jumps to the `else` block and prints *"Pin benar."*

---

## 3. Multiple Conditions (`IfElseIf.c`)

When there are more than two options, we use the `else if` ladder. This simulates a light switch.

```c
#include <stdio.h>

int main(){
    int x;

    printf("Masukan perintah (1/0): ");
    scanf("%d", &x);

    if (x == 1){
        printf("Lampu menyala.");
    } else if (x == 0){
        printf("Lamput mati.");
    } else 
        printf("Perintah tidak dikenal.");

    return 0;
}

```

### 💡 Code Explanation

1. **Sequential Checking:** The program checks conditions from top to bottom.
2. **First Check:** `if (x == 1)` checks if the light should be ON.
3. **Second Check:** `else if (x == 0)` checks if the light should be OFF.
4. **Fallback (`else`):** If the user types any other number (e.g., 99), neither condition is met, so it prints *"Perintah tidak dikenal"* (Unknown command).

---

## 4. Menu Selection (`SwitchCase.c`)

The `switch` statement is cleaner than multiple `if-else` blocks when checking a single variable against specific constants. This example identifies License Plates.

```c
#include <stdio.h>

int main()
{
    char platNomor;
    printf("Masukkan huruf awal plat nomor Anda: ");
    scanf("%c", &platNomor);

    switch(platNomor)
    {
        case 'L':
            printf("Plat nomor Surabaya");
            break;

        case 'B':
            printf("Plat nomor Jakarta");
            break;

        case 'D':
            printf("Plat nomor Bandung");
            break;

        case 'N':
            printf("Plat nomor Malang/Lumajang");
            break;

        default:
            printf("Karakter plat nomor tidak diketahui");
    } 
    return 0;
}

```

### 💡 Code Explanation

1. **Switching:** The command `switch(platNomor)` takes the character input and jumps to the matching `case`.
2. **Cases:** If input is 'L', it prints "Surabaya". If 'B', it prints "Jakarta", etc.
3. **The `break` Keyword:** This is crucial. It stops the code from running into the next case. Without `break`, inputting 'L' would print Surabaya AND Jakarta.
4. **Default:** This acts like the final `else`. If the input is 'Z', it prints *"Karakter plat nomor tidak diketahui"*.

---

## 5. Ternary Operator (`OperatorKondisional.c`)

A shorthand way to write a simple `if-else` in a single line.

```c
#include <stdio.h>

int main (){
    float nilai;

    printf("Masukan nilai murid: ");
    scanf("%f", &nilai);

    printf(nilai <= 75 ? "Remedial\n" : "Lulus\n");
    return 0;
}

```

### 💡 Code Explanation

1. **Syntax:** `(Condition) ? True_Value : False_Value`.
2. **The Logic:**
* It checks: Is `nilai <= 75`?
* **? (If True):** The result is the string `"Remedial\n"`.
* **:(If False):** The result is the string `"Lulus\n"`.
3. **Result:** The selected string is then passed directly to `printf`.
