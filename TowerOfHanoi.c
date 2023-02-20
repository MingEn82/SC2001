#include <stdio.h>

void TowerOfHanoi(int n, int start, int mid, int end)
{
    if (n == 1) 
    {
        printf("Move disk from %d to %d\n", start, end);
    }
    else
    {
        TowerOfHanoi(n-1, start, end, mid);
        printf("Move disk from %d to %d\n", start, mid);
        TowerOfHanoi(n-1, mid, start, end);
    }
    
}

int main()
{
    TowerOfHanoi(5, 1, 2, 3);
}