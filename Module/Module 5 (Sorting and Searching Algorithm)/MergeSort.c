#include <stdio.h>

// Function to merge two subarrays into a sorted array
void merge(int arr[], int left, int mid, int right) {
   int n1 = mid - left + 1; // Size of the first subarray
   int n2 = right - mid;    // Size of the second subarray

   int L[n1], R[n2]; // Temporary arrays to hold the two subarrays

   // Copy data to temporary arrays
   for (int i = 0; i < n1; i++) {
      L[i] = arr[left + i];
   }
   for (int j = 0; j < n2; j++) {
      R[j] = arr[mid + 1 + j];
   }

   // Merge the temporary arrays back into the original array
   int i = 0, j = 0, k = left;
   while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
         arr[k] = L[i];
         i++;
      } else {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   // Copy any remaining elements of L[], if any
   while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
   }

   // Copy any remaining elements of R[], if any
   while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
   }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
   if (left < right) {
      int mid = left + (right - left) / 2; // Find the middle point to divide the array

      // Recursively sort the first and second halves
      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);

      // Merge the sorted halves
      merge(arr, left, mid, right);
   }
}

// Function to print an array
void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]); // Print each element followed by a space
   }
   printf("\n"); // Print a newline after the array
}

// Main function to demonstrate merge sort
int main() {
   int arr[] = {12, 11, 13, 5, 6, 7}; // Sample array
   int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

   printf("Original array: ");
   printArray(arr, n); // Print the original array

   mergeSort(arr, 0, n - 1); // Sort the array using merge sort

   printf("Sorted array: ");
   printArray(arr, n); // Print the sorted array

   return 0; // Return 0 to indicate successful execution
}
