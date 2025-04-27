#include <stdio.h>


int unorderedSearch(int array[], int n, int key) {
	int i;
    for (i = 0; i < n; i++) {
        if (array[i] == key)
            return i; 
    }
    return -1; 
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int key;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = unorderedSearch(array, 5, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

