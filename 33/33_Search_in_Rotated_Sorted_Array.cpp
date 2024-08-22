#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int binary_search(vector<int> &nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + high;
            mid /= 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int high = n - 1, low = 0, mid;
        while (low <= high)
        {
            mid = low + high;
            mid /= 2;
            if (nums[mid] == target)
                return mid;
            if (nums[low] > nums[mid])
            {
                if (nums[mid] < target && nums[high] >= target)
                {
                    return binary_search(nums, mid + 1, high, target);
                }
                else
                {
                    high = mid - 1;
                }
            }
            else if (nums[high] < nums[mid])
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    return binary_search(nums, low, mid - 1, target);
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                return binary_search(nums, low, high, target);
            }
        }
        return -1;
    }
};

// Driver function to test the Solution class
int main()
{
    Solution solution;

    vector<pair<vector<int>, int>> testCases = {
        {{4, 5, 6, 7, 0, 1, 2}, 0},
        {{4, 5, 6, 7, 0, 1, 2}, 3},
        {{1}, 0},
        {{1}, 1},
        {{1, 3, 5}, 5},
        {{5, 1, 3}, 3}};

    for (const auto &testCase : testCases)
    {
        const auto &nums = testCase.first;
        int target = testCase.second;
        int index = solution.search(const_cast<vector<int> &>(nums), target);

        cout << "Searching for " << target << " in [";
        for (size_t i = 0; i < nums.size(); i++)
        {
            cout << nums[i];
            if (i != nums.size() - 1)
                cout << ", ";
        }
        cout << "] gives index: " << index << endl;
    }

    return 0;
}