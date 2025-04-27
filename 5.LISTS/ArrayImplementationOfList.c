#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int last_index;
} ArrayList;

// Initialize the list
void init(ArrayList *list) {
    list->last_index = -1;
}

// Insert element x at position pos
void insert(ArrayList *list, int pos, int x) {
    if (list->last_index == MAX - 1) {
        printf("Overflow: List is full!\n");
        return;
    }

    if (pos < 0 || pos > list->last_index + 1) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right
    int i;
    for (i = list->last_index; i >= pos; i--) {
        list->data[i + 1] = list->data[i];
    }

    list->data[pos] = x;
    list->last_index++;
    printf("Inserted %d at position %d\n", x, pos);
}

// Delete element at position pos
void delete(ArrayList *list, int pos) {
    if (list->last_index == -1) {
        printf("Underflow: List is empty!\n");
        return;
    }

    if (pos < 0 || pos > list->last_index) {
        printf("Invalid position!\n");
        return;
    }

    int deleted = list->data[pos];

    int i;
    // Shift elements to the left
    for ( i = pos; i < list->last_index; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->last_index--;
    printf("Deleted %d from position %d\n", deleted, pos);
}

// Display all elements
void display(ArrayList *list) {
    if (list->last_index == -1) {
        printf("List is empty.\n");
        return;
    }
int i;
    printf("List elements: ");
    for ( i = 0; i <= list->last_index; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// Main function to test
int main() {
    ArrayList myList;
    init(&myList);

    insert(&myList, 0, 10);
    insert(&myList, 1, 20);
    insert(&myList, 2, 30);
    display(&myList);

    delete(&myList, 1);
    display(&myList);

    insert(&myList, 1, 25);
    display(&myList);

    return 0;
}

