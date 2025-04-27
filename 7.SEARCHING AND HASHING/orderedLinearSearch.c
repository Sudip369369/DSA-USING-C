#include <stdio.h>

int orderedLinearSearch(int array[],int n,int data){
	int i;
	for (i=0;i<n;i++){
		if(array[i]==data)
		return i;
		else if(array[i]>data)
		return -1;
	}
	return -1;
}

int main(){
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int key;
	printf("Enter the key: ");
	scanf("%d",&key);
	
	int result = orderedLinearSearch(array,10,key);
	
	if(result!=-1){
		printf("Element found at index %d ",result);
	}
else{
		printf("Element not found");
	}
	return 0;
}
