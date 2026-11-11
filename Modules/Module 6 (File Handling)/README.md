# Module 6: File Handling in C

So far, all variables used in our programs are lost when the program ends. **File Handling** allows us to persist data permanently to secondary disk storage and read it back across program executions.

---

## 🎯 Learning Objectives

By the end of this module, students and learners will be able to:
- Declare and manage file stream pointers (`FILE *fptr`).
- Understand file access modes: write (`"w"`), read (`"r"`), and append (`"a"`).
- Validate file pointers against `NULL` to handle missing or inaccessible files gracefully.
- Read data sequentially line-by-line using `fgets()` until End-of-File (`EOF`).
- Write formatted text records to files using `fprintf()` and `fputs()`.
- Prevent resource and descriptor leaks by closing files with `fclose()`.

---

## 1. Creating and Opening Files (`CreateFiles.c`)
To work with files, we use a special pointer type called `FILE`.

```c
#include <stdio.h>

int main(){
    FILE *fptr;

    // 1. Create a file in the current directory
    // Mode "w" (Write) creates a new file. If it exists, it overwrites it.
    fptr = fopen("filename.txt", "w");

    // Always close the file when done to save changes
    fclose(fptr);

    // 2. Create a file in a specific folder (Windows absolute path example)
    // Note: Double backslashes "\\" are needed to escape the character
    fptr = fopen("C:\\directoryname\\filename.txt", "w");
    
    return 0;
}

```

**💡 Code Explanation:**

1. **`FILE *fptr`**: Declares a pointer that holds information about the file stream.
2. **`fopen(filename, mode)`**: Opens a file.
* **"w"**: Write mode. Creates the file if it doesn't exist.


3. **`fclose(fptr)`**: Crucial step. It saves the data from the buffer to the disk and releases the file.

---

## 2. Writing Content (`WriteToFiles.c`)

Once a file is open in write mode, we can output text to it just like we print to the screen.

```c
#include <stdio.h>

int main(){
   
    FILE *fptr; 
    fptr = fopen("filename.txt", "w");

    // Write text into the file instead of the console
    fprintf(fptr, "Some text");

    fclose(fptr);
    return 0; 
}

```

**💡 Code Explanation:**

1. **`fprintf(file_pointer, text)`**: Works exactly like `printf`, but the first argument specifies *where* to write (the file).
2. **Warning:** Since we used mode **"w"**, if `filename.txt` already had text, it would be completely wiped out and replaced with "Some text".

---

## 3. Appending Content (`AppendContent.c`)

To add data *without* deleting existing content, use Append mode.

```c
#include <stdio.h>

int main(){
    FILE *fptr;

    // Open in "a" (Append) mode
    fptr = fopen("filename.txt", "a");

    // This text is added to the end of the existing file
    fprintf(fptr, "\nHi everybody!");

    fclose(fptr);
    return 0;
}

```

**💡 Code Explanation:**

1. **Mode "a"**: Opens the file for writing but starts at the very end.
2. **`\n`**: Added at the start of the string to ensure the new text starts on a new line.

---

## 4. Reading Files (`ReadFiles.c`)

Reading text from a file into your program variables.

```c
#include <stdio.h>

int main(){
    FILE *fptr;

    // Open in "r" (Read) mode
    fptr = fopen("filename.txt", "r");

    // Buffer to store the text we read
    char myString[100];

    // Loop through the file line by line
    while(fgets(myString, 100, fptr)) {
        printf("%s", myString);
    }

    fclose(fptr);
    return 0;
}

```

**💡 Code Explanation:**

1. **Mode "r"**: Opens the file for reading only. If the file doesn't exist, `fopen` returns `NULL`.
2. **`fgets(buffer, size, pointer)`**: Reads one line of text from the file.
3. **`while(fgets(...))`**: The loop continues as long as `fgets` successfully reads a new line. When it reaches the End of File (EOF), it returns NULL and the loop stops.

---

## ⚠️ Common Pitfalls & Tips

1. **Forgetting to Check for `NULL`:**
   If `fopen()` fails (e.g. file not found or permissions denied), it returns `NULL`. Attempting to read from or write to a `NULL` pointer causes an immediate crash:
   ```c
   FILE *fptr = fopen("data.txt", "r");
   if (fptr == NULL) {
       perror("Error opening file");
       return 1;
   }
   ```
2. **The Destructive Nature of `"w"` Mode:**
   Opening a file with `"w"` mode immediately erases its existing contents. If you want to add content to an existing file without deleting it, use `"a"` (append) mode.
3. **Leaking File Descriptors:**
   Every open file consumes an operating system handle. Always balance every `fopen()` call with a matching `fclose()`.

---

## 🧪 Hands-On Practice Challenges

- 🟢 **Challenge 1 (File Line Counter)**:
  Write a program that opens a text file, reads it line by line with `fgets()`, and prints the total number of lines contained in the file.
- 🟡 **Challenge 2 (Simple Student Logger)**:
  Create a program that prompts the user for student records (Name and Score) and appends them to a file called `grades.txt` using `"a"` mode.
- 🔴 **Challenge 3 (File Copy Utility)**:
  Write a C program that takes a source file name and destination file name, reads the source file, and copies all its contents into the destination file.
