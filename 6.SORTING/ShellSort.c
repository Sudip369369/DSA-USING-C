#include <stdio.h>

void shellSort(int arr[],int n){
	int i,j,v,gap;
	
for(gap = n/2;gap>=1;gap/=2){
	
	for(i=gap;i<n;i++){
		v = arr[i];
		j = i-gap;
		while(j>=0&&arr[j]>v){
			arr[j+gap] = arr[j];
			j = j-gap;
		}
		arr[j+gap] = v;
	}
}
}
	int main(){
    int array[10] = {1,5,10,8,2,19,45,56,11,12};
//    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    shellSort(array,10);
    int i;
    printf("Sorted Elements are: \n");
    for(i=0;i<10;i++){
        printf("%d \n",array[i]);
    }
    return 0;
}

