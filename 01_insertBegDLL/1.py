class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

def create_node(data):
    return Node(data)

def insert_at_front(head, data):
    new_node = create_node(data)
    new_node.next = head
    if head is not None:
        head.prev = new_node
    return new_node

def print_list(head):
    temp = head
    while temp:
        print(temp.data, end=' ')
        temp = temp.next
    print()

head = create_node(2)
second = create_node(3)
third = create_node(4)

head.next = second
second.prev = head
second.next = third
third.prev = second

print("Original Linked List:")
print_list(head)

print("After inserting Node at the front:")
head = insert_at_front(head, 1)
print_list(head)