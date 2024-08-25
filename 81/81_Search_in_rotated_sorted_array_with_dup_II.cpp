#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size(), start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] == nums[start] && nums[mid] == nums[end])
            {
                start++;
                end--;
                continue;
            }
            else if (nums[mid] > nums[end])
            {
                if (target < nums[mid] && target >= nums[start])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    cout << "Test case 1: " << (solution.search(nums1, target1) ? "Found" : "Not Found") << endl;

    // Test case 2
    vector<int> nums2 = {1, 3, 5, 7, 9, 11, 13};
    int target2 = 7;
    cout << "Test case 2: " << (solution.search(nums2, target2) ? "Found" : "Not Found") << endl;

    // Test case 3
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int target3 = 2;
    cout << "Test case 3: " << (solution.search(nums3, target3) ? "Found" : "Not Found") << endl;

    // Test case 4
    vector<int> nums4 = {3, 1, 1, 1, 1};
    int target4 = 3;
    cout << "Test case 4: " << (solution.search(nums4, target4) ? "Found" : "Not Found") << endl;

    // Test case 5
    vector<int> nums5 = {1, 2, 3, 4, 5};
    int target5 = 6;
    cout << "Test case 5: " << (solution.search(nums5, target5) ? "Found" : "Not Found") << endl;

    return 0;
}