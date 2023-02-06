#include <stdio.h>
#include <stdlib.h>

int PQ_SIZE = 0;

struct Node {
    int value;
    struct Node *next;
};

void swap(struct Node *PQ[], int a, int b)
{
    struct Node *temp = PQ[a];
    PQ[a] = PQ[b];
    PQ[b] = temp;
}

void fixHeap(struct Node *PQ[], int i)
{
    int left = i*2+1;
    int right = i*2+2;

    if (left >= PQ_SIZE)
        return;

    int smallest = left;
    if (right < PQ_SIZE && PQ[right]->value < PQ[left]->value)
    {
        smallest = right;
    }

    if (PQ[smallest]->value < PQ[i]->value)
    {
        swap(PQ, i, smallest);
        fixHeap(PQ, smallest);
    }
}

void heapify(struct Node *PQ[], int i)
{
    int left = i*2+1;
    int right = i*2+2;

    if (left < PQ_SIZE)
    {
        heapify(PQ, left);
    }
    if (right < PQ_SIZE)
    {
        heapify(PQ, right);
    }
    fixHeap(PQ, i);
}

struct Node* getMin(struct Node *PQ[])
{
    swap(PQ, 0, --PQ_SIZE);
    heapify(PQ, 0);
    return PQ[PQ_SIZE];
}

void insert(struct Node *PQ[], struct Node *node)
{
    PQ[PQ_SIZE++] = node;
    heapify(PQ, 0);
}

struct Node * mergeKSortedLists(struct Node lists[], int size)
{
    struct Node *PQ[size];
    struct Node *head = NULL, *ptr = NULL;
    for (int i = 0; i < size; i++)
    {
        insert(PQ, &lists[i]);
    }

    while (PQ_SIZE > 0)
    {
        struct Node *minNode = getMin(PQ);
        struct Node *nextNode = minNode->next;
        
        if (head == NULL)
        {
            head = malloc(sizeof(struct Node));
            ptr = malloc(sizeof(struct Node));
            head = ptr = minNode;
        }
        else
        {
            ptr->next = minNode;
            ptr = ptr->next;
        }
        // printf("%d\n", ptr->next->value);
        if (nextNode != NULL)
            insert(PQ, nextNode);
    }

    return head;
}

int main()
{
    struct Node lists[3];

    struct Node node1;
    node1.value = 1;
    struct Node node2;
    node2.value = 3;
    struct Node node3;
    node3.value = 5;
    struct Node node4;
    node4.value = 7;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL;
    lists[0] = node1;    

    struct Node node5;
    node5.value = 2;
    struct Node node6;
    node6.value = 4;
    struct Node node7;
    node7.value = 6;
    struct Node node8;
    node8.value = 8;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = NULL;
    lists[1] = node5;

    struct Node node9;
    node9.value = 0;
    struct Node node10;
    node10.value = 9;
    struct Node node11;
    node11.value = 10;
    struct Node node12;
    node12.value = 11;
    node9.next = &node10;
    node10.next = &node11;
    node11.next = &node12;
    node12.next = NULL;
    lists[2] = node9;

    struct Node *ptr = mergeKSortedLists(lists, 3);
    while (ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
}