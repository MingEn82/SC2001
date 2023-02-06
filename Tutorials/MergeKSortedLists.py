# Min Heap library
import heapq
 
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
 
def mergeKList(arr, K):
    queue = []
    for i in range(K):
        if arr[i] != None:
            heapq.heappush(queue, (arr[i].data, arr[i]))
    dummy = Node(0)
    last = dummy
    while queue:
        curr = heapq.heappop(queue)[1]
        last.next = curr
        last = last.next
        if curr.next != None:
            heapq.heappush(queue, (curr.next.data, curr.next))
    return dummy.next
 
def printList(node):
    while node != None:
        print(node.data, end=" ")
        node = node.next
    print()
 
if __name__ == "__main__":
    N = 3
    a = [None] * N
    # Linkedlist1
    head1 = Node(1)
    a[0] = head1
    head1.next = Node(3)
    head1.next.next = Node(5)
    head1.next.next.next = Node(7)
    # Linkedlist2
    head2 = Node(2)
    a[1] = head2
    head2.next = Node(4)
    head2.next.next = Node(6)
    head2.next.next.next = Node(8)
    # Linkedlist3
    head3 = Node(0)
    a[2] = head3
    head3.next = Node(9)
    head3.next.next = Node(10)
    head3.next.next.next = Node(11)
    res = mergeKList(a, N)
    if res != None:
        printList(res)
