//Factorial using Recursion
#include <stdio.h>

int Factorial(int n){
    if(n==0)
    return 1; 
    else 
    return n*Factorial(n-1);
}

int main(){
    int n;
    printf("Enter any positive value to calculate Factorial: ");
    scanf("%d",&n);
    printf("The Factorial of the %d is %d",n,Factorial(n));
    return 0;
}