class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def isCircular(self, head):
        fast = head
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

            if fast == slow:
                return True

        return False

def create_linked_list_with_cycle(values, pos):
    if not values:
        return None

    head = Node(values[0])
    current = head
    cycle_node = None

    for i in range(1, len(values)):
        current.next = Node(values[i])
        current = current.next
        if i == pos:
            cycle_node = current

    if pos != -1:
        current.next = cycle_node

    return head

values = [1, 2, 3, 4, 5]
cycle_position = 2
head = create_linked_list_with_cycle(values, cycle_position)

sol = Solution()
print("Is Circular:", sol.isCircular(head))