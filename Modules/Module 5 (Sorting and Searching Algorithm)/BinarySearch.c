#include <stdio.h>
#include <stdbool.h>

// Function to check if a given k satisfies the condition
bool f(int k, int a, int b, int n) {
   return ((k / a) * (b / a) >= n);
}

// Binary search function to find the smallest k
int binser(int a, int b, int n) {
   int l = 1;          // Lower bound of the search range
   int r = 100000;     // Upper bound of the search range
   while (r - l > 1) { // While the range is greater than 1
      int mid = (l + r) / 2; // Calculate the middle value
      if (f(mid, a, b, n))   // Check if mid satisfies the condition
         r = mid;            // Narrow the range to [l, mid]
      else
         l = mid + 1;        // Narrow the range to [mid + 1, r]
   }

   // Final check for the smallest k
   if (f(l, a, b, n))
      return l;
   else
      return r;
}

// Main function to demonstrate the binary search
int main() {
   int a = 3, b = 6, n = 4; // Example input values

   int result = binser(a, b, n); // Find the smallest k
   printf("The smallest k satisfying the condition is: %d\n", result);

   return 0; // Successful execution
}
