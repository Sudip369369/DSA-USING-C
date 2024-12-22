#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to check if the stack is empty
int isEmptyStack(Stack* stack) {
    return stack->top == NULL;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        fprintf(stderr, "Stack underflow.\n");
        return INT_MIN; // Return INT_MIN to indicate an error
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to get the top element of the stack
int top(Stack* stack) {
    if (isEmptyStack(stack)) {
        fprintf(stderr, "Stack is empty.\n");
        return INT_MIN; // Return INT_MIN to indicate an error
    }
    return stack->top->data;
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current = stack->top;
    printf("Stack elements: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete the entire stack
void deleteStack(Stack* stack) {
    Node* current = stack->top;
    Node* nextNode;
    while (current) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(stack);
}

int main() {
Stack* stack = createStack();
    if (!stack) return 1;

    char operation[10];
    int value;

    printf("Available operations: push <value>, pop, print, end\n");
    while (1) {
        printf("Enter operation: ");
        scanf("%s", operation);

        if (strcmp(operation, "push") == 0) {
            scanf("%d", &value);
            push(stack, value);
        } else if (strcmp(operation, "pop") == 0) {
            int poppedValue = pop(stack);
            if (poppedValue != INT_MIN) {
                printf("Popped: %d\n", poppedValue);
            }
        } else if (strcmp(operation, "print") == 0) {
            printStack(stack);
        } else if (strcmp(operation, "end") == 0) {
            break;
        } else {
            printf("Invalid operation. Try again.\n");
        }
    }
    deleteStack(stack);
    printf("Stack deleted and program ended.\n");
    return 0;
}
