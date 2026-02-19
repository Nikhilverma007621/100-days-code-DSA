#include <stdio.h>
#include <limits.h>

int maxSubarraySumCircular(int arr[], int n) {
    int totalSum = 0;
    int currMax = 0, maxSum = arr[0];
    int currMin = 0, minSum = arr[0];

    for(int i = 0; i < n; i++) {
        totalSum += arr[i];

        if(currMax > 0)
            currMax += arr[i];
        else
            currMax = arr[i];

        if(currMax > maxSum)
            maxSum = currMax;

        if(currMin < 0)
            currMin += arr[i];
        else
            currMin = arr[i];

        if(currMin < minSum)
            minSum = currMin;
    }

    if(maxSum < 0)
        return maxSum;

    if(totalSum - minSum > maxSum)
        return totalSum - minSum;
    else
        return maxSum;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSubarraySumCircular(arr, n);
    printf("%d\n", result);

    return 0;
}
