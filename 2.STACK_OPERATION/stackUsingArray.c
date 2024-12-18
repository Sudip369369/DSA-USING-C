#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MaxSize 3


// Stack structure definition
struct arrayStack {
    int top;
    int capacity;
    int *array;
};

// Function to create a new stack
struct arrayStack *createStack() {
    struct arrayStack *S = malloc(sizeof(struct arrayStack)); // Allocate memory for the stack
    if (!S) {
        return NULL; // Return NULL if memory allocation fails
    }
    S->capacity = MaxSize;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int)); // Allocate memory for the stack array
    if (!S->array) {
        free(S); // Free the stack structure if memory allocation fails for array
        return NULL;
    }
    return S;
}

// Function to check if the stack is empty
int isEmptyStack(struct arrayStack *S) {
    return (S->top == -1); // Stack is empty if top is -1
}

// Function to check if the stack is full
int isFullStack(struct arrayStack *S) {
    return (S->top == S->capacity - 1); // Stack is full if top is at capacity - 1
}

// Function to push an element onto the stack
void push(struct arrayStack *S, int data) {
    if (isFullStack(S)) {
        printf("Stack Overflow\n");
    } else {
        S->array[++S->top] = data; // Push data onto the stack and increment top
        printf("Pushed %d onto the stack.\n", data);
    }
}

// Function to pop an element from the stack
int pop(struct arrayStack *S) {
    if (isEmptyStack(S)) {
        printf("Stack is Empty\n");
        return INT_MIN; // Return INT_MIN if the stack is empty
    } else {
        int poppedValue = S->array[S->top--]; // Return the top element and decrement top
        return poppedValue;
    }
}

// Function to delete the stack and free memory
void deleteStack(struct arrayStack *S) {
    if (S) {
        if (S->array) {
            free(S->array); // Free the array memory
        }
        free(S); // Free the stack structure memory
    }
}

// Function to print the stack for testing
void printStack(struct arrayStack *S) {
	int i;
    if (isEmptyStack(S)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for ( i = 0; i <= S->top; i++) {
        printf("%d ", S->array[i]);
    }
    printf("\n");
}

int main() {
    struct arrayStack *stack = createStack(); // Create a new stack
    if (!stack) {
        printf("Stack creation failed.\n");
        return -1;
    }

    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to push onto the stack: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data != INT_MIN) {
                    printf("Popped value: %d\n", data);
                }
                break;
            case 3:
                printStack(stack);
                break;
            case 4:
                printf("Exiting program.\n");
                deleteStack(stack); // Clean up and free memory
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}