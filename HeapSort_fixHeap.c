#include <stdio.h>

// helper functions
void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int a[], int n, int m) {
    int tmp = a[n];
    a[n] = a[m];
    a[m] = tmp;
}

void fixHeap(int *array, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // return if element is leaf
    if (left > n)
        return;
    
    // find index of largest element
    int larger = left;
    if (right <= n && array[right] > array[larger])
        larger = right;
    
    // swap larger child with root if root is smaller
    // recursively call fixHeap on sub-heap
    if (array[i] < array[larger])
    {
        swap(array, i, larger);
        fixHeap(array, larger, n);
    }
}

void heapify(int *array, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= n)
    {
        heapify(array, left, n);
    }
    if (right <= n)
    {
        heapify(array, right, n);
    }
    fixHeap(array, i, n);
}

void heapSort(int *array, int n)
{

    int N = n;
    while (N >= 0)
    {
        heapify(array, 0, N);
        swap(array, N, 0);
        N--;
    }
}

int main() {
    int arr[] = {0, 4, 7, 1, 2, 9, 24, 10, 3, 99};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("Before sort\n");
    printArray(arr, 0, arrSize);
    heapSort(arr, arrSize);
    printf("After sort\n");
    printArray(arr, 0, arrSize);
}