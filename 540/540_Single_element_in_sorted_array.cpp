#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        else if (nums[n - 2] != nums[n - 1])
            return nums[n - 1];
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
            else if ((mid % 2 == 0 && nums[mid + 1] == nums[mid]) ||
                     (mid % 2 == 1 && nums[mid - 1] == nums[mid]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Test case 1: Single non-duplicate element is " << solution.singleNonDuplicate(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Test case 2: Single non-duplicate element is " << solution.singleNonDuplicate(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 1, 2};
    cout << "Test case 3: Single non-duplicate element is " << solution.singleNonDuplicate(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {1, 2, 2};
    cout << "Test case 4: Single non-duplicate element is " << solution.singleNonDuplicate(nums4) << endl;

    // Test case 5
    vector<int> nums5 = {1};
    cout << "Test case 5: Single non-duplicate element is " << solution.singleNonDuplicate(nums5) << endl;

    return 0;
}