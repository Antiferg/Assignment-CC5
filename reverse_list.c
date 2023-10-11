#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"


Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev; 
}

int main() {
    int value;
    char choice;
    int i=1;
    Node* head=NULL;

    do {
        printf("Enter a number: ");
        scanf("%d", &value);
        head=insertNode(&head,value,i++);
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Original ");
    displayList(head);

    head = reverseList(head); 

    printf("Reversed ");
    displayList(head);


    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
