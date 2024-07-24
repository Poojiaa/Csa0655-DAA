#include <stdio.h>

// Function to check if a number is perfect
int isPerfectNumber(int n) {
    int sum = 0;
    
    // Find the sum of proper divisors
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of divisors is equal to the number
    return (sum == n);
}

int main() {
    int number;
    
    // Input number
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Check if the number is perfect and output the result
    if (isPerfectNumber(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }
    
    return 0;
}

