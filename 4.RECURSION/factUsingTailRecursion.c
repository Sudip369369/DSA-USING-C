//Factorial using Recursion
#include <stdio.h>

int Factorial(int n,int accumulator){
    if(n==0)
    return accumulator; 
    else 
    return Factorial(n-1,n*accumulator);
}

int main(){
    int n;
    printf("Enter any positive value to calculate Factorial: ");
    scanf("%d",&n);
     // Calculating the factorial with the Explicit accumulator value of 1
    printf("The Factorial of the %d is %d",n,Factorial(n,1));
    return 0;
}