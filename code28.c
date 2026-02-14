#include <stdio.h>

int main() {
    int n;

    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Step 1: Transpose the matrix
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }

    printf("\nRotated Matrix (90 degrees clockwise):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
