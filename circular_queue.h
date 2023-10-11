#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue element.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue element.\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}


