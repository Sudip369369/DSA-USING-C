//program:- Merging Using Iterative Method.

#include <stdio.h>

void merge(int arr[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int temparr[100];
    
    while (i <= mid && j <= h) {  
        if (arr[i] < arr[j])
            temparr[k++] = arr[i++];
        else
            temparr[k++] = arr[j++];
    }
    while (i <= mid)
        temparr[k++] = arr[i++];

    while (j <= h)
        temparr[k++] = arr[j++];
    
    // Copy temp back to original array
    for (i = l; i <= h; i++)
        arr[i] = temparr[i];
}

void mergeSort(int arr[], int n) {
    int l, mid, h, p, i;

    for (p = 2; p <= n; p = p * 2) {
        for (i = 0; i + p - 1 < n; i = i + p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(arr, l, mid, h);
        }
    }

    // Final merge if n is not a power of 2
    if (p / 2 < n) {
        merge(arr, 0, (p / 2) - 1, n - 1);
    }
}

 


int main() {
    int arr1[6] = {10, 20, 5, 1, 30, 40};
    int n = 6;
    int i;
    
    mergeSort(arr1, n);
    
    printf("Array after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    
    return 0;
}
