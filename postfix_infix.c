#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return '\0'; // Return null character for an empty stack
    }
    char value = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack* stack = createStack();
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];
        if (isOperator(ch)) {
            while (stack->top != NULL && precedence(stack->top->data) >= precedence(ch)) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        } else if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            while (stack->top != NULL && stack->top->data != '(') {
                postfix[j++] = pop(stack);
            }
            if (stack->top != NULL && stack->top->data == '(') {
                pop(stack);
            }
        } else {
            postfix[j++] = ch;
        }
        i++;
    }

    while (stack->top != NULL) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    char reversedInfix[strlen(infix) + 1];
    strcpy(reversedInfix, infix);
    reverseString(reversedInfix);

    char reversedPostfix[strlen(infix) + 1];
    infixToPostfix(reversedInfix, reversedPostfix);
    reverseString(reversedPostfix);
    strcpy(prefix, reversedPostfix);
}

int main() {
    char infix[100], postfix[100], prefix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
