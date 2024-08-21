#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool check(const vector<int> &nums) const
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                cnt++;
            }
        }
        if (nums[n - 1] > nums[0])
        {
            cnt++;
        }
        return cnt <= 1;
    }
};

int main()
{
    Solution sol;

    // Test cases
    vector<vector<int>> test_cases = {
        {1, 2, 3, 4, 5}, // True: Already sorted
        {3, 4, 5, 1, 2}, // True: Sorted and rotated
        {2, 1, 3, 4, 5}, // False: Not sorted and rotated
        {1, 3, 5, 7, 2}, // False: More than one rotation point
        {5, 1, 2, 3, 4}  // True: Sorted and rotated
    };

    for (const auto &test_case : test_cases)
    {
        bool result = sol.check(test_case);
        cout << "check({";
        for (size_t i = 0; i < test_case.size(); ++i)
        {
            cout << test_case[i];
            if (i < test_case.size() - 1)
                cout << ", ";
        }
        cout << "}) = " << (result ? "True" : "False") << endl;
    }

    return 0;
}