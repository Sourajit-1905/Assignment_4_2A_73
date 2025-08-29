#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int new_data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = new_data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

struct Node *insertAtFront(struct Node *head, int new_data) {

    struct Node *newnode = createNode(new_data);

    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }

    return newnode;
}


void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {


    struct Node *head = createNode(2);
    head->next = createNode(3);
    head->next->prev = head;
    head->next->next = createNode(4);
    head->next->next->prev = head->next;

    printf("Original Linked List:");
    printList(head);

    printf("After inserting Node at the front:");
    int data = 1;
    head = insertAtFront(head, data);

    printList(head);

    return 0;
}