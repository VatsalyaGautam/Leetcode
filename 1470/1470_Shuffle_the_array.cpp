#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int mid = n;
        for (int i = 0; i < n; i++) {
            ans.emplace_back(nums[i]);
            ans.emplace_back(nums[mid]);
            mid++;
        }
        return ans;
    }
};

// Driver Program
int main() {
    Solution sol;
    int n;
    cin >> n; 
    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> nums[i]; 
    }
    vector<int> result = sol.shuffle(nums, n);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}