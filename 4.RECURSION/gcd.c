#include<stdio.h>

int gcd(int a,int b){
	if(b==0)
	return a;
	
	else gcd(b,a%b);
}


int main(){
	int a,b;
	printf("Enter the two number: ");
	scanf("%d%d",&a,&b);
	
	printf("The GCD of %d and %d is: %d",a,b,gcd(a,b));
	
	return 0;
}
