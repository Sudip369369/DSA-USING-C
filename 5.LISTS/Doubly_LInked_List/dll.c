#include <stdio.h>
#include <stdlib.h>

struct DLLNode {
    int data;
    struct DLLNode *prev, *next;
};

// Insert a node at the specified position
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
    while (temp != NULL && k < position - 1) {
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

// Delete a node at the specified position
void DLLDelete(struct DLLNode **head, int position) {
    if (!*head) {
        printf("List is empty!\n");
        return;
    }

    struct DLLNode *temp = *head;

    // Delete the first node
    if (position == 1) {
        *head = temp->next;
        if (*head) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Move to the node to be deleted
    int k = 1;
    while (temp && k < position) {
        temp = temp->next;
        k++;
    }

    // Check if position is valid
    if (!temp) {
        printf("Invalid position! Position out of range.\n");
        return;
    }

    // Update links and delete the node
    if (temp->prev) {
        temp->prev->next = temp->next;
    }
    if (temp->next) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Get the size of the list
int DLLSize(struct DLLNode *head) {
    int count = 0;
    struct DLLNode *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search for a value in the list
int DLLSearch(struct DLLNode *head, int data) {
    struct DLLNode *temp = head;
    int position = 1;
    
    while (temp) {
        if (temp->data == data) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    
    return -1; // Not found
}

// Display the list from head to tail
void printList(struct DLLNode *head) {
    struct DLLNode *temp = head;
    printf("Doubly Linked List: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display the list from tail to head
void printReverse(struct DLLNode *head) {
    if (!head) {
        printf("Reverse Doubly Linked List: NULL\n");
        return;
    }
    
    // Go to the last node
    struct DLLNode *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    
    // Print in reverse
    printf("Reverse Doubly Linked List: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Free all nodes in the list
void destroyList(struct DLLNode **head) {
    struct DLLNode *current = *head;
    struct DLLNode *next;
    
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

int main() {
    struct DLLNode *head = NULL;

    // Insert operations
    DLLInsert(&head, 10, 1); 
    DLLInsert(&head, 20, 2);
    DLLInsert(&head, 30, 3);  
    DLLInsert(&head, 15, 2); 
    
    printf("After insertion:\n");
    printList(head);
    
    // Size of the list
    printf("Size of the list: %d\n", DLLSize(head));
    
    // Search operation
    int position = DLLSearch(head, 15);
    if (position != -1) {
        printf("Value 15 found at position %d\n", position);
    } else {
        printf("Value 15 not found in the list\n");
    }
    
    // Delete operation
    DLLDelete(&head, 2);
    printf("\nAfter deleting node at position 2:\n");
    printList(head);
    
    // Print reverse
    printReverse(head);
    
    // Clean up memory
    destroyList(&head);
    printf("\nAfter destroying the list:\n");
    printList(head);

    return 0;
}