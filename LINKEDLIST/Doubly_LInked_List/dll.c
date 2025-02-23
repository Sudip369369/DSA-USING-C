#include <stdio.h>
#include <stdlib.h>


struct DLLNode {
    int data;
    struct DLLNode *prev, *next;
};

void DLLInsert(struct DLLNode **head, int data, int position) {

    struct DLLNode *newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    if (!newNode) {  
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;

    // Insert at the beginning
    if (position == 1) {
        newNode->next = *head;
        if (*head) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }


    struct DLLNode *temp = *head;
    int k = 1;
    while (temp && k < position - 1) {
        temp = temp->next;
        k++;
    }

 
    if (!temp) {
        printf("Invalid position! Position out of range.\n");
        free(newNode);
        return;
    }


    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void printList(struct DLLNode *head) {
    struct DLLNode *temp = head;
    printf("Doubly Linked List: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct DLLNode *head = NULL;


    DLLInsert(&head, 10, 1); 
    DLLInsert(&head, 20, 2);
    DLLInsert(&head, 30, 3);  
    DLLInsert(&head, 15, 2); 
    printList(head);

    return 0;
}
