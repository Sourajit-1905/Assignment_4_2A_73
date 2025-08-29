#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Node* sortedInsert(struct Node* head, int data) {
    struct Node* newnode = createNode(data);

    if (head == NULL) {
        newnode->next = newnode;
        return newnode;
    }

    struct Node* current = head;

    while (1) {
        if (current->data <= data && data <= current->next->data) {
            break;
        }

        if (current->data > current->next->data &&
            (data < current->next->data || data > current->data)) {
            break;
        }

        current = current->next;

        if (current == head)
            break;
    }

    newnode->next = current->next;
    current->next = newnode;

    if (data < head->data)
        return newnode;
    else
        return head;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("... (circular)\n");
}

int main() {
    struct Node* head = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);

    head->next = node2;
    node2->next = node3;
    node3->next = head;

    printf("Original list:\n");
    printList(head);

    int values[] = {5, 25, 35};
    for (int i = 0; i < 3; i++) {
        head = sortedInsert(head, values[i]);
        printf("\nAfter inserting %d:\n", values[i]);
        printList(head);
    }

    return 0;
}