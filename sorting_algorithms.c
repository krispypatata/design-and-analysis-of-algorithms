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












// ═════════════════════════════════════════════════════════════════════════════════════
// SORTING ALGORITHMS (GENERICS)
// ═════════════════════════════════════════════════════════════════════════════════════
// Helper functions for generic versions of sorting algorithms
// int cmpint(const void *p1, const void *p2){
//     return ((*((int *)p1)) - (*((int *)p2)) > 0 );
// }
// Correct implementation
int cmpint(const void *p1, const void *p2) {
    int int1 = *((int *)p1);
    int int2 = *((int *)p2);
    return (int1 - int2);  // return the difference
}



// ─────────────────────────────────────────────────────────────────────────────────────
void genswap(const void *p1, const void *p2, int size){
    void *ptemp=(void *)malloc(size);
    memcpy(ptemp,(void *)p1,size);
    memcpy((void *)p1,(void *)p2,size);
    memcpy((void *)p2,ptemp,size);
    free(ptemp);
}

// ═════════════════════════════════════════════════════════════════════════════════════
// Generic Bubble Sort function
void genbsort(void *base, int n, int size, int (*cmp)(const void *, const void *)) {
    int i, j;
    char *arr = (char *)base;  // cast to char* for pointer arithmetic

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (cmp(arr + (j * size), arr + ((j + 1) * size)) > 0) {
                genswap(arr + (j * size), arr + ((j + 1) * size), size);
            }
        }
    }
}

// genbsort(a, n, sizeof(int), cmpint);

// ═════════════════════════════════════════════════════════════════════════════════════
// Generic Selection Sort function
void genselsort(void *base, int n, int size, int (*cmp)(const void *, const void *)) {
    int i, j, index_of_min;
    char *arr = (char *)base;  // cast to char* for pointer arithmetic

    for (i = 0; i < n - 1; i++) {
        index_of_min = i;

        for (j = i + 1; j < n; j++) {
            if (cmp(arr + (index_of_min * size), arr + (j * size)) > 0) {
                index_of_min = j;
            }
        }

        if (index_of_min != i) {
            genswap(arr + (i * size), arr + (index_of_min * size), size);
        }
    }
}


// genselsort(a, n, sizeof(int), cmpint);


// ═════════════════════════════════════════════════════════════════════════════════════
// Generic Insertion Sort function
void genisort(void *base, int n, int size, int (*cmp)(const void *, const void *)){
    int i,j;

    for(i=1;i<n;i++)
        for(j=i;j>0;j--)
	     if(cmp(base+((j-1)*size),base+(j*size)))
                 genswap(base+((j-1)*size),base+(j*size),size);
             else break;
}

// genisort(a, n, sizeof(int), cmpint);

// ═════════════════════════════════════════════════════════════════════════════════════
// Generic Shell Sort function
void genshsort(void *base, int n, int size, int (*cmp)(const void *, const void *)){
    int i, j, d;

    for (d = n / 2; d > 0; d /= 2) {
        for (i = d; i < n; i++) {
            for (j = i; j > d - 1; j -= d) {
                if (cmp(base + (j * size), base + ((j - d) * size))) {
                    genswap(base + (j * size), base + ((j - d) * size), size);
                } else {
                    break;
                }
            }
        }
    }
}

// genshsort(a, n, sizeof(int), cmpint);

// ═════════════════════════════════════════════════════════════════════════════════════
// Generic merge function
void genmerge(void *base, int n, int size, int (*cmp)(const void *, const void *)){
    int i, j, k, mid = n / 2;
    void *temp = malloc(n * size);
    
    for (i = 0, j = mid, k = 0; k < n; k++) {
        if (i < mid && (j >= n || cmp(base + (i * size), base + (j * size)) <= 0)) {
            memcpy(temp + (k * size), base + (i * size), size);
            i++;
        } else {
            memcpy(temp + (k * size), base + (j * size), size);
            j++;
        }
    }

    memcpy(base, temp, n * size); // copy temp back to base
    free(temp);
}

// Generic merge sort function
void genmsort(void *base, int n, int size, int (*cmp)(const void *, const void *)){
    if (n > 1) {
        int mid = n / 2;
        genmsort(base, mid, size, cmp);
        genmsort(base + (mid * size), n - mid, size, cmp);
        genmerge(base, n, size, cmp);
    }
} // end of genmsort

// genmsort(a, n, sizeof(int), cmpint);


// ═════════════════════════════════════════════════════════════════════════════════════
// Generic heapify function
void genheapify(void *base, int n, int i, int size, int (*cmp)(const void *, const void *)) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && cmp(base + (l * size), base + (largest * size)) > 0) {
        largest = l;
    }

    if (r < n && cmp(base + (r * size), base + (largest * size)) > 0) {
        largest = r;
    }

    if (largest != i) {
        genswap(base + (i * size), base + (largest * size), size);
        genheapify(base, n, largest, size, cmp);
    }
}

// Generic heap sort function
void genhsort(void *base, int n, int size, int (*cmp)(const void *, const void *)) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        genheapify(base, n, i, size, cmp);
    }

    for (int i = n - 1; i > 0; i--) {
        genswap(base + (0 * size), base + (i * size), size);
        genheapify(base, i, 0, size, cmp);
    }
} // end of genhsort

// genhsort(a, n, sizeof(int), cmpint);


// ═════════════════════════════════════════════════════════════════════════════════════
// Generic partition function using median-of-three pivot selection
int genpartition(void *base, int low, int high, int size, int (*cmp)(const void *, const void *)) {
    int mid = low + (high - low) / 2;
    
    // Median of three pivot selection
    if (cmp(base + (mid * size), base + (low * size)) < 0)
        genswap(base + (mid * size), base + (low * size), size);
    if (cmp(base + (high * size), base + (low * size)) < 0)
        genswap(base + (high * size), base + (low * size), size);
    if (cmp(base + (high * size), base + (mid * size)) < 0)
        genswap(base + (high * size), base + (mid * size), size);
    
    void *pivot = base + (mid * size);
    genswap(base + (mid * size), base + (high * size), size);

    int i = low - 1;

    // Traverse the array and move all smaller elements to the left side
    for (int j = low; j <= high - 1; j++) {
        if (cmp(base + (j * size), pivot) < 0) {
            i++;
            genswap(base + (i * size), base + (j * size), size);
        }
    }

    // Move pivot to the correct position
    genswap(base + ((i + 1) * size), base + (high * size), size);
    return i + 1;
}

// Generic quick sort function
void genqsort(void *base, int low, int high, int size, int (*cmp)(const void *, const void *)) {
    if (low < high) {
        int pi = genpartition(base, low, high, size, cmp);

        genqsort(base, low, pi - 1, size, cmp);
        genqsort(base, pi + 1, high, size, cmp);
    }
} // end of genqsort

// genqsort(a, 0, n - 1, sizeof(int), cmpint);


