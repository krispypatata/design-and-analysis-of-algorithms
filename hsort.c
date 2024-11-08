// Evangelista, Bill Jerson
// Gabinete, Keith Ginoel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// ═════════════════════════════════════════════════════════════════════════════════════
// Helper function for swapping elements
void swap (int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// ─────────────────────────────────────────────────────────────────────────────────────
// Helper function for initializing the contents of an array
void init(int a[], int n) {
    int i;

    /* Ascending */
    // for (i = 0; i < n; i++) {
    //     a[i] = i + 1;
    // }

    /* Descending */
    // for (i = 0; i < n; i++) {
    //     a[i] = n - i;
    // }

    /* Random */
    // initialize array a
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
    } 

    // set seed
    // srand(7);
    // srand(13);
    srand(17);

    // Perform swapping
    for (i = 0; i < n; i++) {
        swap (&a[i], &a[rand()%n]);
    }
}

// ─────────────────────────────────────────────────────────────────────────────────────
// Helper function for printing the contents of an array
void output(int a[], int n) {
    int i;

    for (i = 0; i < n; i ++) {
        printf("%i\n", a[i]);

    }

    printf("\n");
}


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
}


// ═════════════════════════════════════════════════════════════════════════════════════
// TEST
int main(){
    // Initialization of some necessary variables
    int base = 200000;
    // int n = base * 1;
    // int n = base * 2;
    // int n = base * 4;
    int n = base * 8;
    int a[n], i;
    clock_t t1, t2;
    // ---------------------------------------------------------------------------------
    // Print the initial contents of the array
    init(a,n);
    // output(a,n);

    // ---------------------------------------------------------------------------------
    /* 
        Measure execution time of algorithm here
    */
    t1=clock();
    // Call algorithm here
    hsort(a,n);
    t2=clock();
    // ---------------------------------------------------------------------------------
    // Print the sorted array
    // output(a,n);

    // Print the execution time
    printf("time elapsed: %0.2f\n", (double) (t2-t1)/(double)CLOCKS_PER_SEC);
}
