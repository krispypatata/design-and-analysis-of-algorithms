// sorting_algorithms.h
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

// Sorting functions
void bsort(int arr[], int size);
void selsort(int arr[], int size);
void isort(int arr[], int size);
void msort(int arr[], int size);
void hsort(int arr[], int size);
void shsort(int arr[], int size);
void quick_sort(int a[], int low, int high);

// Generic sorting functions
void genbsort(void *base, int n, int size, int (*cmp)(const void *, const void *));
void genselsort(void *base, int n, int size, int (*cmp)(const void *, const void *));
void genisort(void *base, int n, int size, int (*cmp)(const void *, const void *));
void genshsort(void *base, int n, int size, int (*cmp)(const void *, const void *));
void genmsort(void *base, int n, int size, int (*cmp)(const void *, const void *));
void genhsort(void *base, int n, int size, int (*cmp)(const void *, const void *));
void genqsort(void *base, int low, int high, int size, int (*cmp)(const void *, const void *));

// Utilities
void swap(int *a, int *b);
void output(int a[], int n);
int compare(const void* a, const void* b);

void genswap(const void *p1, const void *p2, int size);
int cmpint(const void *p1, const void *p2);

#endif
