#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);
        int n = nums.size();
        if (n == 0 || target < nums[0] || target > nums[n - 1] ||
            *lower_bound(nums.begin(), nums.end(), target) != target ||
            nums[upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1] != target)
        {
            return ans;
        }
        ans[0] = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        ans[1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return ans;
    }
};

// Driver program to test the Solution class
int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    cout << "Test case 1: ";
    cout << "Target: " << target1 << " -> Indices: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Test case 2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = solution.searchRange(nums2, target2);
    cout << "Test case 2: ";
    cout << "Target: " << target2 << " -> Indices: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Test case 3
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = solution.searchRange(nums3, target3);
    cout << "Test case 3: ";
    cout << "Target: " << target3 << " -> Indices: [" << result3[0] << ", " << result3[1] << "]" << endl;

    // Test case 4
    vector<int> nums4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target4 = 7;
    vector<int> result4 = solution.searchRange(nums4, target4);
    cout << "Test case 4: ";
    cout << "Target: " << target4 << " -> Indices: [" << result4[0] << ", " << result4[1] << "]" << endl;

    return 0;
}