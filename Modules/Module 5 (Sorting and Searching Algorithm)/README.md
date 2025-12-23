# Module 5: Sorting and Searching Algorithms

This module moves beyond basic syntax into **Computer Science Algorithms**. You will learn how to organize data (Sorting) and how to find specific data efficiently (Searching).

---

## 1. Searching Algorithms

### A. Linear Search (`LinearSearch.c`)
The simplest search method. It checks every element one by one until it finds a match.

```c
int linearSearch(int arr[], int n, int item) {
   for (int i = 0; i < n; ++i) {
      if (item == arr[i])
         return i; // Found: Return the index
   }
   return -1; // Not Found
}

```

**💡 Code Explanation:**

1. **Logic:** It iterates from index `0` to `n-1`.
2. **Performance:** If the array has 1 million items and your target is at the end, it takes 1 million steps (). It works on both sorted and unsorted arrays.

### B. Binary Search on Answer (`BinarySearch.c`)

Usually, Binary Search finds an item in a sorted array. However, this example demonstrates **Binary Search on Answer**—a technique to find the optimal *value* that satisfies a mathematical condition.

```c
// Function to check if 'k' works
bool f(int k, int a, int b, int n) {
   return ((k / a) * (b / a) >= n);
}

int binser(int a, int b, int n) {
   int l = 1, r = 100000;     
   while (r - l > 1) { 
      int mid = (l + r) / 2; 
      if (f(mid, a, b, n)) r = mid; // Try smaller k
      else l = mid + 1;             // Need larger k
   }
   // ...
}

```

**💡 Code Explanation:**

1. **The Goal:** Find the smallest number `k` such that a formula `(k/a) * (b/a) >= n` is true.
2. **The Logic:** Instead of checking every number from 1 to 100,000, we check the middle (`mid`).
* If `mid` works, we try to find a smaller answer in the left half.
* If `mid` doesn't work, we search the right half.


3. **Efficiency:** This reduces 100,000 checks to just ~17 checks ().

---

## 2. Basic Sorting Algorithms

### A. Bubble Sort (`BubbleSort.c`)

Repeatedly swaps adjacent elements if they are in the wrong order. The largest values "bubble" to the top.

```c
void bubbleSort(int arr[], int n) {
   int i, j, swapped;
   for (i = 0; i < n - 1; i++) {
      swapped = 0; 
      for (j = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            swap(&arr[j], &arr[j + 1]); // Swap using pointers
            swapped = 1;
         }
      }
      if (swapped == 0) break; // Optimization
   }
}

```

**💡 Code Explanation:**

1. **Nested Loops:** The inner loop compares neighbors `arr[j]` and `arr[j+1]`.
2. **Optimization:** The variable `swapped` checks if the array is already sorted. If no swaps happen in a full pass, the loop breaks early to save time.

### B. Insertion Sort (`InsertionSort.c`)

Builds the sorted array one item at a time, similar to how you sort playing cards in your hand.

```c
void insertionSort(int arr[], int n) {
   for (i = 1; i < n; i++) {
      key = arr[i];   // The card we picked up
      j = i - 1;      

      // Shift elements greater than key to the right
      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key; // Place the card in the empty spot
   }
}

```

**💡 Code Explanation:**

1. **The Key:** We pick the value at `arr[i]` and store it in `key`.
2. **Shifting:** We compare `key` with values to its left (`arr[j]`). If `arr[j]` is bigger, we shift it to the right to make space.
3. **Insertion:** Once we find a value smaller than `key`, we insert `key` after it.

---

## 3. Advanced Sorting (Divide & Conquer)

### A. Merge Sort (`MergeSort.c`)

A recursive algorithm that splits the array in half, sorts each half, and then merges them back together.

```c
void merge(int arr[], int left, int mid, int right) {
    // Logic to merge two temporary arrays L[] and R[]
    // ... (Code omitted for brevity, see source)
}

void mergeSort(int arr[], int left, int right) {
   if (left < right) {
      int mid = left + (right - left) / 2;

      mergeSort(arr, left, mid);      // Sort Left Half
      mergeSort(arr, mid + 1, right); // Sort Right Half

      merge(arr, left, mid, right);   // Combine them
   }
}

```

**💡 Code Explanation:**

1. **Divide:** The array is cut into halves recursively until only 1 element remains.
2. **Conquer:** The `merge` function takes two sorted subarrays (e.g., `[2, 5]` and `[1, 4]`) and combines them into one sorted array (`[1, 2, 4, 5]`).
3. **Stability:** Merge sort is very efficient () and reliable for large datasets.

### B. Quick Sort (`QuickSort.c`)

Selects a "Pivot" element and partitions the array so that smaller elements are on the left and larger ones are on the right.

```c
int partition(int arr[], int left, int right) {
   int pivot = arr[left]; // Pivot is the first element
   int storeIndex = left + 1;

   for (int i = left + 1; i <= right; i++) {
      if (arr[i] < pivot) {
         // Swap smaller element to the left side
         int temp = arr[i];
         arr[i] = arr[storeIndex];
         arr[storeIndex] = temp;
         storeIndex++;
      }
   }
   // Swap pivot to its correct position
   // ...
   return storeIndex - 1;
}

```

**💡 Code Explanation:**

1. **The Pivot:** We choose `arr[left]` as the reference point.
2. **Partitioning:** We iterate through the list. If a number is smaller than the pivot, we throw it to the "left" side (using `storeIndex`).
3. **Recursion:** After placing the pivot in its exact final spot, we recursively QuickSort the left subarray and the right subarray.
