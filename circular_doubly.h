#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int value, int position) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        return newNode;
    }

    if (position == 1) {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp->next != head; ++i) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return head;
    }

    if (position == 1) {
        if (head->next == head) {
            free(head);
            return NULL;
        }
        Node* temp = head;
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
        free(temp);
        return head;
    }

    Node* temp = head;
    int i;
    for (i = 1; i < position && temp->next != head; ++i) {
        temp = temp->next;
    }

    if (temp->next == head) {
        printf("Invalid position. Deletion failed.\n");
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("Doubly Circular Linked List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

