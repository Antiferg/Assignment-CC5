#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}

Node* insertNode(Node* head, int value, int position) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }

    if (position == 1) {
        newNode->next = head->next;
        head->next = newNode;
        return head;
    }

    Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp->next != head; ++i) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return head;
    }

    if (position == 1) {
        Node* temp = head->next;
        if (temp == head) {

            free(head);
            return NULL;
        }
        head->next = temp->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp->next != head; ++i) {
        temp = temp->next;
    }

    if (temp->next == head) {
        printf("Invalid position. Deletion failed.\n");
        return head;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    return head;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf(" (head)\n");
}

