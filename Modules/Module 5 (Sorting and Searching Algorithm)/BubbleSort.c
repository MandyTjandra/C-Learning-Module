#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *xp, int *yp) {
   int temp = *xp;    // Store the value at xp in temp
   *xp = *yp;         // Copy the value at yp to xp
   *yp = temp;        // Copy the value from temp to yp
}

// Function to implement the optimized bubble sort algorithm
void bubbleSort(int arr[], int n) {
   int i, j, swapped; // `swapped` helps optimize the process by checking if any swaps occurred in an iteration

   // Outer loop iterates through the entire array
   for (i = 0; i < n - 1; i++) {
      swapped = 0; // Initialize swapped as 0 at the start of each pass

      // Inner loop compares adjacent elements
      for (j = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j + 1]) { // Check if the current element is greater than the next element
            swap(&arr[j], &arr[j + 1]); // Swap them if necessary
            swapped = 1; // Mark that a swap occurred
         }
      }

      // If no swaps occurred in the inner loop, the array is already sorted
      if (swapped == 0)
         break;
   }
}

// Function to print the elements of an array
void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]); // Print each element followed by a space
   }
   printf("\n"); // Print a newline after the array
}

// Main function to demonstrate bubble sort
int main() {
   int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Sample array
   int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

   printf("Original array: ");
   printArray(arr, n); // Print the original array

   bubbleSort(arr, n); // Sort the array using bubble sort

   printf("Sorted array: ");
   printArray(arr, n); // Print the sorted array

   return 0; // Return 0 to indicate successful execution
}
