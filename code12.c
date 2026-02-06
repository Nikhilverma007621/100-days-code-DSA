#include <stdio.h>

void moveZeroes(int nums[], int n)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    while (k < n)
    {
        nums[k] = 0;
        k++;
    }
}

int main()
{
    int nums[] = {0, 1, 0, 3, 12};
    int n = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
