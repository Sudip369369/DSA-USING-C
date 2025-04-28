#include <stdio.h>

void selectionSort(int arr[],int n){
	int i,j,min,temp;
	
	for(i=0;i<n-1;i++)
	{ 
	min = i;
	for(j = i+1;j<n;j++){
		if(arr[j]<arr[min])
		min = j;	
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main(){

   int array[10] = {1,5,10,8,2,19,45,56,11,12};
// int array[10] = {1,2,3,4,5,6,7,8,9,10};
    selectionSort(array,10);
    int i;
    printf("Sorted Elements are: \n");
    for(i=0;i<10;i++){
        printf("%d \n",array[i]);
    }
    return 0;
}

