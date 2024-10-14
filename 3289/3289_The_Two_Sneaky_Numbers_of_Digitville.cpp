#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
            if (mpp[nums[i]] == 2)
            {
                ans.push_back(nums[i]);
                if (ans.size() == 2)
                    return ans;
            }
        }
        return ans;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;

    vector<int> nums = {4, 5, 6, 4, 5, 7, 8};

    cout << "Original array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> sneakyNumbers = solution.getSneakyNumbers(nums);

    cout << "Sneaky numbers (first two duplicates): ";
    for (int num : sneakyNumbers)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}