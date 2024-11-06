#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int s = nums.size();
        int n = pow(2, s);
        for (int i = 0; i < n; i++)
        {
            int num = i;
            int index = 0;
            vector<int> vec;
            while (num != 0)
            {
                if (num & 1)
                {
                    if (index < s)
                        vec.push_back(nums[index]);
                }
                index++;
                num = num >> 1;
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    int n;

    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> result = solution.subsets(nums);
    cout << "The subsets are:" << endl;
    for (const auto &subset : result)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}