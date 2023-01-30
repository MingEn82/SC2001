#include <stdio.h>

int checkDuplicate(int array[], int size)
{
    int hashmap[size*2+1];
    int i;

    for (i = 0; i <= size*2; i++)
    {
        hashmap[i] = 0;
    }
    
    for (i = 0; i < size; i++)
    {
        if (hashmap[array[i]] == 0)
        {
            hashmap[array[i]] = 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
} 

int main()
{
    int array[] = {0, 4, 9, 8, 10};
    int size = sizeof(array)/sizeof(array[0]);
    printf("%d\n", checkDuplicate(array, size));
}