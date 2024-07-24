#include <stdio.h>
#include <math.h>
// Function to calculate the number of digits in a number
int countDigits(int n) {
    if (n == 0)
        return 0;
    return 1 + countDigits(n / 10);
}
// Recursive function to calculate the sum of digits raised to the power of the number of digits
int sumOfPowers(int n, int power) {
    if (n == 0)
        return 0;
    return pow(n % 10, power) + sumOfPowers(n / 10, power);
}
// Function to check if a number is an Armstrong number
int isArmstrong(int n) {
    int numDigits = countDigits(n);
    return (n == sumOfPowers(n, numDigits));
}

int main() {
    int num;
 // Asking the user to input a number
    printf("Enter a number: ");
    scanf("%d", &num);
  // Checking if the number is an Armstrong number
    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
 return 0;
}
