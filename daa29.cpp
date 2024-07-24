#include <stdio.h>

// Function to print Pascal's Triangle
void printPascalTriangle(int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        // Print leading spaces for formatting
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print the values in the current row
        for (j = 0; j <= i; j++) {
            // Print the value of the binomial coefficient
            printf("%d ", binomialCoeff(i, j));
        }
        printf("\n");
    }
}

// Function to compute the binomial coefficient
int binomialCoeff(int n, int k) {
    int res = 1;

    // Handle k > n - k
    if (k > n - k) {
        k = n - k;
    }

    // Compute the binomial coefficient
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main() {
    int rows;

    // Input number of rows
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    // Print Pascal's Triangle
    printPascalTriangle(rows);

    return 0;
}

