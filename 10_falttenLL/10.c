#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->bottom = NULL;
    return newNode;
}

struct Node* merge2Lists(struct Node* head1, struct Node* head2) {
    struct Node dummy;
    struct Node* temp = &dummy;
    dummy.bottom = NULL;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            temp->bottom = head1;
            head1 = head1->bottom;
        } else {
            temp->bottom = head2;
            head2 = head2->bottom;
        }
        temp = temp->bottom;
        temp->next = NULL;
    }

    if (head1)
        temp->bottom = head1;
    else
        temp->bottom = head2;

    return dummy.bottom;
}

struct Node* flatten(struct Node* head) {
    if (!head || !head->next)
        return head;

    head->next = flatten(head->next);
    head = merge2Lists(head, head->next);

    return head;
}

struct Node* buildLinkedList(int arr[][10], int sizes[], int n) {
    if (n == 0)
        return NULL;

    struct Node* head = createNode(arr[0][0]);
    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i][0]);
        current = current->next;
    }

    current = head;
    for (int i = 0; i < n; i++) {
        struct Node* bottomCurrent = current;
        for (int j = 1; j < sizes[i]; j++) {
            bottomCurrent->bottom = createNode(arr[i][j]);
            bottomCurrent = bottomCurrent->bottom;
        }
        current = current->next;
    }

    return head;
}

void printFlattenedList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->bottom;
    }
    printf("None\n");
}

int main() {
    int arr[4][10] = {
        {5, 7, 8, 30},
        {10, 20},
        {19, 22, 50},
        {28, 35, 40, 45}
    };
    int sizes[4] = {4, 2, 3, 4};

    struct Node* head = buildLinkedList(arr, sizes, 4);
    struct Node* flattenedHead = flatten(head);
    printf("Flattened linked list:\n");
    printFlattenedList(flattenedHead);

    return 0;
}