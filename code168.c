#include <stdio.h>

// Function to find peak element index (O(log n))
int findPeakElement(int* nums, int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            right = mid;        // peak is in left half
        } else {
            left = mid + 1;     // peak is in right half
        }
    }

    return left;
}

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int nums[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int peakIndex = findPeakElement(nums, n);

    // Output result
    printf("%d\n", peakIndex);

    return 0;
}