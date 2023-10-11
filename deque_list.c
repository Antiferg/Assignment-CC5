#include <stdio.h>
#include <stdlib.h>
#include "deque_list.h"

int main() {
    Deque* deque = createDeque();
    int choice, value;

    do {
        printf("1. Push Front\n");
        printf("2. Push Rear\n");
        printf("3. Pop Front\n");
        printf("4. Pop Rear\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                pushFront(deque, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                pushRear(deque, value);
                break;
            case 3:
                value = popFront(deque);
                if (value != -1) {
                    printf("Popped element from the front: %d\n", value);
                }
                break;
            case 4:
                value = popRear(deque);
                if (value != -1) {
                    printf("Popped element from the rear: %d\n", value);
                }
                break;
            case 5:
                displayDeque(deque);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    Node* temp;
    while (deque->front != NULL) {
        temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
    free(deque);

    return 0;
}
