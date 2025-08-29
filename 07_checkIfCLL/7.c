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

int isCircular(struct Node* head) {
    struct Node* fast = head;
    struct Node* slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return 1;
    }

    return 0;
}

struct Node* createLinkedListWithCycle(int values[], int size, int pos) {
    if (size == 0)
        return NULL;

    struct Node* head = createNode(values[0]);
    struct Node* current = head;
    struct Node* cycleNode = NULL;

    for (int i = 1; i < size; i++) {
        current->next = createNode(values[i]);
        current = current->next;
        if (i == pos)
            cycleNode = current;
    }

    if (pos != -1)
        current->next = cycleNode;

    return head;
}

int main() {
    int values[] = {1, 2, 3, 4, 5};
    int cycle_position = 2;
    int size = sizeof(values) / sizeof(values[0]);

    struct Node* head = createLinkedListWithCycle(values, size, cycle_position);

    if (isCircular(head))
        printf("Is Circular: true\n");
    else
        printf("Is Circular: false\n");

    return 0;
}