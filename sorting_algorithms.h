// sorting_algorithms.h
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

void bsort(int arr[], int size);

void selsort(int arr[], int size);

void isort(int arr[], int size);

void msort(int arr[], int size);

void hsort(int arr[], int size);

void shsort(int arr[], int size);

void quick_sort(int a[], int low, int high);


// Utilities
void swap(int *a, int *b);
void output(int a[], int n);
int compare(const void* a, const void* b);

#endif
