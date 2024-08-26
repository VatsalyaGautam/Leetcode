#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1, mid, min = 5001;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] < min)
            {
                min = nums[mid];
            }
            if (nums[high] > nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                if (nums[low] < min)
                {
                    min = nums[low];
                }
                low = mid + 1;
            }
        }
        return min;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Test case 1: Min element is " << solution.findMin(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test case 2: Min element is " << solution.findMin(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Test case 3: Min element is " << solution.findMin(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {2, 2, 2, 0, 1};
    cout << "Test case 4: Min element is " << solution.findMin(nums4) << endl;

    // Test case 5
    vector<int> nums5 = {1};
    cout << "Test case 5: Min element is " << solution.findMin(nums5) << endl;

    return 0;
}