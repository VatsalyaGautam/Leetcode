#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nsi(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ansVec(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) 
                st.pop();
            ansVec[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ansVec;
    }

    vector<int> psi(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ansVec(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ansVec[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ansVec;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> prev = psi(arr);
        vector<int> next = nsi(arr);
        const int MOD = 1000000007;
        long long total = 0;
        for (int i = 0; i < arr.size(); i++) {
            total = (total + (((((i - prev[i]) % MOD) * (next[i] - i) % MOD) % MOD) * 1LL * arr[i]) % MOD) % MOD;
        }
        return total;
    }
};

// Driver program
int main() {
    vector<int> arr = {3, 1, 2, 4};
    Solution sol;
    cout << sol.sumSubarrayMins(arr) << endl;
    return 0;
}