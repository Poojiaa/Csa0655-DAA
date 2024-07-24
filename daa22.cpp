#include <stdio.h>
#include <limits.h>

// Function to compute the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to solve the OBST problem using dynamic programming
int obst(int keys[], int freq[], int n) {
    int cost[n][n];

    // Initialize cost for single keys
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Fill the cost table
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;
            int sum_freq = sum(freq, i, j);

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + 
                        ((r < j) ? cost[r + 1][j] : 0) + 
                        sum_freq;

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n-1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    int min_cost = obst(keys, freq, n);
    printf("Minimum cost of OBST: %d\n", min_cost);

    return 0;
}

