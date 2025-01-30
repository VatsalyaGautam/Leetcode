#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i])
                st.pop();

            st.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i])
                st.pop();
            if (st.empty()) {
                ans.emplace_back(-1);
            } else {
                ans.emplace_back(st.top());
            }

            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Driver program
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}