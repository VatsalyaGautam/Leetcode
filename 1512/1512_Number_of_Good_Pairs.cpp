#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int count = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mpp.find(nums[i]) == mpp.end())
            {
                mpp[nums[i]]++;
            }
            else
            {
                count += mpp[nums[i]];
                mpp[nums[i]]++;
            }
        }
        return count;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = solution.numIdenticalPairs(nums);
    cout << "Number of good pairs: " << result << endl;

    return 0;
}