#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 3 != 0)
                ans++;
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

    int result = solution.minimumOperations(nums);

    cout << "Minimum operations: " << result << endl;

    return 0;
}