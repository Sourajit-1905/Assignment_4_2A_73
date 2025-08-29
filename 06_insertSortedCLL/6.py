class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def sortedInsert(self, head, data):
        newnode = Node(data)

        if not head:
            newnode.next = newnode
            return newnode

        current = head
        while True:
            if current.data <= data <= current.next.data:
                break

            if current.data > current.next.data and (data < current.next.data or data > current.data):
                break

            current = current.next
            if current == head:
                break

        newnode.next = current.next
        current.next = newnode

        if data < head.data:
            return newnode
        else:
            return head

def printList(head):
    if not head:
        print("List is empty.")
        return
    result = []
    current = head
    while True:
        result.append(str(current.data))
        current = current.next
        if current == head:
            break
    print(" -> ".join(result) + " -> ... (circular)")

sol = Solution()

head = Node(10)
node2 = Node(20)
node3 = Node(30)
head.next = node2
node2.next = node3
node3.next = head  

print("Original list:")
printList(head)

for val in [5, 25, 35]:
    head = sol.sortedInsert(head, val)
    print(f"\nAfter inserting {val}:")
    printList(head)