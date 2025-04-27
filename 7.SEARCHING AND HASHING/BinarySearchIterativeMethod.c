#include <stdio.h>

// Iterative Binary Search Function
int binarySearchIterative(int A[], int n, int data) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == data)
            return mid;
        else if (A[mid] < data)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 
}

int main() {
    int array[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int key;


    printf("Enter the key element: "); 
    scanf("%d", &key);

    int result = binarySearchIterative(array, 10, key);

 
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found.\n"); 

    return 0;
}

