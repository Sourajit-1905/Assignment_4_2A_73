#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

Node* reverse(Node* head) {
    Node* curnode = head;
    Node* prevnode = NULL;

    while (curnode) {
        Node* temp = curnode->next;
        curnode->next = curnode->prev;
        curnode->prev = temp;
        prevnode = curnode;
        curnode = curnode->prev;
    }

    head = prevnode;
    return head;
}

int main() {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;

    printf("Original list:\n");
    printList(node1);

    Node* reversedHead = reverse(node1);

    printf("Reversed list:\n");
    printList(reversedHead);

    return 0;
}