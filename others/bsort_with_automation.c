// Evangelista, Bill Jerson
// Gabinete, Keith Ginoel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Helper function for swapping elements
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function for initializing the contents of an array
void init(int a[], int n, int seed_type) {
    int i;
    
    if (seed_type == 0) { // Ascending order
        for (i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    } else if (seed_type == 1) { // Descending order
        for (i = 0; i < n; i++) {
            a[i] = n - i;
        }
    } else { // Random order with specified seed
        for (i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        
        // Set random seed based on the seed_type
        srand(seed_type); // Different seeds for different runs
        for (i = 0; i < n; i++) {
            swap(&a[i], &a[rand() % n]);
        }
    }
}

// Helper function for printing the contents of an array (optional)
void output(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%i\n", a[i]);
    }
    printf("\n");
}

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

// Function to perform testing and output results
void run_tests(int base) {
    int a[base * 8];  // Maximum size array for n*8
    clock_t t1, t2;
    
    // Array sizes (n, n*2, n*4, n*8)
    int sizes[] = {1, 2, 4, 8};
    int seed_types[] = {0, 1, 7, 13, 17}; // 0: Ascending, 1: Descending, 7/13/17: Random with different seeds
    int i, j, k, multiplier, seed_type;

    // Perform tests for each seed type and array size
    for (seed_type = 0; seed_type < 5; seed_type++) {
        for (i = 0; i < 4; i++) {
            multiplier = sizes[i];
            int n = base * multiplier;  // Calculate array size n, n*2, n*4, n*8

            for (j = 0; j < 3; j++) {  // Repeat the test 3 times
                // Initialize the array with the appropriate order
                init(a, n, seed_type);
                
                // Measure execution time of the algorithm
                t1 = clock();
                bsort(a, n);  // Call the sorting function (use bsort_optimized if needed)
                t2 = clock();

                // Output the execution time for this test case
                printf("Seed: %d, Size: %d, Trial: %d, Time: %0.2f seconds\n", 
                    seed_type, n, j + 1, (double)(t2 - t1) / CLOCKS_PER_SEC);
            }
        }
    }
}

// Main function
int main() {
    int base = 10000;  // Set a base size for n

    // Run all tests
    run_tests(base);

    return 0;
}
