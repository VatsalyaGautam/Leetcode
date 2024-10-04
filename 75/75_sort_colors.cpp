#include <iostream>
#include <vector>

class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        int zero = 0;
        int one = 0;
        int two = 0;

        // Count occurrences of 0, 1, and 2
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
            else
                two++;
        }

        // Update the array based on counts
        for (int i = 0; i < nums.size(); i++)
        {
            if (zero > 0)
            {
                nums[i] = 0;
                zero--;
                continue;
            }
            else if (one > 0)
            {
                nums[i] = 1;
                one--;
                continue;
            }
            else
            {
                nums[i] = 2;
                two--;
                if (two == 0)
                    break;
            }
        }
    }
};

// Driver program
int main()
{
    std::vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution solution;
    solution.sortColors(nums);

    // Output the sorted array
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}