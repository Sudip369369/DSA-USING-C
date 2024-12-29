#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CAPACITY 6
// Define the Queue structure
typedef struct ArrayQueue {
    int front, rear, capacity;
    int *array;
} ArrayQueue;

// Function to create a queue
ArrayQueue* createQueue(int capacity) {
    ArrayQueue* Q = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    if (!Q) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    Q->capacity = capacity;
    Q->front = -1;
    Q->rear = -1;
    Q->array = (int*)malloc(capacity * sizeof(int));
    if (!Q->array) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(Q);
        return NULL;
    }
    return Q;
}

// Function to check if the queue is empty
int isEmpty(ArrayQueue* Q) {
    return (Q->front == -1);
}

// Function to check if the queue is full
int isFull(ArrayQueue* Q) {
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

// Function to get the current size of the queue
int queueSize(ArrayQueue* Q) {
    if (isEmpty(Q)) return 0;
    return (Q->rear - Q->front + Q->capacity) % Q->capacity + 1;
}

// Function to enqueue an element
void enqueue(ArrayQueue* Q, int data) {
    if (isFull(Q)) {
        printf("Queue Overflow. Cannot enqueue %d.\n", data);
        return;
    }
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if (Q->front == -1) { // Set front if this is the first element
        Q->front = Q->rear;
    }
}

// Function to dequeue an element
int dequeue(ArrayQueue* Q) {
    if (isEmpty(Q)) {
        printf("Queue Underflow. Cannot dequeue.\n");
        return -1; // Error value
    }
    int data = Q->array[Q->front];
    if (Q->front == Q->rear) { // Queue becomes empty
        Q->front = Q->rear = -1;
    } else {
        Q->front = (Q->front + 1) % Q->capacity;
    }
    return data;
}

// Function to get the front element
int front(ArrayQueue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return -1; // Error value
    }
    return Q->array[Q->front];
}

// Function to get the rear element
int rear(ArrayQueue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return -1; // Error value
    }
    return Q->array[Q->rear];
}

// Function to print the queue
void printQueue(ArrayQueue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int size = queueSize(Q);
    int i;
    for ( i = 0; i < size; i++) {
        printf("%d ", Q->array[(Q->front + i) % Q->capacity]);
    }
    printf("\n");
}

// Function to delete the queue
void deleteQueue(ArrayQueue* Q) {
    if (Q) {
        if (Q->array) free(Q->array);
        free(Q);
    }
}

// Main function for demonstration
int main() {
      int capacity = MAX_CAPACITY;
    ArrayQueue* queue = createQueue(capacity);
    if (!queue) return -1;

    char operation[15];
    int value;

    printf("Available operations: enqueue <value>, dequeue, print, get_front, get_rear, get_size, end\n");
    while (1) {
        printf("Enter operation: ");
        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(queue, value);
        } else if (strcmp(operation, "dequeue") == 0) {
            int dequeuedValue = dequeue(queue);
            if (dequeuedValue != -1) { // Assuming -1 is the error value for empty queue
                printf("Dequeued: %d\n", dequeuedValue);
            }
        } else if (strcmp(operation, "print") == 0) {
            printQueue(queue);
        } else if (strcmp(operation, "get_front") == 0) {
            int frontValue = front(queue);
            if (frontValue != -1) { // Assuming -1 is the error value for empty queue
                printf("Front: %d\n", frontValue);
            }
        } else if (strcmp(operation, "get_rear") == 0) {
            int rearValue = rear(queue);
            if (rearValue != -1) { // Assuming -1 is the error value for empty queue
                printf("Rear: %d\n", rearValue);
            }
        } else if (strcmp(operation, "get_size") == 0) {
            printf("Queue size: %d\n", queueSize(queue));
        } else if (strcmp(operation, "end") == 0) {
            break;
        } else {
            printf("Invalid operation. Try again.\n");
        }
    }
    deleteQueue(queue);
    printf("Queue deleted and program ended.\n");
    return 0;
}
