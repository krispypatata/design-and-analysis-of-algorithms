// #include "sorting_algorithms.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


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
                // bsort(a, n);  // Call the sorting function (use bsort_optimized if needed)
                
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
