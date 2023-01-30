#include <stdio.h>

void swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void sort(int array[], int size) 
{
    int low = 0, high = size - 1, mid = 1;
    while (mid <= high)
    {
        if (mid > high)
            break;

        if (array[mid] == 0)
        {
            swap(array, ++low, mid++);
        } 
        else if (array[mid] == 1)
        {
            mid++;
        } 
        else
        {
            swap(array, mid, --high);
        }
    }
}

void sort2(int array[], int size)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == 0)
            zeroCount++;
        else if (array[i] == 1)
            oneCount++;
        else
            twoCount++;
    }

    for (i = 0; i < size; i++)
    {
        if (zeroCount > 0)
        {
            array[i] = 0;
            zeroCount--;
        }
        else if (oneCount > 0)
        {
            array[i] = 1;
            oneCount--;
        }
        else
        {
            array[i] = 2;
            twoCount--;
        }
    }
}

int main()
{
    int array[] = {1, 2, 1, 0, 1, 0, 2, 1, 0, 1, 2};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array, size);
    sort2(array, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}