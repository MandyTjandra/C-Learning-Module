#include <stdio.h>

// Function to implement insertion sort
void insertionSort(int arr[], int n) {
   int i, key, j; // `key` holds the current element, `i` is the outer loop counter, and `j` is for inner comparisons

   // Loop through the array starting from the second element
   for (i = 1; i < n; i++) {
      key = arr[i];   // Take the current element as the key
      j = i - 1;      // Start comparing with the previous elements

      // Move elements that are greater than the key one position ahead
      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      
      // Insert the key into its correct position
      arr[j + 1] = key;
   }
}

// Function to print an array
void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]); // Print each element followed by a space
   }
   printf("\n"); // Print a newline after the array
}

// Main function to demonstrate insertion sort
int main() {
   int arr[] = {12, 11, 13, 5, 6}; // Sample array
   int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

   printf("Original array: ");
   printArray(arr, n); // Print the original array

   insertionSort(arr, n); // Sort the array using insertion sort

   printf("Sorted array: ");
   printArray(arr, n); // Print the sorted array

   return 0; // Return 0 to indicate successful execution
}
