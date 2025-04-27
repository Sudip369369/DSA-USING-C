//Program: Merging two sorted array. 
#include <stdio.h>

void merge(int arr1[], int arr2[], int m, int n, int arr3[]) {
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else 
            arr3[k++] = arr2[j++];
    }
    
//    for remaining element of the array if array has unequal size. 
 for(;i<m;i++)
 	arr3[k++] = arr1[i++];
 
 for(;j<n;j++)
   arr3[k++] = arr2[j++];

/* Alternative method.......!
    while (i < m)
        arr3[k++] = arr1[i++];
    
    while (j < n)
        arr3[k++] = arr2[j++];
    
*/
}

int main() {
    int arr1[5] = {2, 4, 6, 8, 10};
    int arr2[6] = {1, 3, 5, 7, 9, 11};
    int m = 5, n = 6;
    int arr3[m + n];
    int i;
    
    merge(arr1, arr2, m, n, arr3);
    printf("Sorted Array is:\n");
    for (i = 0; i < m + n; i++)
        printf("%d ", arr3[i]);
    printf("\n");
   
    return 0;
}
