#include <stdio.h>
#include <stdlib.h>
#define VERTICES 5

int PQSize = 0;

// utility functions
void swap(int array[], int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
};

// minimum Heap
struct PQNode {
    int dest;
    int weight;
};

void swapEdge(struct PQNode *PQ, int a, int b)
{
    struct PQNode temp = PQ[a];
    PQ[a] = PQ[b];
    PQ[b] = temp;
}

void fixHeap(struct PQNode *PQ, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= n)
        return;
    int smallest = left;
    if (right < n && PQ[right].weight < PQ[smallest].weight)
    {
        smallest = right;
    }
    if (PQ[smallest].weight < PQ[i].weight)
    {
        swapEdge(PQ, i, smallest);
        fixHeap(PQ, n, smallest);
    }
}

void heapify(struct PQNode *PQ, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n)
    {
        heapify(PQ, n, left);
    }
    if (right < n)
    {
        heapify(PQ, n, right);
    }
    fixHeap(PQ, n, i);
}

// insert node into minimum heap
void insert(struct PQNode *PQ, int dest, int totalWeight)
{
    struct PQNode new;
    new.dest = dest;
    new.weight = totalWeight;
    PQ[PQSize] = new;
    heapify(PQ, PQSize, 0);
    PQSize++;
}

// Get minimum node in priority queue
// which is the first element in minimum heap
// need to regenerate minimum heap after extracting
struct PQNode extractMin(struct PQNode *PQ)
{
    swapEdge(PQ, 0, --PQSize);
    heapify(PQ, PQSize, 0);
    return PQ[PQSize];
}

/*
Adjacency List Implementation of Graph
*/
// Adjacency List Node structure
// weight is the cost of travelling to this node
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode *next; 
};

// Adjacency List structure
struct AdjList {
    struct AdjListNode *head;
};

// Graph structure
// Graph is represented as an array of adjacency lists
// Size of array is V (number of vertices)
struct Graph {
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode *newNode = 
        (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
};

struct Graph* createGraph(int V) {
    struct Graph *newGraph = 
        (struct Graph *) malloc(sizeof(struct Graph));

    newGraph->V = V;
    // Create an array of adjacency lists
    // Size of array will be V
    newGraph->array = 
        (struct AdjList*) malloc(V * sizeof(struct AdjList));
    
    // Initialize each adjacency list as empty
    for (int i = 0; i < V; i++) {
        newGraph->array[i].head = NULL;
    }

    return newGraph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add a node from src to dest
    // For easier implementation, new node is inserted at front
    struct AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Uncomment below for undirected graphs!
    // Since graph is undirected,
    // add an Node from dest to src also
    // newNode = newAdjListNode(src, weight);
    // newNode->next = graph->array[dest].head;
    // graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list representation of graph
void printGraph(struct Graph* graph, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        struct AdjListNode *ptr = (graph->array)[i].head;
        printf("Source %d: ", i);
        while (ptr != NULL)
        {
            printf("%d(%d) -> ", ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int * dijkstra(struct Graph *g, int src) {
    struct PQNode PQ[500];
    int visited[VERTICES];
    static int dist[VERTICES];
    int i, idx, newDist;

    for (i = 0; i < VERTICES; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;
    insert(PQ, src, 0);
    while (PQSize > 0) {
        struct PQNode pqMin = extractMin(PQ);
        idx = pqMin.dest;
        visited[idx] = 1;
        struct AdjListNode *ptr = g->array[idx].head;
        while (ptr) {
            newDist = dist[idx] + ptr->weight;
            if (visited[ptr->dest] != 1 && dist[ptr->dest] > newDist) {
                dist[ptr->dest] = newDist;
                insert(PQ, ptr->dest, newDist);
            }
            ptr = ptr->next;
        }
    }

    for (i = 0; i < VERTICES; i++) {
        printf("%d: %d | ", i, dist[i]);
    }
    printf("\n");

    return dist;
}

int main()
{
    struct Graph *g = createGraph(VERTICES);
    addEdge(g, 0, 1, 10);
    addEdge(g, 0, 3, 5);
    addEdge(g, 1, 2, 1);
    addEdge(g, 1, 3, 2);
    addEdge(g, 2, 4, 4);
    addEdge(g, 3, 1, 3);
    addEdge(g, 3, 2, 9);
    addEdge(g, 3, 4, 2);
    addEdge(g, 4, 0, 7);
    addEdge(g, 4, 2, 6);
    printGraph(g, VERTICES);

    int src = 1;
    int *dist = dijkstra(g, src);
    // printArray(dist, 0, VER - 1);
 
    return 0;
}