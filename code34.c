#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int currentSum = nums[0];
    int maxSum = nums[0];

    for(int i = 1; i < n; i++) {

        if(currentSum + nums[i] > nums[i]) {
            currentSum = currentSum + nums[i];
        } else {
            currentSum = nums[i];
        }

        if(currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    printf("Maximum Subarray Sum: %d\n", maxSum);

    return 0;
}
