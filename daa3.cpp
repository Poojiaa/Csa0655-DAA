#include <stdio.h>

// Function to find the GCD using recursive factorization
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main() {
    int num1, num2;
 // Asking the user to input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
 // Finding and printing the GCD of the two numbers
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
  return 0;
}
