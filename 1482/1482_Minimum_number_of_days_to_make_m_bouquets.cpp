#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool solve(vector<int> vec, int m, int k, int n, int bloomlimit)
    {
        int count = 0, bouquets = 0;
        for (int i = 0; i < n; i++)
        {
            if (vec[i] <= bloomlimit)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (count == k)
            {
                bouquets++;
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int mid, ans = -1;
        int n = bloomDay.size();
        long long y = m, z = k;
        if ((y * z) > n)
            return -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (solve(bloomDay, m, k, n, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;
    cout << "Test case 1: Minimum number of days = " << solution.minDays(bloomDay1, m1, k1) << endl;

    // Test case 2
    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;
    cout << "Test case 2: Minimum number of days = " << solution.minDays(bloomDay2, m2, k2) << endl;

    // Test case 3
    vector<int> bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
    int m3 = 2, k3 = 3;
    cout << "Test case 3: Minimum number of days = " << solution.minDays(bloomDay3, m3, k3) << endl;

    // Test case 4
    vector<int> bloomDay4 = {1000000000, 1000000000};
    int m4 = 1, k4 = 1;
    cout << "Test case 4: Minimum number of days = " << solution.minDays(bloomDay4, m4, k4) << endl;

    return 0;
}