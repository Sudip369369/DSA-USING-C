#include <stdio.h>

// Recursive Binary Search Function
int binarySearchRecursion(int A[], int low, int high, int data) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (A[mid] == data)
        return mid;
    else if (A[mid] > data)
        return binarySearchRecursion(A, low, mid - 1, data);
    else
        return binarySearchRecursion(A, mid + 1, high, data);
}

int main() {
    int array[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int key;

    printf("Enter the key element: ");
    scanf("%d", &key);

    int result = binarySearchRecursion(array, 0, 9, key); 

    if (result != -1)
        printf("Element found at index %d\n", result); 
    else
        printf("Element not found.\n"); 

    return 0;
}

