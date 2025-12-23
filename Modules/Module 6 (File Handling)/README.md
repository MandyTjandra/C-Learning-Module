# Module 6: File Handling in C

So far, all variables used in our programs are lost when the program ends. **File Handling** allows us to save data permanently to a text file and read it back later.

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
