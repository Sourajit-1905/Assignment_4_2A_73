class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def insert_node_at_pos(self, head, pos, x):
        newnode = Node(x)
        if pos == 0:
            temp = head
            while temp.next != head:
                temp = temp.next
            temp.next = newnode
            newnode.next = head
            return newnode
        temp = head
        i = 1
        while i < pos and temp.next != head:
            temp = temp.next
            i += 1
        newnode.next = temp.next
        temp.next = newnode
        return head

def create_circular_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    temp = head
    for val in values[1:]:
        temp.next = Node(val)
        temp = temp.next
    temp.next = head
    return head

def print_circular_linked_list(head, count):
    temp = head
    for _ in range(count):
        print(temp.data, end=" -> ")
        temp = temp.next
    print("(back to head)")

values = [10, 20, 30, 40]
head = create_circular_linked_list(values)
print("Original Circular Linked List:")
print_circular_linked_list(head, len(values))

sol = Solution()
pos = 2
x = 25
head = sol.insert_node_at_pos(head, pos, x)

print(f"\nAfter inserting {x} at position {pos}:")
print_circular_linked_list(head, len(values) + 1)