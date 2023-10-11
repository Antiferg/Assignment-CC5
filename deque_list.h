#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

struct Deque {
    Node* front;
    Node* rear;
};

typedef struct Deque Deque;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

void pushFront(Deque* deque, int value) {
    Node* newNode = createNode(value);
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void pushRear(Deque* deque, int value) {
    Node* newNode = createNode(value);
    if (deque->rear == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int popFront(Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty. Cannot pop from the front.\n");
        return -1; 
    }

    int value = deque->front->data;
    Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL; 
    }
    free(temp);

    return value;
}

int popRear(Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty. Cannot pop from the rear.\n");
        return -1;
    }

    int value = deque->rear->data;
    Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL; 
    }
    free(temp);

    return value;
}

void displayDeque(Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    Node* temp = deque->front;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}