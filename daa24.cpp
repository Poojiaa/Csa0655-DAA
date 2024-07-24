#include <stdio.h>

// Recursive function to reverse a number
int reverseNumber(int num) {
    // Base case: If num is a single digit
    if (num < 10) {
        return num;
    }
    
    // Recursive case
    int digits = 0;
    int n = num;
    while (n != 0) {
        digits++;
        n /= 10;
    }

    // Remove the last digit from the number
    int lastDigit = num % 10;
    // Recursive call with the remaining number
    int remainingNumber = num / 10;

    // Combine the reversed remaining number with the last digit
    return lastDigit * pow(10, digits - 1) + reverseNumber(remainingNumber);
}

// Utility function to calculate power of 10
int pow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int number = 12345;
    printf("Original number: %d\n", number);
    printf("Reversed number: %d\n", reverseNumber(number));
    return 0;
}

