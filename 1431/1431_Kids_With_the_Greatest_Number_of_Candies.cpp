#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxCandies = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); i++) {
            ans.push_back(candies[i] + extraCandies >= maxCandies);
        }
        return ans;
    }
};

// Driver program
int main() {
    Solution solution;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);
    for (bool canHaveMost : result) {
        cout << (canHaveMost ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}