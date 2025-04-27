#include <stdio.h>

void insertionSort(int arr[], int n) {
	int i;
    for ( i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
	    int array[10] = {1,5,10,8,2,19,45,56,11,12};
//    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    insertionSort(array,10);
    int i;
    printf("Sorted Elements are: \n");
    for(i=0;i<10;i++){
        printf("%d \n",array[i]);
    }
    return 0;
}


