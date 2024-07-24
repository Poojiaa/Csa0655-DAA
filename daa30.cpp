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

// Function to compute the minimum cost of an Optimal Binary Search Tree
int obst(int keys[], int freq[], int n) {
    int cost[n][n];
    int root[n][n];
    
    // Initialize the cost and root tables
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        root[i][i] = i;
    }
    
    // Fill the cost table
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            int sum_freq = sum(freq, i, j);
            
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + 
                        ((r < j) ? cost[r + 1][j] : 0) + 
                        sum_freq;
                
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }
    
    return cost[0][n-1];
}

int main() {
    int keys[] = {10, 12, 20};  // Keys
    int freq[] = {34, 8, 50};   // Frequencies of the keys
    int n = sizeof(keys) / sizeof(keys[0]);
    
    int min_cost = obst(keys, freq, n);
    printf("Minimum cost of OBST: %d\n", min_cost);
    
    return 0;
}

