#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct dynarrayStack {
    int top;
    int capacity;
    int *array;
};
typedef struct dynarrayStack dyaStack;


dyaStack* createStack() {
    dyaStack* S = (dyaStack*)malloc(sizeof(dyaStack));
    if (!S) {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }
    S->top = -1;
    S->capacity = 1;
    
    S->array = (int*)malloc(S->capacity * sizeof(int));
    if (!S->array) {
        printf("Memory Allocation Failed.\n");
        free(S);
        return NULL;
    }
    return S;
}


int isFull(dyaStack* S) {
    return (S->top == S->capacity - 1);
}


void doubleStack(dyaStack* S) {
    int* temp = realloc(S->array, S->capacity * 2 * sizeof(int));
    if (!temp) {
        printf("Memory Reallocation Failed. Stack Expansion Stopped.\n");
        return;
    }
    S->array = temp;
    S->capacity *= 2;

}

void push(dyaStack* S, int data) {
    if (isFull(S)) {
        doubleStack(S);
    }
    S->array[++S->top] = data;
}


int isEmpty(dyaStack* S) {
    return S->top == -1;
}

int pop(dyaStack* S) {
    if (isEmpty(S)) {
        printf("Stack Underflow. Cannot pop from an empty stack.\n");
        return INT_MIN;  
    }
    return S->array[S->top--];
}


int top(dyaStack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty. No top element.\n");
        return INT_MIN;
    }
    return S->array[S->top];
}

void print(dyaStack* S) {
    if (isEmpty(S)) {
        printf("Stack is Empty.\n");
        return;
    }
    int i;
    printf("Stack Elements: ");
    for ( i = 0; i <= S->top; i++) {
        printf("%d ", S->array[i]);
    }
    printf("\n");
}

void deleteStack(dyaStack* S) {
    if (S) {
        free(S->array);
        free(S);
        printf("Stack Deleted Successfully.\n");
    }
}

int main() {
    dyaStack* S = createStack();
    if (!S) return 1;

    while (1) {
        int ch;
        printf("\nAvailable Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print\n");
        printf("5. Delete Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        int val, pValue;
        switch (ch) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &val);
                push(S, val);
                break;

            case 2:
                pValue = pop(S);
                if (pValue != INT_MIN) 
                    printf("Popped Value: %d\n", pValue);
                break;

            case 3:
                pValue = top(S);
                if (pValue != INT_MIN) 
                    printf("Peek Element: %d\n", pValue);
                break;

            case 4:
                print(S);
                break;

            case 5:
                deleteStack(S);
                return 0; // Exit program after deleting stack

            case 6:
                printf("Program Exited.\n");
                deleteStack(S);
                return 0;

            default:
                printf("Invalid Operation. Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}
