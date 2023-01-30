#include <stdio.h>

// helper functions
void printArray(int a[], int start, int arrSize) {
    for (int i = start; i < arrSize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int n, int m) {
    int tmp = a[n];
    a[n] = a[m];
    a[m] = tmp;
}

void heapify(int arr[], int size, int x) {
    int leftChildIdx = 2*x;
    int rightChildIdx = 2*x+1;
    int largest = x;

    // find index of largest element
    if (leftChildIdx < size && arr[leftChildIdx] > arr[largest]) {
        largest = leftChildIdx;
    }

    if (rightChildIdx < size && arr[rightChildIdx] > arr[largest]) {
        largest = rightChildIdx;;
    }

    if (largest != x) {
        swap(arr, largest, x);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    // create max heap
    int i;
    for (i = size / 2; i > 0; i--) {
        heapify(arr, size, i);
    }

    for (i = size-1; i > 1; i--) {
        swap(arr, i, 1);
        heapify(arr, i, 1);
    }
}

int main() {
    int arr[] = {0, 0, 4, 7, 1, 2, 9, 24, 10, 3, 99};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("Before sort\n");
    printArray(arr, 1, arrSize);
    heapSort(arr, arrSize);
    printf("After sort\n");
    printArray(arr, 1, arrSize);
}