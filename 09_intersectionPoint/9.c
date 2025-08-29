#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int findLength(struct Node* head) {
    int i = 0;
    struct Node* temp = head;
    while (temp) {
        i++;
        temp = temp->next;
    }
    return i;
}

struct Node* intersectPoint(struct Node* head1, struct Node* head2) {
    int len1 = findLength(head1);
    int len2 = findLength(head2);

    struct Node* higher = len1 > len2 ? head1 : head2;
    struct Node* lower = len1 > len2 ? head2 : head1;

    for (int i = 0; i < abs(len1 - len2); i++) {
        higher = higher->next;
    }

    while (higher && lower) {
        if (higher == lower)
            return higher;
        higher = higher->next;
        lower = lower->next;
    }

    return NULL;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("None\n");
}

int main() {
    struct Node* intersect = (struct Node*)malloc(sizeof(struct Node));
    intersect->data = 8;
    intersect->next = (struct Node*)malloc(sizeof(struct Node));
    intersect->next->data = 10;
    intersect->next->next = NULL;

    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 3;
    head1->next = (struct Node*)malloc(sizeof(struct Node));
    head1->next->data = 6;
    head1->next->next = (struct Node*)malloc(sizeof(struct Node));
    head1->next->next->data = 9;
    head1->next->next->next = intersect;

    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    head2->data = 4;
    head2->next = intersect;

    printf("List 1:\n");
    printList(head1);
    printf("List 2:\n");
    printList(head2);

    struct Node* result = intersectPoint(head1, head2);

    if (result)
        printf("Intersection at node with data: %d\n", result->data);
    else
        printf("No intersection found.\n");

    return 0;
}