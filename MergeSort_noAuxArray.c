#include <stdio.h>

// helper functions
void printArray(int a[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int arr[], int n, int m) {
    int mid = (n + m) / 2;
    int a = n, b = mid + 1, i, tmp;

    while (a <= mid && b <= m) {
        if (arr[a] > arr[b]) {
            tmp = arr[b++];
            for (i = ++mid; i > a; i--) {
                arr[i] = arr[i-1];
            }
            arr[a++] = tmp;
        } else if (arr[a] < arr[b]) {
            a++;
        } else {
            if (a == mid && b == m) break;
            tmp = arr[b++];
            a++;
            for (i = ++mid; i > a; i--) {
                arr[i] = arr[i-1];
            }
            arr[a++] = tmp;
        }
    }
}

void mergeSort(int a[], int n, int m) {
    int mid = (n + m)/2;
    if (m - n <= 0)
        return;
    else if (m - n > 1) {
        mergeSort(a, n, mid);
        mergeSort(a, mid+1, m);
    }
    merge(a, n, m);
}

int main() {
    int arr[] = {0, 4, 7, 1, 2, 9, 24, 10, 3, 99};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("Before sort\n");
    printArray(arr, arrSize);
    mergeSort(arr, 0, arrSize-1);
    printf("After sort\n");
    printArray(arr, arrSize);
}