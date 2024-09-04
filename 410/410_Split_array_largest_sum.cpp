#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int solve(vector<int> nums, int n, int limit)
    {
        int sum = 0;
        int parts = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum + nums[i] <= limit)
            {
                sum += nums[i];
            }
            else
            {
                parts++;
                sum = nums[i];
            }
        }
        return parts;
    }

    int splitArray(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int parts = solve(nums, n, mid);
            if (parts > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;
    cout << "Test case 1: Minimum largest sum after splitting = " << solution.splitArray(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    cout << "Test case 2: Minimum largest sum after splitting = " << solution.splitArray(nums2, k2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 4, 4};
    int k3 = 3;
    cout << "Test case 3: Minimum largest sum after splitting = " << solution.splitArray(nums3, k3) << endl;

    // Test case 4
    vector<int> nums4 = {2, 3, 1, 2, 4, 3};
    int k4 = 4;
    cout << "Test case 4: Minimum largest sum after splitting = " << solution.splitArray(nums4, k4) << endl;

    return 0;
}