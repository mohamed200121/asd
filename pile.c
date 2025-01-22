#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the stack

// Define the stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1; // Stack is empty
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("Pushed %d to the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Return an invalid value
    } else {
        int value = stack->items[stack->top];
        stack->top--;
        printf("Popped %d from the stack.\n", value);
        return value;
    }
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No top element.\n");
        return -1; // Return an invalid value
    } else {
        return stack->items[stack->top];
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);

    printf("Top element after pops: %d\n", peek(&stack));

    pop(&stack); // Try to pop from an empty stack

    return 0;
}