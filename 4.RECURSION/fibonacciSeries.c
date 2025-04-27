//using tail recursive function

#include <stdio.h>
int fibo(int n,int a,int b){
	if(n<=0) return a;
	else if(n==1) return b;
	else return fibo(n-1,b,a+b);
}

int main(){
    int i, n;
    printf("Enter the valud of n to generate fibonacci Series up to n: ");
    scanf("%d",&n);
    int a = 0;
    int b = 1;
   printf("Fibonacci series up to n is: \n");
   for(i=0;i<n;i++){
   	printf("%d ",fibo(i,a,b));
   }
 

	return 0;
}
