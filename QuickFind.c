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
void quickFindUF(int id[], int size)
{
    for (int i = 0; i < size; i++)
    {
        id[i] = i;
    }
}

// Returns root node that p is connected to
// O(1) time complexity
int find(int id[], int p)
{
    return id[p];
}

// Unions 2 connected components together
// O(N) time complexity
void unionQF(int id[], int size, int p, int q)
{
    int pid = id[p];
    int qid = id[q];

    if (pid == qid)
        return;  

    for (int i = 0; i < size; i++)
    {
        if (id[i] == pid)
        {
            id[i] = qid;
        }
    }
}

// Returns whether p and q are connected
// O(1) time complexity
int connected(int id[], int p, int q)
{
    return (find(id, p) == find(id, q) ? 1 : 0);
}

int main()
{
    int size = 10;
    int id[size];
    quickFindUF(id, size);
    unionQF(id, size, 4, 3);
    unionQF(id, size, 3, 8);
    unionQF(id, size, 6, 5);
    unionQF(id, size, 9, 4);
    unionQF(id, size, 2, 1);
    printf("Is 8 and 9 connected? %d\n", connected(id, 8, 9));
    printf("Is 5 and 0 connected? %d\n", connected(id, 5, 0));
    unionQF(id, size, 5, 0);
    printArray(id, size);
}