#include <stdio.h>
#include <stdlib.h>

// helper functions
void printArray(int id[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", id[i]);
    }
    printf("\n");
}

// Initialises array
// O(N) time complexity
void quickUnionUF(int id[], int size)
{
    for (int i = 0; i < size; i++)
    {
        id[i] = i;
    }
}

// Returns the root of p
// O(N) time complexity in the worst case
// Worst case is a tree of height of N (effectively a linked list)
int find(int id[], int p)
{
    while (p != id[p])
    {
        p = id[p];
    }
    return p;
}


// Returns whether p and q are connected
// O(N) time complexity in the worst case
// Worst case is a tree of height of N (effectively a linked list)
int connected(int id[], int p, int q)
{
    return (find(id, p) == find(id, q) ? 1 : 0);
}

// Connects tree of p to the tree of q by
// setting the root of p to be the root of q
// O(N) time complexity in the worst case
// Worst case is a tree of height of N (effectively a linked list)
void unionQU(int id[], int p, int q)
{
    id[find(id, p)] = find(id, q);
}

int main()
{
    int size = 10;
    int id[size];
    quickUnionUF(id, size);
    unionQU(id, 4, 3);
    unionQU(id, 3, 8);
    unionQU(id, 6, 5);
    unionQU(id, 9, 4);
    unionQU(id, 2, 1);
    printf("Is 8 and 9 connected? %d\n", connected(id, 8, 9));
    printf("Is 5 and 4 connected? %d\n", connected(id, 5, 4));
    unionQU(id, 5, 0);
    printArray(id, size);
}