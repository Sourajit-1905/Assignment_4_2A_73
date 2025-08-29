class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def pairwiseSwap(self, head):
        first = head
        second = head.next

        while first and second:
            temp = first.data
            first.data = second.data
            second.data = temp

            first = second.next
            if first:
                second = first.next
            else:
                break

        return head

def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

values = [1, 2, 3, 4, 5, 6]
head = create_linked_list(values)

print("Original list:")
print_linked_list(head)

sol = Solution()
swapped_head = sol.pairwiseSwap(head)

print("After pairwise swap:")
print_linked_list(swapped_head)