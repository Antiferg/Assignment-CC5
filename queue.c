#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    Queue* queue = createQueue();
    int choice, value;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);


    while (queue->front != NULL) {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);

    return 0;
}
