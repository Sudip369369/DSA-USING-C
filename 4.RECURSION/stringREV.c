#include <stdio.h>
#include <string.h>
void stringReverse(char *str,int start,int end){
	
	if(start>=end)
	return;
 
	char temp;
	temp = str[start];
	str[start] = str[end];
	str[end] = temp;
	stringReverse(str,start+1,end-1);
	
}
int main(){
	char str[100];
	printf("Enter the string: ");
	scanf("%s",&str);
	int l = strlen(str);
	printf("Before Reverse: %s\n",str);
	stringReverse(str,0,l-1);	
	printf("After Reverse: %s",str);
	
	return 0;
}
