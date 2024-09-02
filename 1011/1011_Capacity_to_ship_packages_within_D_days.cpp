#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool calculate(vector<int> weights, int days, int capacity, int n)
    {
        int actualDays = 0, counter = 0;
        for (int i = 0; i < n; i++)
        {
            counter += weights[i];
            if (counter > capacity)
            {
                actualDays++;
                counter = weights[i];
            }
            else if (counter == capacity)
            {
                actualDays++;
                counter = 0;
            }
            if (i == n - 1 && counter > 0)
            {
                actualDays++;
            }
        }
        return actualDays <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int mid, ans = -1;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (!calculate(weights, days, mid, n))
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
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    cout << "Test case 1: Minimum ship capacity = " << solution.shipWithinDays(weights1, days1) << endl;

    // Test case 2
    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    cout << "Test case 2: Minimum ship capacity = " << solution.shipWithinDays(weights2, days2) << endl;

    // Test case 3
    vector<int> weights3 = {1, 2, 3, 1, 1};
    int days3 = 4;
    cout << "Test case 3: Minimum ship capacity = " << solution.shipWithinDays(weights3, days3) << endl;

    // Test case 4
    vector<int> weights4 = {10, 50, 100, 100, 50, 10};
    int days4 = 5;
    cout << "Test case 4: Minimum ship capacity = " << solution.shipWithinDays(weights4, days4) << endl;

    return 0;
}