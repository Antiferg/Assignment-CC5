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
    newNode->next = NULL;
    return newNode;
}

Node* push(Node* top, int value) {
    Node* newNode = createNode(value);
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top) {
    if (top == NULL) {
        printf("Stack is empty. Pop operation failed.\n");
        return top;
    }

    Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void displayStack(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    Node* top = NULL;
    int choice, value;

    do {
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                displayStack(top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}
