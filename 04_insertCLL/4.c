#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_circular_linked_list(int values[], int size) {
    if (size == 0) return NULL;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = values[0];
    struct Node* temp = head;

    for (int i = 1; i < size; i++) {
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp = temp->next;
        temp->data = values[i];
    }

    temp->next = head;
    return head;
}

void print_circular_linked_list(struct Node* head, int count) {
    struct Node* temp = head;
    for (int i = 0; i < count; i++) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("(back to head)\n");
}

struct Node* insert_node_at_pos(struct Node* head, int pos, int x) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;

    if (pos == 0) {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        return newnode;
    }

    struct Node* temp = head;
    int i = 1;
    while (i < pos && temp->next != head) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

int main() {
    int values[] = {10, 20, 30, 40};
    int size = sizeof(values) / sizeof(values[0]);

    struct Node* head = create_circular_linked_list(values, size);
    printf("Original Circular Linked List:\n");
    print_circular_linked_list(head, size);

    int pos = 2;
    int x = 25;
    head = insert_node_at_pos(head, pos, x);

    printf("\nAfter inserting %d at position %d:\n", x, pos);
    print_circular_linked_list(head, size + 1);

    return 0;
}