#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int start = 0;
    int end = numsSize - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int nums[] = {1, 3, 5, 7, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;

    int result = search(nums, numsSize, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}