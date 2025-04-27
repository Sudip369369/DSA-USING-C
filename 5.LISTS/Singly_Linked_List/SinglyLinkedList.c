#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
    int data;
    struct listNode* next;
} listNode;

void sllInsert(listNode** head, int data, int pos)
{
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    if(!newNode){
        printf("Memory Allocation Failed.\n");
        return;
    }
    
    newNode->data = data;
    
    // Case 1: Insert at beginning
    if(pos == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    // Case 2: Insert at middle or end
    listNode *q,*p = *head;
    int k = 1;
    while(k < pos-1 && p != NULL)
    {
        k++;
        p = p->next;
    }
    
    // Check if position is valid
    if(p == NULL){
        printf("Position %d is out of range.\n", pos);
        free(newNode);
        return;
    }
    
    // Insert node
    newNode->next = p->next;
    p->next = newNode;
}

void sllDelete(listNode** head, int pos)
{
    if(!*head){
        printf("List is empty\n");
        return;
    }
    
    listNode *p, *q;
    p = *head;
    
    // Case 1: Delete first node
    if(pos == 1){
        *head = (*head)->next;
        free(p);
        return;
    }
    
    // Case 2: Delete middle or end node
    int k = 1;
    while(k < pos && p != NULL)
    {
        k++;
        q = p;
        p = p->next;
    }
    
    // Check if position is valid
    if(p == NULL){
        printf("Position %d does not exist\n", pos);
        return;
    }
    
    // Delete node
    q->next = p->next;
    free(p);
}

int sizeofList(listNode* head){
    listNode* temp = head;
    int c = 0;
    while(temp){
        c++;
        temp = temp->next;
    }
    return c;
}

void printList(listNode* head) {
    listNode* temp = head;
    printf("Singly Linked List: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    listNode* head = NULL;

    sllInsert(&head, 10, 1);  
    sllInsert(&head, 20, 2);  
    sllInsert(&head, 30, 3); 
	sllInsert(&head,40,4);
    printList(head);
    
    sllDelete(&head, 2);     
    printList(head);
    printf("Size of list: %d\n", sizeofList(head));
    
    return 0;
}