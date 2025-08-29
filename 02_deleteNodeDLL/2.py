class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" <-> " if temp.next else "\n")
        temp = temp.next

def createDoublyLinkedList(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        new_node = Node(val)
        current.next = new_node
        new_node.prev = current
        current = new_node
    return head

class Solution:
    def delPos(self, head, x):
        if x == 1:
            if head is None:
                return None
            new_head = head.next
            if new_head:
                new_head.prev = None
            return new_head

        temp = head
        i = 1

        while temp and i < x:
            temp = temp.next
            i += 1

        if temp is None:
            return head

        if temp.prev:
            temp.prev.next = temp.next
        if temp.next:
            temp.next.prev = temp.prev

        return head

values = [10, 20, 30, 40, 50]
head = createDoublyLinkedList(values)

print("Original list:")
printList(head)

position_to_delete = 3
sol = Solution()
head = sol.delPos(head, position_to_delete)

print(f"\nList after deleting position {position_to_delete}:")
printList(head)