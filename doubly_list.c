#include <stdio.h>
#include <stdlib.h>
#include "doubly_list.h"


int main() {
    Node* head = NULL;
    int choice, position, value;

    do {
        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertNode(head, value, position);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteNode(head, position);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
