#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node** head, int value, int position) {
    Node* newNode = createNode(value);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; ++i) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position. Insertion failed.\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return *head;
}

Node* deleteNode(Node* head, int value) {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return head;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node with value %d deleted successfully.\n", value);
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node with value %d not found in the list. Deletion failed.\n", value);
    } else {
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        free(deleteNode);
        printf("Node with value %d deleted successfully.\n", value);
    }

    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

