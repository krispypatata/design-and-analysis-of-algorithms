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
    for (i = 0; i < n; i++) {
        a[i] = n - i;
    }

    /* Random */
    // initialize array a
    // for (i = 0; i < n; i++) {
    //     a[i] = i + 1;
    // } 

    // set seed
    // srand(7);
    // srand(13);
    // srand(17);

    // Perform swapping
    // for (i = 0; i < n; i++) {
    //     swap (&a[i], &a[rand()%n]);
    // }
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
// Function implementation of the quick sort algorithm
// reference: https://www.geeksforgeeks.org/quick-sort-algorithm/
// Partition function
// int partition(int a[], int low, int high) {
//     // Choose the pivot
//     int pivot = a[high];
    
//     // Index of smaller element and indicates 
//     // the right position of pivot found so far
//     int i = low - 1;

//     // Traverse arr[low..high] and move all smaller
//     // elements to the left side. Elements from low to 
//     // i are smaller after every iteration
//     for (int j = low; j <= high - 1; j++) {
//         if (a[j] < pivot) {
//             i++;
//             swap(&a[i], &a[j]);
//         }
//     }
    
//     // Move pivot after smaller elements and
//     // return its position
//     swap(&a[i + 1], &a[high]);  
//     return i + 1;
// }

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
}


// ═════════════════════════════════════════════════════════════════════════════════════
// Comparison function for the built-in qsort
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}


// ═════════════════════════════════════════════════════════════════════════════════════
// TEST
int main(){
    // Initialization of some necessary variables
    int base = 200000;
    int n = base * 1;
    // int n = base * 2;
    // int n = base * 4;
    // int n = base * 8;
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
    /*
    built-in qsort()
    reference: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
    => This function accepts following parameters:
        base − It represents pointer to the first element of the array to be sorted.
        nitems − It represents number of element in the array.
        size − It represents size of each element in the array.
        compare − It represent a function pointer to a comparison function that compares two elements.
    */
    // qsort(a, n, sizeof(int), compare);

    // Using the implemented qsort
    quick_sort(a, 0, n - 1);
    t2=clock();
    // ---------------------------------------------------------------------------------
    // Print the sorted array
    // output(a,n);

    // Print the execution time
    printf("time elapsed: %0.2f\n", (double) (t2-t1)/(double)CLOCKS_PER_SEC);
}
