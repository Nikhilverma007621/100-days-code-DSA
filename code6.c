#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[n - 1];
    long long actualSum = 0;

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        actualSum += arr[i];
    }

    long long expectedSum = (long long)n * (n + 1) / 2;

    int missingNumber = expectedSum - actualSum;

    printf("%d\n", missingNumber);

    return 0;
}
