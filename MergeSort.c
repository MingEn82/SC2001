#include <stdio.h>

// helper functions
void printArray(int a[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int n, int m) {
    int mid = (n + m) / 2;
    int i, j, k;
    int n1 = mid - n + 1;
    int n2 = m - mid;

    // initialising temp arrays
    int a1[n1], a2[n2];

    for (i = 0; i < n1; i++) {
        a1[i] = a[n+i];
    }

    for (i = 0; i < n2; i++) {
        a2[i] = a[mid+1+i];
    }

    // copying smallest element to main array
    i = 0, j = 0, k = n;
    while (i < n1 && j < n2) {
        if (a1[i] < a2[j]) {
            a[k++] = a1[i++];
        } else if (a1[i] > a2[j]) {
            a[k++] = a2[j++];
        } else {
            if (i == n1 && j == n2) break;
            a[k++] = a1[i++];
            a[k++] = a2[j++];
        }
    }

    // adding remaining elements to main array
    while (i < n1) {
        a[k++] = a1[i++];
    }
    while (j < n2) {
        a[k++] = a2[j++];
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