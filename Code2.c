#include <stdio.h>

int main() {
    int n, target;
    int nums[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    return 0;
}
