#include <stdio.h>

// Function to partition the array
int partition(int arr[], int left, int right) {
   int pivot = arr[left]; // Choose the first element as the pivot
   int storeIndex = left + 1; // Initialize the store index

   // Iterate through the array from left + 1 to right
   for (int i = left + 1; i <= right; i++) {
      if (arr[i] < pivot) { // If the current element is smaller than the pivot
         // Swap arr[i] and arr[storeIndex]
         int temp = arr[i];
         arr[i] = arr[storeIndex];
         arr[storeIndex] = temp;

         storeIndex++; // Increment the store index
      }
   }

   // Swap the pivot element with the element at storeIndex - 1
   int temp = arr[left];
   arr[left] = arr[storeIndex - 1];
   arr[storeIndex - 1] = temp;

   return storeIndex - 1; // Return the position of the pivot
}

// Function to implement quick sort
void quickSort(int arr[], int left, int right) {
   if (left < right) {
      // Partition the array and get the pivot index
      int pivotIndex = partition(arr, left, right);

      // Recursively sort the elements before and after the pivot
      quickSort(arr, left, pivotIndex - 1);
      quickSort(arr, pivotIndex + 1, right);
   }
}

// Function to print an array
void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]); // Print each element followed by a space
   }
   printf("\n"); // Print a newline after the array
}

// Main function to demonstrate quick sort
int main() {
   int arr[] = {10, 7, 8, 9, 1, 5}; // Sample array
   int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

   printf("Original array: ");
   printArray(arr, n); // Print the original array

   quickSort(arr, 0, n - 1); // Sort the array using quick sort

   printf("Sorted array: ");
   printArray(arr, n); // Print the sorted array

   return 0; // Return 0 to indicate successful execution
}
