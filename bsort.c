// Evangelista, Bill Jerson
// Gabinete, Keith Ginoel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


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
// Function implementation of the bubble sort algorithm (optimized)
// https://www.geeksforgeeks.org/bubble-sort-algorithm/
void bsort_optimized(int a[], int n) {
    int i, j;
    bool is_swapped;

    for (i = 0; i < n; i++) {
        is_swapped = false;
        for (j = 1; j < n - i - 1; j ++) {
            if (a[j] > a[j + 1]) 
                swap(&a[j], &a[j + 1]);
                is_swapped = true;
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (is_swapped == false)
            break;
    }
}


// ═════════════════════════════════════════════════════════════════════════════════════
// Function implementation of the bubble sort algorithm
void bsort(int a[], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 1; j < n - i; j++) {
            if (a[j - 1] > a[j]) 
                swap(&a[j - 1], &a[j]);
        }

    }
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
    bsort(a,n);
    // bsort_optimized(a,n);
    t2=clock();
    // ---------------------------------------------------------------------------------
    // Print the sorted array
    output(a,n);

    // Print the execution time
    printf("time elapsed: %0.2f\n", (double) (t2-t1)/(double)CLOCKS_PER_SEC);
}
