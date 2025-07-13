#include <stdio.h>

int main(){

    /*File Handling
    FILE *fptr;
    fptr = fopen(filename, mode);*/

    FILE *fptr;
    /*Create File*/
    fptr = fopen("filename.txt", "w");

    // Close the file
    fclose(fptr);

    /*Create Files in Specific Folder*/
    fptr = fopen("C:\\directoryname\\filename.txt", "w");

    
    return 0;
}