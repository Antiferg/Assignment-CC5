#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"

int main() {
    Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertNode(&head, value, position);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}