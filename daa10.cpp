#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome using recursion
bool isPalindrome(char str[], int start, int end) {
    // Base case: if there is only one character or no characters left
    if (start >= end) {
        return true;
    }
    // Check if the characters at the current positions are the same
    if (str[start] != str[end]) {
        return false;
    }
    // Recursive case: move to the next pair of characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);  // Using gets() for simplicity, though it's unsafe. Consider using fgets() in real applications.

    int length = strlen(str);
    if (isPalindrome(str, 0, length - 1)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
