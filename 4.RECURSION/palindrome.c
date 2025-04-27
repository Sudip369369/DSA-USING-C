#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int start, int end) {
    if (start >= end)
        return 1; // Base case: finished checking, it's a palindrome
    
    if (str[start] != str[end])
        return 0; 
    
  
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    if (isPalindrome(str, 0, len - 1))
        printf("The string is a Palindrome!\n");
    else
        printf("The string is NOT a Palindrome.\n");

    return 0;
}
