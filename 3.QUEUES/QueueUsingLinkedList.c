#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct Queue {
    struct ListNode *front, *rear;
};

struct Queue* CreateQueue() {
    struct Queue* Q;
    Q = malloc(sizeof(struct Queue));
    Q->front = Q->rear = NULL;
    return Q;
}
int IsEmptyQueue(struct Queue *Q) {
    return (Q->front == NULL);
}
void EnQueue(struct Queue *Q, int data) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;

    if (Q->rear == NULL) { // Queue is empty
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

int DeQueue(struct Queue *Q) {
    if (IsEmptyQueue(Q)) return -1;

    struct ListNode* temp = Q->front;
    int data = temp->data;

    Q->front = Q->front->next;
    if (Q->front == NULL) Q->rear = NULL;

    free(temp);
    return data;
}

void DeleteQueue(struct Queue *Q) {
    struct ListNode* temp;
    while (Q->front != NULL) {
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);
}

// Print function to display queue
void PrintQueue(struct Queue* Q) {
    struct ListNode* temp = Q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test
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

