#include <stdio.h>

int main() {
    int n = 4;  // Number of segments

    // Generate the pattern
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d\n", j);
        }
    }

    printf("\n");
    return 0;
}

