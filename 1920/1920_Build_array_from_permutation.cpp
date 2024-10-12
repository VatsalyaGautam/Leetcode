#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = solution.buildArray(nums);

    cout << "The resulting array is: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}