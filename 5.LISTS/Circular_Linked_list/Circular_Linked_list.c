#include <stdio.h>
#include <stdlib.h>

typedef struct CLLNode{
    int data;
    struct CLLNode* next;  
} CLLNode;

int CircularListLength(CLLNode *head) {
    if(!head)
        return 0;
    
    CLLNode* current = head;
    int count = 0;
    
    do {
        current = current->next;
        count++;
    } while(current != head);

    return count;  
}

void CircularListPrint(CLLNode *head) {
    if(!head) {
        printf("List is empty\n");
        return;  
    }
    
    CLLNode* current = head;
    printf("Circular List Elements: ");
    
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while(current != head);
    // Shows circular nature
    printf("%d (back to start)\n", head->data);  
}

void InsertAtEndInCLL(CLLNode **head, int data) {
    CLLNode *newNode = (CLLNode *) malloc(sizeof(CLLNode));
    if(!newNode) {
        printf("Memory Error\n");
        return;
    }
    
    newNode->data = data;
    newNode->next = newNode;  // Point to itself initially
    
    if(*head == NULL) {

        *head = newNode;
        return;
    }
    
    CLLNode *current = *head;
    while (current->next != *head)
        current = current->next;
    
    newNode->next = *head;
    current->next = newNode;
}

void InsertAtBeginInCLL(CLLNode **head, int data) {
    CLLNode *newNode = (CLLNode *) malloc(sizeof(CLLNode));
    if(!newNode) {
        printf("Memory Error\n");
        return;
    }
    
    newNode->data = data;
    
    if(*head == NULL) {
        
        newNode->next = newNode;  // Point to itself
        *head = newNode;
        return;
    }
    
    CLLNode *current = *head;
    while(current->next != *head)
        current = current->next;
    
    newNode->next = *head;
    current->next = newNode;
    *head = newNode; 
}

void DeleteNodeInCLL(CLLNode **head, int position) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    CLLNode *current = *head, *temp;
    
    // Only one node in the list
    if((*head)->next == *head && position == 1) {
        free(*head);
        *head = NULL;
        return;
    }
    
    // Delete first node
    if(position == 1) {
        // Find the last node
        while(current->next != *head)
            current = current->next;
        
        temp = *head;
        *head = (*head)->next;
        current->next = *head;
        free(temp);
        return;
    }
    
    // Delete node at position > 1
    int k = 1;
    while(k < position - 1 && current->next != *head) {
        current = current->next;
        k++;
    }
    
    if(current->next == *head) {
        printf("Position %d out of range\n", position);
        return;
    }
    
    temp = current->next;
    current->next = temp->next;
    free(temp);
}

void SearchInCLL(CLLNode *head, int data) {
    if(!head) {
        printf("List is empty\n");
        return;
    }
    
    CLLNode *current = head;
    int position = 1;
    
    do {
        if(current->data == data) {
            printf("Element %d found at position %d\n", data, position);
            return;
        }
        current = current->next;
        position++;
    } while(current != head);
    
    printf("Element %d not found in the list\n", data);
}

void DestroyCircularList(CLLNode **head) {
    if(*head == NULL)
        return;
    
    CLLNode *current = *head, *temp;
    
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while(current != *head);
    
    *head = NULL;
}

int main(){
    CLLNode *head = NULL;
    
    // Insert nodes
    InsertAtEndInCLL(&head, 10);
    InsertAtEndInCLL(&head, 20);
    InsertAtEndInCLL(&head, 30);
    
    printf("After inserting at end:\n");
    CircularListPrint(head);
    printf("List length: %d\n\n", CircularListLength(head));
    

    InsertAtBeginInCLL(&head, 5);
    printf("After inserting 5 at beginning:\n");
    CircularListPrint(head);
    
    // Search for elements
    SearchInCLL(head, 20);
    SearchInCLL(head, 25);
    
 
    DeleteNodeInCLL(&head, 2);
    printf("\nAfter deleting node at position 2:\n");
    CircularListPrint(head);
    

    DestroyCircularList(&head);
    printf("\nAfter destroying the list:\n");
    if(head == NULL)
        printf("List is successfully destroyed\n");
    
    return 0;
}