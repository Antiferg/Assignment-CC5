#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int deque[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at front.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        deque[front] = value;
        printf("Inserted at front: %d\n", value);
    }
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at rear.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("Inserted at rear: %d\n", value);
    }
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from front.\n");
    } else {
        printf("Deleted from front: %d\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from rear.\n");
    } else {
        printf("Deleted from rear: %d\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        do {
            printf("%d ", deque[i]);
            if (i == MAX_SIZE - 1) {
                i = 0;
            } else {
                i++;
            }
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}


