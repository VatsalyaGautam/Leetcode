#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        else if (nums[0] > nums[1])
        {
            return 0;
        }
        else if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] > nums[i + 2] && nums[i + 1] > nums[i])
            {
                return i + 1;
            }
        }
        return -1;
    }
};

// Driver function to test the Solution class
int main()
{
    Solution solution;

    vector<vector<int>> testCases = {
        {1, 2, 3, 1},
        {1, 2, 1, 3, 5, 6, 4},
        {1},
        {3, 2, 1},
        {1, 3, 2},
        {2, 1}};

    for (const auto &nums : testCases)
    {
        int peakIndex = solution.findPeakElement(const_cast<vector<int> &>(nums));
        cout << "Peak element index for [";
        for (size_t i = 0; i < nums.size(); i++)
        {
            cout << nums[i];
            if (i != nums.size() - 1)
                cout << ", ";
        }
        cout << "] is: " << peakIndex << endl;
    }

    return 0;
}