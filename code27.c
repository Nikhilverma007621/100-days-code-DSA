#include <stdio.h>

int main() {
    int n;
    
    // Input size of matrix
    printf("Enter the size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    int isIdentity = 1;

    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity condition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
    }

    // Output result
    if(isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
