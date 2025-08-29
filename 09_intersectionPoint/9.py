class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def findLength(self, head):
        i = 0
        temp = head
        while temp:
            i += 1
            temp = temp.next
        return i

    def intersectPoint(self, head1, head2):
        len1 = self.findLength(head1)
        len2 = self.findLength(head2)

        higher = head1 if len1 > len2 else head2
        lower = head2 if len1 > len2 else head1

        for _ in range(abs(len1 - len2)):
            higher = higher.next

        while higher and lower:
            if higher == lower:
                return higher
            higher = higher.next
            lower = lower.next

        return None

def printList(head):
    while head:
        print(head.data, end=" -> ")
        head = head.next
    print("None")

intersect = Node(8)
intersect.next = Node(10)

head1 = Node(3)
head1.next = Node(6)
head1.next.next = Node(9)
head1.next.next.next = intersect

head2 = Node(4)
head2.next = intersect

print("List 1:")
printList(head1)
print("List 2:")
printList(head2)

sol = Solution()
result = sol.intersectPoint(head1, head2)

if result:
    print(f"Intersection at node with data: {result.data}")
else:
    print("No intersection found.")