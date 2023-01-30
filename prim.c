#include <stdio.h>
#include <stdlib.h>

#define VERTICES 9

int PQSize = 0;

struct PQNode {
    int from;
    int to;
    int weight;
};

void swap(struct PQNode PQ[], int a, int b) {
    struct PQNode temp = PQ[a];
    PQ[a] = PQ[b];
    PQ[b] = temp;
}

void fixHeap(struct PQNode PQ[], int i) {
    int left = 2*i+1;
    int right = 2*i+2;

    if (left >= PQSize)
        return;

    int smaller = left;
    if (right < PQSize && PQ[right].weight < PQ[smaller].weight) {
        smaller = right;
    }
    
    if (PQ[smaller].weight < PQ[i].weight) {
        swap(PQ, smaller, i);
        fixHeap(PQ, smaller);
    }
}

void heapify(struct PQNode PQ[], int i) {
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < PQSize) {
        heapify(PQ, left);
    }
    if (right < PQSize) {
        heapify(PQ, right);
    }
    fixHeap(PQ, i);
}

void insert(struct PQNode PQ[], int from, int to, int weight) {
    struct PQNode newNode;
    newNode.from = from;
    newNode.to = to;
    newNode.weight = weight;
    PQ[PQSize] = newNode;
    heapify(PQ, 0);
    PQSize++;
}

struct PQNode extractMin(struct PQNode PQ[]) {
    swap(PQ, 0, --PQSize);
    heapify(PQ, 0);
    return PQ[PQSize];
}

/*
Adjacency matrix implementation of graph
*/

void addEdge(int *g[], int from, int to, int weight) {
    g[from][to] = weight;
    g[to][from] = weight;
}

void updateFringe(struct PQNode PQ[], int vertex, int *g[], int visited[], int dist[], int connected[]) {
    for (int i = 0; i < VERTICES; i++) {
        if (g[vertex][i] != 0 && visited[i] == 0) {
            int newWeight = g[vertex][i];
            if (newWeight < dist[i]) {
                dist[i] = newWeight;
                connected[i] = vertex;
                insert(PQ, vertex, i, newWeight);
            }
        }
    }
}

void printMST(int dist[], int connected[]) {
    int sum = 0;
    for (int i = 0; i < VERTICES; i++)
    {
        printf("Linked %d with %d with weight %d\n", connected[i], i, dist[i]);
        sum += dist[i];
    }
    printf("Total weight: %d\n", sum);
}

void prim(int **g, int src) {
    int dist[VERTICES], visited[VERTICES], connected[VERTICES];
    struct PQNode PQ[VERTICES];
    int i;
    for (int i = 0; i < VERTICES; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        connected[i] = -1;
    }

    dist[src] = 0;
    visited[src] = 1;
    connected[src] = src;
    insert(PQ, 0, 0, 0);
    while (PQSize > 0) {
        struct PQNode node = extractMin(PQ);
        visited[node.to] = 1;
        updateFringe(PQ, node.to, g, visited, dist, connected);
    }

    printMST(dist, connected);
}

int main()
{
    int **g = (int **) malloc(VERTICES * sizeof(int *));
    for (int i = 0; i < VERTICES; i++)
    {
        g[i] = (int *) malloc(VERTICES * sizeof(int));
        for (int j = 0; j < VERTICES; j++)
        {
            g[i][j] = 0;
        }
    }
    addEdge(g, 0, 1, 4);
    addEdge(g, 0, 7, 8);
    addEdge(g, 1, 2, 8);
    addEdge(g, 1, 7, 11);
    addEdge(g, 2, 3, 7);
    addEdge(g, 2, 8, 2);
    addEdge(g, 2, 5, 4);
    addEdge(g, 3, 4, 9);
    addEdge(g, 3, 5, 14);
    addEdge(g, 4, 5, 10);
    addEdge(g, 5, 6, 2);
    addEdge(g, 6, 8, 6);
    addEdge(g, 6, 7, 1);
    addEdge(g, 7, 8, 7);
    prim(g, 0);
}