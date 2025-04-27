#include <stdio.h>
/*// Bubble sort Algorithm
void bubbleSort(int arr[], int n) {
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
*/

//Making Bubble Sort Adaptive
void bubbleSort(int arr[], int n) {
    int i, j, swapped;
    for (i = 0; i < n-1; i++) {
        swapped = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; // No swaps = already sorted
    }
}

int main(){
//    int array[10] = {1,5,10,8,2,19,45,56,11,12};
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    bubbleSort(array,10);
    int i;
    printf("Sorted Elements are: \n");
    for(i=0;i<10;i++){
        printf("%d \n",array[i]);
    }
    return 0;
}
