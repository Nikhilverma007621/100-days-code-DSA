#include <stdio.h>

int integerSquareRoot(int n) {
    int left = 0, right = n;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // To avoid overflow, use mid <= n / mid instead of mid * mid <= n
        if (mid <= n / mid) {
            ans = mid;        // possible answer
            left = mid + 1;   // search in right half
        } else {
            right = mid - 1;  // search in left half
        }
    }

    return ans;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = integerSquareRoot(n);
    printf("Integer square root: %d\n", result);

    return 0;
}
