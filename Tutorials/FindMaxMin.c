#include <stdio.h>
#include <limits.h>

void findMinAndMax(int arr[], int start, int end, int minMax[]) {
    if (start == end) {
        minMax[0] = arr[start];
        minMax[1] = arr[start];
        return;
    }

    if (end - start == 1) {
        if (arr[end] > arr[start]) {
            minMax[0] = arr[start];
            minMax[1] = arr[end];
        } else {
            minMax[0] = arr[end];
            minMax[1] = arr[start];
        }
        return;
    }

    int mid = (start + end) / 2;
    int tempMinMax1[2];
    int tempMinMax2[2];

    findMinAndMax(arr, start, mid, tempMinMax1);
    findMinAndMax(arr, mid+1, end, tempMinMax2);

    if (tempMinMax1[0] < tempMinMax2[0]) {
        minMax[0] = tempMinMax1[0];
    } else {
        minMax[0] = tempMinMax2[0];
    }

    if (tempMinMax1[1] > tempMinMax2[1]) {
        minMax[1] = tempMinMax1[1];
    } else {
        minMax[1] = tempMinMax2[1];
    }

}

int main() {
    int arr[] = {0, 0, 4, 7, 1, 2, 9, 24, 10, 3, 99};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int minMax[] = {INT_MAX, INT_MIN};
    findMinAndMax(arr, 0, arrSize-1, minMax);
    // printArray(arr, arrSize);
    printf("The minimum number is: %d\n", minMax[0]);
    printf("The maximum number is: %d\n", minMax[1]);
}