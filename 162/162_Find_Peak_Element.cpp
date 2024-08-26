#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
            {
                return mid;
            }
            else if (nums[mid] < nums[mid + 1])
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
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test case 1: Peak element index is " << solution.findPeakElement(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Test case 2: Peak element index is " << solution.findPeakElement(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 2};
    cout << "Test case 3: Peak element index is " << solution.findPeakElement(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {3, 4, 3, 2, 1};
    cout << "Test case 4: Peak element index is " << solution.findPeakElement(nums4) << endl;

    // Test case 5
    vector<int> nums5 = {5, 6, 7, 8, 9};
    cout << "Test case 5: Peak element index is " << solution.findPeakElement(nums5) << endl;

    return 0;
}