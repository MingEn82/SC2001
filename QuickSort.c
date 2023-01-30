#include <stdio.h>

// helper functions
void printArray(int a[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int n, int m) {
    int tmp = a[n];
    a[n] = a[m];
    a[m] = tmp;
}

int partition(int a[], int low, int high) {
    int i, last_small, pivot;
    int mid = (low + high) / 2;
    swap(a, low, mid);
    pivot = a[low];
    last_small = low;

    for (i = low+1; i < high; i++) {
        if (a[i] < pivot)
            swap(a, ++last_small, i);
    }

    swap(a, low, last_small);
    return last_small;
}

void quicksort(int a[], int n, int m) {
    if (n >= m) return;
    int pivotPos = partition(a, n, m);
    quicksort(a, n, pivotPos-1);
    quicksort(a, pivotPos+1, m);
}

int main() {
    int arr[] = {0, 4, 7, 1, 2, 9, 24, 10, 3, 99};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("Before sort\n");
    printArray(arr, arrSize);
    quicksort(arr, 0, arrSize-1);
    printf("After sort\n");
    printArray(arr, arrSize);
}