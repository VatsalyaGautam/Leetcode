#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth = INT_MIN;
        for (int i = 0; i < accounts.size(); i++) {
            int sum = 0;
            for (int j = 0; j < accounts[0].size(); j++) {
                sum += accounts[i][j];
            }
            wealth = max(wealth, sum);
        }
        return wealth;
    }
};

// Driver program
int main() {
    Solution solution;
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}, {4, 5, 6}};
    cout << solution.maximumWealth(accounts) << endl;
    return 0;
}