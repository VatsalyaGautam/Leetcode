#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int n = s.size();
        unordered_map<char, int> mpp;
        int i = 0;
        int ans = 0;

        for (char ch : s)
        {
            mpp[ch] = i;
            i++;
        }

        i = 0;
        for (char ch : t)
        {
            ans += abs(i - mpp[ch]);
            i++;
        }

        return ans;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    string s, t;

    cout << "Enter the first string (permutation of letters): ";
    cin >> s;

    cout << "Enter the second string (permutation of letters): ";
    cin >> t;

    if (s.size() != t.size())
    {
        cout << "The strings must be of the same length." << endl;
        return 1;
    }

    int result = solution.findPermutationDifference(s, t);
    cout << "Permutation difference: " << result << endl;

    return 0;
}