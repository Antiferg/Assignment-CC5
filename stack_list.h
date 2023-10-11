#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100


struct Stack {
    int top;
    int items[MAX_SIZE];
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->items[++stack->top] = item;
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}




