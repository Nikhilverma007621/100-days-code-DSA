#include <stdio.h>

// Function to search target in rotated sorted array
int search(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        if (arr[low] <= arr[mid]) {
            // Target lies in left half
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            // Target lies in right half
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;  // Not found
}

int main() {
    int n, target;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target
    scanf("%d", &target);

    int result = search(arr, n, target);

    printf("%d\n", result);

    return 0;
}