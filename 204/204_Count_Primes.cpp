#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<int> vec(n, 1);
        vec[0] = vec[1] = 0;

        for (int i = 2; i * i < n; i++)
        {
            if (vec[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    vec[j] = 0;
                }
            }
        }
        return count(vec.begin(), vec.end(), 1);
    }
};

// Driver Program
int main()
{
    Solution sol;
    int n;
    cin >> n; // Example input
    cout << sol.countPrimes(n) << endl;
    return 0;
}