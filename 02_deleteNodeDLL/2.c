#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* delPos(struct Node* head, int x) {
    if (head == NULL || x <= 0) return head;

    if (x == 1) {
        struct Node* newHead = head->next;
        if (newHead) newHead->prev = NULL;
        free(head);
        return newHead;
    }

    struct Node* temp = head;
    int i = 1;

    while (temp && i < x) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) return head;

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    free(temp);
    return head;
}

struct Node* createList(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* head = createNode(arr[0]);
    struct Node* current = head;
    for (int i = 1; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = createList(arr, n);

    printf("Original list:\n");
    printList(head);

    int position = 3;
    head = delPos(head, position);

    printf("\nList after deleting position %d:\n", position);
    printList(head);

    return 0;
}