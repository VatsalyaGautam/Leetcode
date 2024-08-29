#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long func(int mid, vector<int> piles)
    {
        long long n = piles.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += ceil((double)piles[i] / (double)mid);
        }
        return ans;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        long high = *max_element(piles.begin(), piles.end()), low = 1, mid, ans = 1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (func(mid, piles) > h)
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
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Test case 1: Minimum eating speed is " << solution.minEatingSpeed(piles1, h1) << endl;

    // Test case 2
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Test case 2: Minimum eating speed is " << solution.minEatingSpeed(piles2, h2) << endl;

    // Test case 3
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    cout << "Test case 3: Minimum eating speed is " << solution.minEatingSpeed(piles3, h3) << endl;

    // Test case 4
    vector<int> piles4 = {312884470};
    int h4 = 968709470;
    cout << "Test case 4: Minimum eating speed is " << solution.minEatingSpeed(piles4, h4) << endl;

    return 0;
}