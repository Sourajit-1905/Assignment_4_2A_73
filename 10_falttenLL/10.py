class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.bottom = None

class Solution:
    def merge2Lists(self, head1, head2):
        dummy = Node(-1)
        temp = dummy

        while head1 and head2:
            if head1.data < head2.data:
                temp.bottom = head1
                head1 = head1.bottom
            else:
                temp.bottom = head2
                head2 = head2.bottom
            temp = temp.bottom
            temp.next = None

        if head1:
            temp.bottom = head1
        else:
            temp.bottom = head2

        return dummy.bottom

    def flatten(self, head):
        if not head or not head.next:
            return head

        head.next = self.flatten(head.next)
        head = self.merge2Lists(head, head.next)

        return head

def build_linked_list(arr):
    if not arr:
        return None

    head = Node(arr[0][0])
    current = head
    for i in range(1, len(arr)):
        current.next = Node(arr[i][0])
        current = current.next

    current = head
    for sublist in arr:
        bottom_current = current
        for val in sublist[1:]:
            bottom_current.bottom = Node(val)
            bottom_current = bottom_current.bottom
        current = current.next

    return head

def print_flattened_list(head):
    while head:
        print(head.data, end=" -> ")
        head = head.bottom
    print("None")

if __name__ == "__main__":
    arr = [
        [5, 7, 8, 30],
        [10, 20],
        [19, 22, 50],
        [28, 35, 40, 45]
    ]

    head = build_linked_list(arr)
    sol = Solution()
    flattened_head = sol.flatten(head)
    print("Flattened linked list:")
    print_flattened_list(flattened_head)