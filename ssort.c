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
// Function implementation of the shell sort algorithm
// reference: https://www.geeksforgeeks.org/shell-sort/
int ssort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1) {
           // Perform insertion sort for this gap size
            for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap) {
                swap(&arr[j], &arr[j - gap]);
            }
        }
    }
    return 0;
}


// ═════════════════════════════════════════════════════════════════════════════════════
// TEST
int main(){
    // Initialization of some necessary variables
    int base = 10000;
    // int n = base * 1;
    // int n = base * 2;
    // int n = base * 4;
    int n = base * 8;
    int a[n], i;
    clock_t t1, t2;
    // ---------------------------------------------------------------------------------
    // Print the initial contents of the array
    init(a,n);
    output(a,n);

    // ---------------------------------------------------------------------------------
    /* 
        Measure execution time of algorithm here
    */
    t1=clock();
    // Call algorithm here
    ssort(a,n);
    t2=clock();
    // ---------------------------------------------------------------------------------
    // Print the sorted array
    output(a,n);

    // Print the execution time
    printf("time elapsed: %0.2f\n", (double) (t2-t1)/(double)CLOCKS_PER_SEC);
}
