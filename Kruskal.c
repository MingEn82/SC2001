#include <stdio.h>
#include <stdlib.h>

int SIZE = 10;
int EDGES_SIZE = 0;
int NUM_VERTICES = 8;

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

int find(int id[], int p)
{
    while(p != id[p])
    {
        id[p] = id[id[p]];
        p = id[p];
    }
}

int connected(int id[], int p, int q)
{
    return (find(id, p) == find(id, q) ? 1 : 0);
}

void unionWQUPC(int id[], int sz[], int p, int q)
{
    int pRoot = find(id, p);
    int qRoot = find(id, q);
    
    if (pRoot == qRoot)
        return;
    
    if (sz[pRoot] < sz[qRoot])
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

struct Edge
{
    int from;
    int to;
    int weight;
};

void swapEdge(struct Edge edges[], int a, int b)
{
    struct Edge temp = edges[a];
    edges[a] = edges[b];
    edges[b] = temp;
}

void fixHeap(struct Edge edges[], int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;

    if (left >= EDGES_SIZE)
        return;
    
    
    if (left < EDGES_SIZE && edges[left].weight < edges[smallest].weight)
    {
        smallest = left;
    }
    if (right < EDGES_SIZE && edges[right].weight < edges[smallest].weight)
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swapEdge(edges, smallest, i);
        fixHeap(edges, smallest);
    }
}

void heapify(struct Edge edges[], int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    if (left < EDGES_SIZE)
    {
        heapify(edges, left);
    }
    if (right < EDGES_SIZE)
    {
        heapify(edges, right);
    }
    fixHeap(edges, i);
}

struct Edge getMin(struct Edge edges[])
{
    swapEdge(edges, 0, --EDGES_SIZE);
    heapify(edges, 0);
    return edges[EDGES_SIZE];
}

// Graph functions
int** createGraph()
{
    int **g = malloc(sizeof(int *) * NUM_VERTICES);
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        g[i] = malloc(sizeof(int) * NUM_VERTICES);
        for (int j = 0; j < NUM_VERTICES; j++)
        {
            g[i][j] = 0;
        }
    }
    return g;
}

void printGraph(int **g)
{
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        for (int j = 0; j < NUM_VERTICES; j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

void printEdges(struct Edge edges[])
{
    for (int i = 0; i < EDGES_SIZE; i++)
    {
        printf("From: %d, To: %d, Weight: %d\n", edges[i].from, edges[i].to, edges[i].weight);
    }
}

struct Edge* addEdge(int **g, struct Edge edges[], int from, int to, int weight)
{
    g[from][to] = weight;
    g[to][from] = weight;

    struct Edge newEdge;
    newEdge.weight = weight;
    newEdge.from = from;
    newEdge.to = to;

    EDGES_SIZE++;
    edges = realloc(edges, EDGES_SIZE * sizeof(struct Edge));
    edges[EDGES_SIZE - 1] = newEdge;
    heapify(edges, 0);

    return edges;
}

void kruskal(struct Edge edges[])
{
    int shortestPathLength = 0;
    int id[EDGES_SIZE];
    int sz[EDGES_SIZE];
    WQUPCUF(id, EDGES_SIZE);
    initialiseSize(sz, EDGES_SIZE);
    while (EDGES_SIZE > 0)
    {
        struct Edge minEdge = getMin(edges);
        if (connected(id, minEdge.from, minEdge.to) == 0)
        {
            unionWQUPC(id, sz, minEdge.from, minEdge.to);
            printf("Linked %d with %d with weight %d\n", minEdge.from, minEdge.to, minEdge.weight);
            shortestPathLength += minEdge.weight;
        }
    }
    printf("Shortest path length: %d\n", shortestPathLength);
}

int main()
{
    int **g = createGraph();
    struct Edge *edges;
    edges = addEdge(g, edges, 6, 4, 16);
    edges = addEdge(g, edges, 6, 0, 15);
    edges = addEdge(g, edges, 3, 6, 14);
    edges = addEdge(g, edges, 6, 2, 13);
    edges = addEdge(g, edges, 0, 4, 12);
    edges = addEdge(g, edges, 4, 7, 11);
    edges = addEdge(g, edges, 1, 2, 10);
    edges = addEdge(g, edges, 5, 4, 9);
    edges = addEdge(g, edges, 2, 7, 8);
    edges = addEdge(g, edges, 1, 5, 7);
    edges = addEdge(g, edges, 1, 3, 6);
    edges = addEdge(g, edges, 5, 7, 5);
    edges = addEdge(g, edges, 0, 2, 4);
    edges = addEdge(g, edges, 1, 7, 3);
    edges = addEdge(g, edges, 2, 3, 2);
    edges = addEdge(g, edges, 0, 7, 1);
    printGraph(g);
    kruskal(edges);
}