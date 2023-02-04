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
void WQUUF(int id[], int size)
{
    for (int i = 0; i < size; i++)
    {
        id[i] = i;
    }
}

// Initialises size array
// O(N) time complexity
void initialiseSize(int sz[], int size)
{
    for (int i = 0; i < size; i++)
    {
        sz[i] = 1;
    }
}

// Returns the root of p
// O(logN) time complexity in the worst case
// Depth of any node x is at most log2(N)
int find(int id[], int p)
{
    while (p != id[p])
    {
        p = id[p];
    }
    return p;
}


// Returns whether p and q are connected
// O(logN) time complexity in the worst case
// Depth of any node x is at most log2(N)
int connected(int id[], int p, int q)
{
    return (find(id, p) == find(id, q) ? 1 : 0);
}

// Connects tree of p to the tree of q by
// setting the root of smaller tree to root of larger
// O(N+MlogN) time complexity in the worst case
void unionWQU(int id[], int sz[], int p, int q)
{
    int pRoot = find(id, p);
    int qRoot = find(id, q);

    if (pRoot == qRoot)
    {
        return;
    }

    if (sz[p] < sz[q])
    {
        id[pRoot] = id[qRoot];
        sz[qRoot] += sz[pRoot]; 
    }
    else
    {
        id[qRoot] = id[pRoot];
        sz[pRoot] += sz[qRoot];
    }
}

int main()
{
    int size = 10;
    int id[size];
    int sz[size];
    WQUUF(id, size);
    initialiseSize(sz, size);
    unionWQU(id, sz, 4, 3);
    unionWQU(id, sz, 3, 8);
    unionWQU(id, sz, 6, 5);
    unionWQU(id, sz, 9, 4);
    unionWQU(id, sz, 2, 1);
    printf("Is 8 and 9 connected? %d\n", connected(id, 8, 9));
    printf("Is 5 and 4 connected? %d\n", connected(id, 5, 4));
    unionWQU(id, sz, 5, 0);
    printArray(id, size);
}