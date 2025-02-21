#include <stdio.h>

// Function to compute the Binomial Coefficient using dynamic programming
int binomialCoeff(int n, int k) {
    int C[n+1][k+1];
    
    // Initialize the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    return C[n][k];
}

int main() {
    int n = 5, k = 2;
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));
    return 0;
}

