#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int divide(vector<int> vec, int n, int div)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)vec[i] / (double)div);
        }
        return sum;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid, n = nums.size(), ans = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (divide(nums, n, mid) > threshold)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << "Test case 1: Smallest divisor is " << solution.smallestDivisor(nums1, threshold1) << endl;

    // Test case 2
    vector<int> nums2 = {2, 3, 5, 7, 11};
    int threshold2 = 11;
    cout << "Test case 2: Smallest divisor is " << solution.smallestDivisor(nums2, threshold2) << endl;

    // Test case 3
    vector<int> nums3 = {19};
    int threshold3 = 5;
    cout << "Test case 3: Smallest divisor is " << solution.smallestDivisor(nums3, threshold3) << endl;

    // Test case 4
    vector<int> nums4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int threshold4 = 10;
    cout << "Test case 4: Smallest divisor is " << solution.smallestDivisor(nums4, threshold4) << endl;

    return 0;
}