#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct CircularQueue {
    Node* front;
    Node* rear;
};

typedef struct CircularQueue CircularQueue;

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

CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(CircularQueue* queue, int value) {
    Node* newNode = createNode(value);
    if (queue->rear == NULL) {
        newNode->next = newNode;
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        newNode->next = queue->front; 
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value;
    Node* temp = queue->front;
    if (queue->front == queue->rear) {

        value = temp->data;
        queue->front = NULL;
        queue->rear = NULL;
    } else {

        value = temp->data;
        queue->front = queue->front->next;
        queue->rear->next = queue->front; 
    }
    free(temp);

    return value;
}

void displayQueue(CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = queue->front;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf(" (Circular)\n");
}


