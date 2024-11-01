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
    msort(a,n);
    t2=clock();
    // ---------------------------------------------------------------------------------
    // Print the sorted array
    output(a,n);

    // Print the execution time
    printf("time elapsed: %0.2f\n", (double) (t2-t1)/(double)CLOCKS_PER_SEC);
}