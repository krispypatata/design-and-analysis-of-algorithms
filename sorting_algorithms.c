// Evangelista, Bill Jerson
// Gabinete, Keith Ginoel

#include "sorting_algorithms.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// ═════════════════════════════════════════════════════════════════════════════════════
// Helper function for swapping elements
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// ═════════════════════════════════════════════════════════════════════════════════════
// Comparison function for the built-in qsort
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

// ═════════════════════════════════════════════════════════════════════════════════════
// SORTING ALGORITHMS
// ═════════════════════════════════════════════════════════════════════════════════════
// Function implementation of the bubble sort algorithm
void bsort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}


// ═════════════════════════════════════════════════════════════════════════════════════
// Function implementation of the selection sort algorithm
// reference: https://www.geeksforgeeks.org/selection-sort-algorithm-2/
void selsort(int a[], int n) {
    int i, j, index_of_min;

    for (i = 0; i < n - 1; i++) {
        // find the index with the minimum value
        index_of_min = i;

        for (j = i + 1; j < n; j++) {
            if (a[index_of_min] > a[j]) {
                index_of_min = j;
            }
        }

        // swap elements
        swap(&a[i], &a[index_of_min]);
    }
}

// ═════════════════════════════════════════════════════════════════════════════════════
// Function implementation of the shell sort algorithm
// Lab's implementation
void shsort(int a[], int n){
  int i,j,d;

  for(d=n/2;d>0;d/=2)
  for(i=d;i<n;i++)
    for(j=i;j>d-1;j-=d)
      if(a[j]<a[j-d])
	swap(&a[j],&a[j-d]);
      else
	break;
}


// ═════════════════════════════════════════════════════════════════════════════════════
// Function implementation of the insertion sort algorithm
void isort(int a[], int n) {
    int i, j;

    for (i = 1; i < n; i++) {
        for (j = i; j > 0; j--) {
            if (a[j - 1] > a[j]) {
                swap( &a[j - 1], &a[j]);
            }
            else break;
        }
    }
}


// ═════════════════════════════════════════════════════════════════════════════════════
// Function implementation of the merge sort algorithm
void merge(int a[], int n)
{
    int i, j, k, mid = n / 2, temp[n];

    for (i = 0, j = mid, k = 0; k < n; k++) {
        temp[k] = (i < mid && (j >= n || a[i] <= a[j])) ? a[i++] : a[j++];
    }
        

    memcpy(a, temp, n * sizeof(int)); // copy a back to temp

} // end of merge

// ─────────────────────────────────────────────────────────────────────────────────────
void msort(int a[], int n)
{
    if (n > 1)
    {
        msort(a, n / 2);
        msort(&a[n / 2], n - n / 2);
        merge(a, n);
    }
} // end of msort


// ═════════════════════════════════════════════════════════════════════════════════════
// Function implementation of the heap sort algorithm
// reference: https://www.geeksforgeeks.org/heap-sort/
// To heapify a subtree rooted with node i
// which is an index in arr[].
void heapify(int a[], int n, int i) {
    // Initialize largest as root
    int largest = i; 

    // left index = 2*i + 1
    int l = 2 * i + 1; 

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(&a[i], &a[largest]);

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

// ─────────────────────────────────────────────────────────────────────────────────────
// Main function to do heap sort
void hsort(int a[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&a[0], &a[i]);

        // Call max heapify on the reduced heap
        heapify(a, i, 0);
    }
} // end of hsort


// ═════════════════════════════════════════════════════════════════════════════════════
// Partition function using median-of-three pivot selection
int partition(int a[], int low, int high) {
    // Choose median of three pivot
    int mid = low + (high - low) / 2;
    if (a[mid] < a[low])
        swap(&a[mid], &a[low]);
    if (a[high] < a[low])
        swap(&a[high], &a[low]);
    if (a[high] < a[mid])
        swap(&a[high], &a[mid]);
    
    int pivot = a[mid];
    swap(&a[mid], &a[high]);

    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high-1] and move all smaller
    // elements to the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(&a[i + 1], &a[high]);
    return i + 1;
}


// ─────────────────────────────────────────────────────────────────────────────────────
// Main function to do quick sort
void quick_sort(int a[], int low, int high) {
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(a, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
} // end of quicksort