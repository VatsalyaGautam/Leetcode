#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        for (int i = (2 * n) - 1; i >= 0; i--) {
            int index = i % n;
            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            if (i < n) {
                ans.emplace_back(st.empty() ? -1 : st.top());
            }
            st.push(nums[index]);
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