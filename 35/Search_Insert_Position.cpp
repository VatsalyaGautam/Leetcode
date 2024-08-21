#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Insert position for target " << target1 << " in nums1: " << solution.searchInsert(nums1, target1) << endl; // Output: 2

    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Insert position for target " << target2 << " in nums2: " << solution.searchInsert(nums2, target2) << endl; // Output: 1

    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Insert position for target " << target3 << " in nums3: " << solution.searchInsert(nums3, target3) << endl; // Output: 4

    vector<int> nums4 = {1, 3, 5, 6};
    int target4 = 0;
    cout << "Insert position for target " << target4 << " in nums4: " << solution.searchInsert(nums4, target4) << endl; // Output: 0

    return 0;
}