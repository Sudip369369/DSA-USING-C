//program:- Merging Using Recursive Method.
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

void mergeSort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

int main() {
    int arr1[6] = {10, 20, 5, 1, 30, 40};
    int l = 0;
    int h = 5;
    int i;
    
    mergeSort(arr1, l, h);
    
    printf("Array after sorting:\n");
    for (i = 0; i <= h; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    
    return 0;
}
