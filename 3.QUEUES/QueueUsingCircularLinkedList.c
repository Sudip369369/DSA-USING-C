#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* rear;
};

// Function to create a new queue
struct Queue* CreateQueue() {
    struct Queue* Q = malloc(sizeof(struct Queue));
    Q->rear = NULL;
    return Q;
}

// Check if the queue is empty
int isEmpty(struct Queue* Q) {
    return (Q->rear == NULL);
}

// EnQueue operation
void EnQueue(struct Queue* Q, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (isEmpty(Q)) {
        newNode->next = newNode;
        Q->rear = newNode;
    } else {
        newNode->next = Q->rear->next;
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

    printf("Enqueued: %d\n", value);
}

// DeQueue operation
int DeQueue(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct Node* front = Q->rear->next;
    int data = front->data;

    if (Q->rear == front) {  // Only one element
        free(front);
        Q->rear = NULL;
    } else {
        Q->rear->next = front->next;
        free(front);
    }

    return data;
}

// Print the queue
void PrintQueue(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = Q->rear->next;
    printf("Queue: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != Q->rear->next);
    printf(" (back to front)\n");
}

// Delete the entire queue
void DeleteQueue(struct Queue* Q) {
    if (isEmpty(Q)) return;

    struct Node* temp = Q->rear->next;
    struct Node* current;

    while (temp != Q->rear) {
        current = temp;
        temp = temp->next;
        free(current);
    }
    free(Q->rear);
    Q->rear = NULL;
    printf("Queue deleted.\n");
}

// Main
int main() {
    struct Queue* Q = CreateQueue();

    EnQueue(Q, 10);
    EnQueue(Q, 20);
    EnQueue(Q, 30);

    PrintQueue(Q);

    printf("Dequeued: %d\n", DeQueue(Q));
    PrintQueue(Q);

    DeleteQueue(Q);

    return 0;
}

