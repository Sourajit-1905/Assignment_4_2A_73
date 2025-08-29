class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class Solution:
    def reverse(self, head):
        curnode = head
        prevnode = None
        while curnode:
            nextnode = curnode.next
            temp = curnode.next
            curnode.next = curnode.prev
            curnode.prev = temp
            prevnode = curnode
            curnode = curnode.prev
        head = prevnode
        return head

def print_list(head):
    result = []
    while head:
        result.append(str(head.data))
        head = head.next
    print(" <-> ".join(result))

node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)

node1.next = node2
node2.prev = node1
node2.next = node3
node3.prev = node2
node3.next = node4
node4.prev = node3

print("Original list:")
print_list(node1)

sol = Solution()
reversed_head = sol.reverse(node1)

print("Reversed list:")
print_list(reversed_head)