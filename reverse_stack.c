#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

void reverseStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    int size = stack->top + 1;
    int temp[size];
    int i = 0;


    while (!isEmpty(stack)) {
        temp[i++] = pop(stack);
    }


    for (int j = size - 1; j >= 0; --j) {
        push(stack, temp[j]);
    }
}



int main() {
    struct Stack stack;
    initializeStack(&stack);

    int n, num;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements of the stack:\n",n);


    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        push(&stack, num);
    }

    reverseStack(&stack);

    printf("Reversed stack: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }

    return 0;
}
