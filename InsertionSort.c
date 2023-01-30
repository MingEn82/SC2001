#include <stdio.h>

// helper functions
void printArray(int a[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void insertionSort(int a[], int arrSize) {
    for (int i = 1; i < arrSize; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j-1])
                swap(a, j, j-1);
            else break;
        }
    }
}

int main() {
    int arr[] = {0, 4, 7, 1, 2, 9, 24, 10, 3, 99};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("Before sort\n");
    printArray(arr, arrSize);
    insertionSort(arr, arrSize);
    printf("After sort\n");
    printArray(arr, arrSize);
}
