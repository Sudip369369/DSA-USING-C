#include <stdio.h>
#include <stdlib.h> 
#define MAXQUEUE 2

typedef struct Queue {
    int rear, front;
    int Array[MAXQUEUE];
} Queue;

// Function to initialize the queue
void createQueue(Queue* Q) {
    Q->front = Q->rear = -1;
}


// Function to check if the queue is empty
int isEmpty(Queue* Q) {
    return (Q->front == -1);
}

// Function to check if the queue is full
int isFull(Queue* Q) {
    return (Q->rear == MAXQUEUE - 1);
}

// Function to make the queue Empty 
void makeEmpty(Queue* Q){
	Q->rear = Q->front = -1;
}

// Function to add an element to the queue
void enqueue(Queue* Q, int data) {
    if (isFull(Q)) {
        printf("\nQueue overflow.\n");
        return;
    }
    if (isEmpty(Q)) {
        Q->front = 0; // Set front to 0 for the first element
    }
    Q->rear++;
    Q->Array[Q->rear] = data;
    printf("\nEnqueued: %d\n", data);
}

// Function to remove an element from the queue
int dequeue(Queue* Q) {
    if (isEmpty(Q)) {
        printf("\nQueue underflow.\n");
        return -1;
    }
    int dequeuedData = Q->Array[Q->front];
    if (Q->front == Q->rear) {
        // Reset queue to empty state
        Q->front = Q->rear = -1;
    } else {
        Q->front++;
    }
    return dequeuedData;
}

// Function to Display the Data 
void displayQueue(Queue* Q) {
	int i;
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return;
    }
 
    printf("Queue elements: ");
    for ( i = Q->front; i <= Q->rear; i++) {
        printf("%d ", Q->Array[i]);
    }
    printf("\n");
}
int main() {
    Queue Q;
    createQueue(&Q);

    int opr, data;

    while (1) {
        printf("\nEnter the operation:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Make empty");
        printf("\n4. Print");
        printf("\n5. End");
        printf("\nYour choice: ");
        scanf("%d", &opr);

        switch (opr) {
            case 1:
                printf("\nEnter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(&Q, data);
                break;

            case 2:
                if (!isEmpty(&Q)) {
                    printf("\nDequeued: %d\n", dequeue(&Q));
                }
                break;

            case 3:
            	makeEmpty(&Q);
            	break;
            case 4: 
                 displayQueue(&Q); 
                break;
            case 5: 
                printf("\nExiting the program.\n");
                return 0;
            default:
                printf("\nEnter a valid operation.\n");
        }
    }
    return 0;
}