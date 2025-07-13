#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int item) {
   // Iterate through the array
   for (int i = 0; i < n; ++i) {
      // Check if the current element matches the item
      if (item == arr[i])
         return i; // Return the index where the item is found
   }
   return -1; // Return -1 if the item is not found in the array
}

// Main function to demonstrate linear search
int main() {
   int arr[] = {10, 20, 30, 40, 50}; // Sample array
   int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
   int item = 30; // Item to search for

   printf("Array: ");
   for (int i = 0; i < n; ++i) {
      printf("%d ", arr[i]); // Print the array
   }
   printf("\n");

   // Perform linear search
   int result = linearSearch(arr, n, item);

   if (result != -1) {
      printf("Item %d found at index %d.\n", item, result); // Item found
   } else {
      printf("Item %d not found in the array.\n", item); // Item not found
   }

   return 0; // Return 0 to indicate successful execution
}
