#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createLinkedList(int values[], int size) {
    if (size == 0)
        return NULL;

    struct Node* head = createNode(values[0]);
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(values[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* pairwiseSwap(struct Node* head) {
    struct Node* first = head;
    struct Node* second = head ? head->next : NULL;

    while (first && second) {
        int temp = first->data;
        first->data = second->data;
        second->data = temp;

        first = second->next;
        if (first)
            second = first->next;
        else
            break;
    }

    return head;
}

int main() {
    int values[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(values) / sizeof(values[0]);

    struct Node* head = createLinkedList(values, size);

    printf("Original list:\n");
    printLinkedList(head);

    head = pairwiseSwap(head);

    printf("After pairwise swap:\n");
    printLinkedList(head);

    return 0;
}