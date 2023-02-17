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
void WQUPCUF(int id[], int size)
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

// Returns the root of p with single pass PC
// O(logN) time complexity in the worst case
// Depth of any node x is at most log2(N)
int findSinglePass(int id[], int p)
{
    // Single Pass Variant
    while (p != id[p])
    {
        // Make every other node in path point to its grandparent
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

// Returns the root of p with double pass PC
// O(logN) time complexity in the worst case
// Depth of any node x is at most log2(N)
int findDoublePass(int id[], int p)
{
    // Double Pass Variant
    int root = p;
    while (root != id[root])
    {
        root = id[root];
    }
    int pRoot;
    while (p != root)
    {
        pRoot = id[p];
        id[p] = root;
        p = pRoot;
    }
}

int find(int id[], int p)
{
    // return findSinglePass(id, p);
    return findDoublePass(id, p);
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
// O(N+Mlog*N) time complexity in the worst case
void unionWQUPC(int id[], int sz[], int p, int q)
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
    WQUPCUF(id, size);
    initialiseSize(sz, size);
    unionWQUPC(id, sz, 4, 3);
    unionWQUPC(id, sz, 3, 8);
    unionWQUPC(id, sz, 6, 5);
    unionWQUPC(id, sz, 9, 4);
    unionWQUPC(id, sz, 2, 1);
    printf("Is 8 and 9 connected? %d\n", connected(id, 8, 9));
    printf("Is 5 and 4 connected? %d\n", connected(id, 5, 4));
    unionWQUPC(id, sz, 5, 0);
    printArray(id, size);
}