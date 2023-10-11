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

        return newNode;
    }

    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp->next != NULL; ++i) {
        temp = temp->next;
    }

    if (i != position - 1) {
        printf("Invalid position. Insertion failed.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteNode(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return head;
    }

    Node* temp = head;
    if (position == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    int i;
    for (i = 1; i < position && temp != NULL; ++i) {
        temp = temp->next;
    }

    if (i != position || temp == NULL) {
        printf("Invalid position. Deletion failed.\n");
        return head;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

void displayList(Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


